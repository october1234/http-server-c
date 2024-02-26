//
// Created by Ian lin on 2024/2/26.
//

#ifndef HTTP_PARSER_C_1_PARSE_METHOD_H
#define HTTP_PARSER_C_1_PARSE_METHOD_H

#define HTTP_METHOD_GET 0
#define HTTP_METHOD_HEAD 1
#define HTTP_METHOD_POST 2
#define HTTP_METHOD_PUT 3
#define HTTP_METHOD_DELETE 4
#define HTTP_METHOD_CONNECT 5
#define HTTP_METHOD_OPTIONS 6
#define HTTP_METHOD_TRACE 7
#define HTTP_METHOD_PATCH 8
typedef int http_method_t;

int parse_method(char* raw, int raw_len, int* last_index);

#endif //HTTP_PARSER_C_1_PARSE_METHOD_H
