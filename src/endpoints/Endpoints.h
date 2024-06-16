#pragma once

#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

using namespace Poco::Net;

class EndPoints
{
public:

    static void handleHello(HTTPServerRequest& request, HTTPServerResponse& response);

    static void handleGoodbye(HTTPServerRequest& request, HTTPServerResponse& response);

    static void handleNotFound(HTTPServerRequest& request, HTTPServerResponse& response);
};