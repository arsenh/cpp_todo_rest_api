#include "TodoAppRouter.h"

#include <Poco/Net/HTTPServerRequest.h>

TodoAppRouter::TodoAppRouter()
{
	handlers["/hello"] = EndPoints::handleHello;
	handlers["/goodbye"] = EndPoints::handleGoodbye;
}

HTTPRequestHandler* TodoAppRouter::createRequestHandler(const HTTPServerRequest& request)
{
    auto it = handlers.find(request.getURI());

    if (it != handlers.end()) {
        return new EndPointHandler(it->second);
    } else {
        return new EndPointHandler(EndPoints::handleNotFound);
    }
}