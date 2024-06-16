#pragma once

#include "Endpoints.h"
#include "EndPointHandler.h"

#include <Poco/Net/HTTPRequestHandlerFactory.h>

#include <map>

using namespace Poco::Net;

class TodoAppRouter : public HTTPRequestHandlerFactory {
public:
    TodoAppRouter();

    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request) override;

private:
    std::map<std::string, EndPointHandler::HandlerFunc> handlers;
};