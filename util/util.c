//
// Created by Ian lin on 2024/2/23.
//

#include "util.h"

void *allocate_memory(size_t size, size_t count) {
    void *pointer = malloc(size * count);
    if (pointer == NULL) {
        perror("Cannot allocate memory");
        exit(-1);
    }
    return pointer;
}

void *reallocate_memory(void *pointer, size_t size, size_t count) {
    void *new_pointer = realloc(pointer, size * count);
    if (pointer == NULL) {
        perror("Cannot reallocate memory");
        exit(-1);
    }
    return new_pointer;
}

void *copy_substring(char *string, int start, int end) {
    int length = end - start;
    char *substring = allocate_memory(sizeof(char), length + 1);
    for (int i = 0; i < length; i++) {
        substring[i] = string[start + i];
    }
    substring[length] = '\0';
    return substring;
}