//
// Created by Ian lin on 2024/2/26.
//

#include "parse_headers.h"

#include "../util/util.h"

http_header_t parse_header(char* str, int str_len) {
    http_header_t header;
    for (int i = 0; i < str_len; i++) {
        if (str[i] == ':' && str[i+1] == ' ') {
            header.key = copy_substring(str, 0, i);
            header.value = copy_substring(str, i + 2, str_len);
        }
    }
    return header;
}

vector_t parse_headers(char* raw, int raw_len, const int* last_index) {
    vector_t http_headers = vector_create_stack(sizeof(http_header_t));
    int next_header_start = *last_index;
    for (int i = *last_index; i < raw_len; i++) {
        if (raw[i] == '\r' && raw[i+1] == '\n') {
            http_header_t result = parse_header(copy_substring(raw, next_header_start, i), i - next_header_start);
            vector_push(&http_headers, &result);
            next_header_start = i + 2;
        }
    }
    return http_headers;
}