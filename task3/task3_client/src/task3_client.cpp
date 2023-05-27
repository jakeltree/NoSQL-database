#include <task3_client.h>

int JsonMethods::Send(string command, vector<string> param) {
    httplib::Client cli(baseUrl);
    json obj = {
        {"Command", command},
        {"Param", "null"}
    };
    obj["Param"] = param;
    auto res = cli.Post("/process", obj.dump(), "application/json");
    json receive = json::parse(res->body);
    int responseSuccess = receive["Response"];
    json data = receive["Data"];
    if (data != nullptr) 
        cout << data.dump(4) << endl;
    return responseSuccess;
}

void JsonMethods::Shutdown() {
    httplib::Client cli(baseUrl);
    cli.Get("/stop");
}
