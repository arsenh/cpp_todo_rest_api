#include <iostream>

#include "Endpoints.h"


void EndPoints::handleHello(HTTPServerRequest& request, HTTPServerResponse& response)
{
    response.setStatus(HTTPResponse::HTTP_OK);
    response.setContentType("text/html");

    std::ostream& out = response.send();
    out << "<html><head><title>Hello</title></head>";
    out << "<body><h1>Hello, World!</h1></body></html>";
    out.flush();
}

void EndPoints::handleGoodbye(HTTPServerRequest& request, HTTPServerResponse& response)
{
    response.setStatus(HTTPResponse::HTTP_OK);
    response.setContentType("text/html");

    std::ostream& out = response.send();
    out << "<html><head><title>Goodbye</title></head>";
    out << "<body><h1>Goodbye, World!</h1></body></html>";
    out.flush();
}

void EndPoints::handleNotFound(HTTPServerRequest& request, HTTPServerResponse& response)
{
    response.setStatus(HTTPResponse::HTTP_NOT_FOUND);
    response.setContentType("text/html");

    std::ostream& out = response.send();
    out << "<html><head><title>404 Not Found</title></head>";
    out << "<body><h1>404 - Page Not Found</h1></body></html>";
    out.flush();
}