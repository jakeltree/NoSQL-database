#include <task3_server.h>

using namespace std;
using json = nlohmann::json;

static unsigned long x = 123456789, y = 362436069, z = 521288629;


Literature::Literature() {
    const string file_name = "generate_data.json";
    ifstream f(baseFilePath + file_name);
    if (f.is_open()) {
        json generate_data = json::parse(f);
        f.close();
        for (auto &element : generate_data["Authors"])
            sample_authors.push_back(element);
        for (auto &element : generate_data["Names"])
            sample_names.push_back(element);
        for (auto &element : generate_data["Publishers"])
            sample_publishers.push_back(element);
    } else {
        cout << "Ошибка: нет файла " << file_name << endl;
    }
}
unsigned long Literature::xorshf96(void) {
    unsigned long t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;

     t = x;
     x = y;
     y = z;
     z = t ^ x ^ y;
    return z;
}
int Literature::RandomNumber(int max) {
    x++;
    return xorshf96() % max;
}

string Literature::GenerateId(string name) {
    string id = "Literature"
        + to_string(RandomNumber(999) + 100)
        + name.substr(0, 3);
    return id;
}

json Literature::GenerateEntry() {
    // Создадим случайные единичные данные
    json new_entry;
    int max_author_num = RandomNumber(sample_authors.size() - 2);
    new_entry["Author"] = json::array({
        sample_authors[max_author_num],
        sample_authors[max_author_num + 1],
        sample_authors[max_author_num + 2]
    });
    string name = sample_names[RandomNumber(sample_names.size())];
    new_entry["Name"] = name;
    new_entry["Year"] = RandomNumber(191) + 1830;
    new_entry["Publisher"] = sample_publishers[
            RandomNumber(sample_publishers.size())
        ];
    new_entry["Rating"] = RandomNumber(100) + 1;
    new_entry["Id"] = GenerateId(name);
    return new_entry;
}

int Literature::Input(string file_name) {
    ifstream f(baseFilePath + file_name);
    if (f.is_open()) {
        data = json::parse(f);
        f.close();
        return 1;
    } else {
        cout << "Ошибка: не получается прочитать файл!";
        f.close();
        return 0;
    }
}

int Literature::Print(json &data) {
    data = this->data;
    return 1;
}

// Добавляем данные по полю Name
int Literature::Add(string name) {
    regex formatCheck("[A-z0-9-.]{3,}$");
    if (!regex_search(name, formatCheck)) {
        cout <<
            "Error: ValidationError (некорректное имя)"
            << endl;
        return 0;
    }
    json new_entry = GenerateEntry();
    new_entry["Name"] = name;
    new_entry["Id"] = GenerateId(name);
    data.push_back(new_entry);
    return 1;
}

int Literature::Delete(string field) {
    for (json::iterator it = data.begin(); it != data.end(); ++it) {
        if ((*it)["Name"] == field) {
            data.erase(it);
            return 1;
        }
    }
    cout << "ERROR: попытка удаления несуществующего поля!" << endl;
    return 0;
}

int Literature::Generate(int entries) {
    data = {};
    while (entries--) {
        data.push_back(GenerateEntry());
    }
    return 1;
}

int Literature::Execute(string output_file) {
    const int max_rating = 101;
    const int cutoff = data.size() / 10;
    sort(data.begin(), data.end(),
        [](const json &a, const json &b){
            return a["Rating"] < b["Rating"];});

    json output_data;
    json::iterator it = data.begin();
    for (int i = 0; i < cutoff; i++) {
        output_data.push_back(*it);
        ++it;
    }

    it = data.end();
    for (int i = 0; i < cutoff; i++) {
        --it;
    }
    for (int i = 0; i < cutoff; i++) {
        output_data.push_back(*it);
        ++it;
    }

    ofstream outf(baseFilePath + output_file);
    outf << output_data.dump(4);
    outf.close();
    return 1;
}

int Literature::GetById(string id, json &data) {
    regex formatCheck("^(Literature)[0-9]{3}[A-z0-9]{3}$");
    if (!regex_search(id, formatCheck)) {
        cout <<
            "Error: ValidationError (формат id не соответствует параметрам)"
            << endl;
        return 0;
    }
    for (auto &element : this->data) {
        if (element["Id"] == id) {
            data = element;
            return 1;
        }
    }
    cout << "ERROR: Can't find the entry" << endl;
    return 0;
}

int Literature::ProcessCommand(json send, json& data) {
    const string command = send["Command"];
    data = {};
    vector<string> param;
    for (json::iterator it = send["Param"].begin();
         it != send["Param"].end();
         ++it) {
        string s = *it;
        param.push_back(s);
    }

    if (command == "Input") {
        if (!this->Input(baseFilePath + param[0]))
            return 0;
        return 1;
    } else if (command == "Print") {
        if (!this->Print(data))
            return 0;
        return 1;
    } else if (command == "Add") {
        if (!this->Add(param[0]))
            return 0;
        return 1;
    } else if (command == "Delete") {
        if (!this->Delete(param[0]))
            return 0;
        return 1;
    } else if (command == "Generate") {
        if (!this->Generate(stoi(param[0])))
            return 0;
        return 1;
    } else if (command == "Execute") {
        if (!this->Execute(param[0]))
            return 0;
        return 1;
    } else if (command == "GetById") {
        if (!this->GetById(param[0], data))
            return 0;
        return 1;
    }

    cout << "Command is not found!" << endl;
    return 0;
}
