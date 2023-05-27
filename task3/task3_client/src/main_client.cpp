#include <task3_client.h>

int main() {
    JsonMethods process;
    while (1) {
        cout << "Введите команду (без параметра) или \"Help\""
             << " для получения справки о командах" << endl;
        string command;
        cin >> command;
        if (command == "Help") {
            cout <<  R"(
                Набор команд:
                    1. Print
                    2. Input 
                        Параметр:{имя_файла}
                    3. Add
                        Параметр:{поле Name}
                    4. Delete
                        Параметр:{поле Name}
                    5. Generate
                        Параметр:{количество записей}
                    6. Execute
                        Параметр:{файл для вывода}
                    7. GetById
                        Параметр:{ID записи}
                        Пример: GetById Literature177Met
            )" << endl;
            continue;
        }
        if (command == "Shutdown") {
            process.Shutdown();
            return 0;
        }
        int num;
        if (command == "Print") {
            num = 0;
        } else {
            num = 1;
        }
        vector<string> param;

        if (num) {
            cout << "Введите параметр" << endl;
            while (num--) {
                string s;
                getline(cin >> ws, s);
                param.push_back(s);
            }
            if (process.Send(command, param))
                cout << "Success\n\n";
            else
                cout << "Error\n\n";
        } else {
            if (process.Send(command))
                cout << "Success\n\n";
            else
                cout << "Error\n\n";
        }
    }
    return 0;
}
