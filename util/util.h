//
// Created by Ian lin on 2024/2/23.
//

#ifndef HTTP_SERVER_C_1_UTIL_H
#define HTTP_SERVER_C_1_UTIL_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void *allocate_memory(size_t size, size_t count);

void *reallocate_memory(void *pointer, size_t size, size_t count);

void *copy_substring(char *string, int start, int end);

#endif //HTTP_SERVER_C_1_UTIL_H
