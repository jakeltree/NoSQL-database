#include <task3_server.h>

int main() {
    httplib::Server svr;
    Literature lit;
    svr.Post("/process",
        [&](const httplib::Request &req, httplib::Response &res) {
            json send = json::parse(req.body);
            json data;
            int processResult = lit.ProcessCommand(send, data);
            if (processResult)
                cout << "Success" << endl;
            json receive = {
                {"Response", processResult},
                {"Command", send["Command"]},
                {"Data", data}
            };
            res.set_content(receive.dump(), "application/json");
        });

    svr.Get("/stop", [&](const auto& /*req*/, auto& /*res*/) {
        svr.stop();
    });
    cout << "Running server on PORT 8080" << endl;
    svr.listen("localhost", 8080);
}
