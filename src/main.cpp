#include "httpserver/HttpServerApp.h"

int main(int argc, char** argv) {
    TodoApp app;
    return app.run(argc, argv);
}


/*
* Todo app REST API
*
* GET /todos - return all todos
* POST /todos - create new todo
* GET /todos/{id} - return todo by Id
* PUT /todos/{id} - update todos by Id
* DELETE /todos/{id} - delelte todos by Id
*
*
* Future update.
* API will work on /api/todos, static files will work on /index.html
*/