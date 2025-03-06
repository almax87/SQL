cmake_minimum_required (VERSION 3.9)

project (bookshop)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
include_directories(/usr/local/include/Wt)
add_executable(bookshop main.cpp)
target_compile_features(bookshop PRIVATE cxx_std_20)
target_link_libraries(bookshop libwt.so libwtdbo.so libwtdbopostgres.so libwttest.so libwthttp.so)