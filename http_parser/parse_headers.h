//
// Created by Ian lin on 2024/2/26.
//

#ifndef HTTP_PARSER_C_1_PARSE_HEADERS_H
#define HTTP_PARSER_C_1_PARSE_HEADERS_H

#include "../util/vector.h"

typedef struct {
    char* key;
    char* value;
} http_header_t;

vector_t parse_headers(char* raw, int raw_len, const int* last_index);

#endif //HTTP_PARSER_C_1_PARSE_HEADERS_H
