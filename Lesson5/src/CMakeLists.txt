cmake_minimum_required (VERSION 3.9)

project (client_manager)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
add_executable(client_manager main.cpp methods.cpp)
add_subdirectory(/usr/bin/libpqxx/libpqxx-7.10.0/ libpqxx-build)
target_compile_features(client_manager PRIVATE cxx_std_17)
target_link_libraries(client_manager pqxx)
