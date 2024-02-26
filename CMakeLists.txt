cmake_minimum_required(VERSION 3.27)
project(http_server_c_1 C)

set(CMAKE_C_STANDARD 11)

add_executable(http_server_c_1 main.c
        http_parser/http_parser.h
        http_parser/http_parser.c
        http_parser/parse_headers.c
        http_parser/parse_headers.h
        http_parser/parse_method.c
        http_parser/parse_method.h
        util/util.c
        util/vector.c)
