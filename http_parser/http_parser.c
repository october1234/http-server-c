//
// Created by Ian lin on 2024/2/26.
//

#include "http_parser.h"

#include <stdlib.h>

#include "../util/util.h"
#include "../util/vector.h"
#include "parse_method.h"
#include "parse_headers.h"

char *parse_path(char* raw, int raw_len, int* last_index) {
    char *path = NULL;
    for (int i = *last_index; i < raw_len; i++) {
        if (raw[i] == ' ') {
            path = copy_substring(raw, *last_index, i);
            *last_index = i + 1;
            break;
        }
    }
    if (path == NULL) {
        perror("Invalid Http Request");
        exit(-1);
    }
    return path;
}

char *parse_version(char* raw, int raw_len, int* last_index) {
    char *path = NULL;
    for (int i = *last_index; i < raw_len; i++) {
        if (raw[i] == '\r' && raw[i+1] == '\n') {
            path = copy_substring(raw, *last_index, i);
            *last_index = i + 2;
            break;
        }
    }
    if (path == NULL) {
        perror("Invalid Http Request");
        exit(-1);
    }
    return path;
}

http_request_t parse_http(char* raw, int raw_len) {
    int last_index = 0;
    http_method_t method = parse_method(raw, raw_len, &last_index);
    char* path = parse_path(raw, raw_len, &last_index);
    char* version = parse_version(raw, raw_len, &last_index);
    vector_t http_headers = parse_headers(raw, raw_len, &last_index);
    int i = 0;
    http_request_t request = {
        .method = method,
        .path = path,
        .version = atof(version),
        .headers = http_headers
    };
    return request;
}