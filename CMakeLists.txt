cmake_minimum_required(VERSION 3.10)

project(todo_rest)

set(CMAKE_CXX_STANDARD 20)

find_package(Poco REQUIRED COMPONENTS Foundation Net Util)

add_executable(todo_rest "src/main.cpp" "src/httpserver/HttpServerApp.h" "src/endpoints/Endpoints.h" "src/endpoints/Endpoints.cpp" "src/endpoints/EndPointHandler.h"  "src/endpoints/TodoAppRouter.h" "src/endpoints/TodoAppRouter.cpp")

target_link_libraries(todo_rest PRIVATE Poco::Foundation Poco::Net Poco::Util)

target_include_directories(todo_rest PRIVATE ${Poco_INCLUDE_DIRS})
