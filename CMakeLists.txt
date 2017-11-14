cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

include(cmake/HunterGate.cmake)

HunterGate(
    URL "https://github.com/uliana99/hunter/archive/v0.19.137.1.tar.gz"
    SHA1 "87af3ced13dd7a194ca94db4cd0d21908d80b596"
)

project(curl)

hunter_add_package(CURL)
find_package(CURL CONFIG REQUIRED)

add_executable(curl ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(curl CURL::libcurl)
