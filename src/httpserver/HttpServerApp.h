#pragma once

#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Util/ServerApplication.h>
#include <Poco/Util/Application.h>


#include "../endpoints/TodoAppRouter.h"

using namespace Poco::Net;
using namespace Poco::Util;
using namespace Poco;

class TodoApp : public ServerApplication {
protected:
    void initialize(Application& self) override {
        loadConfiguration();
        ServerApplication::initialize(self);
    }

    int main(const std::vector<std::string>& args) override {
        unsigned short port = 8080;
        HTTPServer srv(Poco::makeShared<TodoAppRouter>(), ServerSocket{ port }, Poco::makeAuto<HTTPServerParams>());
        srv.start();
        std::cout << "HTTP Server started on port " << port << std::endl;

        waitForTerminationRequest();

        srv.stop();
        std::cout << "HTTP Server stopped" << std::endl;
        return Application::EXIT_OK;
    }
};