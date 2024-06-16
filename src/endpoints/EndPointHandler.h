#pragma once

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

#include <functional>

using namespace Poco::Net;
using namespace Poco;

class EndPointHandler : public HTTPRequestHandler {
public:
    using HandlerFunc = std::function<void(HTTPServerRequest&, HTTPServerResponse&)>;

    EndPointHandler(const HandlerFunc& h) : handler{ h } {}

    void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response) override
    {
        handler(request, response);
    }

private:
    HandlerFunc handler;
};