//
// Created by Ian lin on 2024/2/26.
//
#include "parse_method.h"

#include <stddef.h>
#include <string.h>

#include "../util/util.h"

http_method_t get_method_from_string(char* method_string){
    if (strcmp(method_string, "GET") == 0)
        return HTTP_METHOD_GET;
    if (strcmp(method_string, "HEAD") == 0)
        return HTTP_METHOD_HEAD;
    if (strcmp(method_string, "POST") == 0)
        return HTTP_METHOD_POST;
    if (strcmp(method_string, "PUT") == 0)
        return HTTP_METHOD_PUT;
    if (strcmp(method_string, "DELETE") == 0)
        return HTTP_METHOD_DELETE;
    if (strcmp(method_string, "CONNECT") == 0)
        return HTTP_METHOD_CONNECT;
    if (strcmp(method_string, "OPTIONS") == 0)
        return HTTP_METHOD_OPTIONS;
    if (strcmp(method_string, "TRACE") == 0)
        return HTTP_METHOD_TRACE;
    if (strcmp(method_string, "PATCH") == 0)
        return HTTP_METHOD_PATCH;
    return -1;
}

int parse_method(char* raw, int raw_len, int* last_index) {
    char *method = NULL;
    for (int i = *last_index; i < raw_len; i++) {
        if (raw[i] == ' ') {
            method = copy_substring(raw, 0, i);
            *last_index = i + 1;
            break;
        }
    }
    if (method == NULL) {
        perror("Invalid Http Request");
        exit(-1);
    }
    return (get_method_from_string(method));
}