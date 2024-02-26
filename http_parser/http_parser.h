//
// Created by Ian lin on 2024/2/26.
//

#ifndef HTTP_PARSER_C_1_HTTP_PARSER_H
#define HTTP_PARSER_C_1_HTTP_PARSER_H

#include "parse_method.h"
#include "../util/vector.h"

typedef struct {
    http_method_t method;
    char *path;
    float version;
    vector_t headers;
} http_request_t;

http_request_t parse_http(char* raw, int raw_len);

#endif //HTTP_PARSER_C_1_HTTP_PARSER_H
