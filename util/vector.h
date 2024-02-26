//
// Created by Ian lin on 2024/2/26.
//

#ifndef HTTP_PARSER_C_1_VECTOR_H
#define HTTP_PARSER_C_1_VECTOR_H

#include <stddef.h>

typedef struct {
    void *data;
    size_t element_size;
    size_t size;
    size_t capacity;
} vector_t;

vector_t vector_create_stack(size_t element_size);

vector_t *vector_create_heap(size_t element_size);

void vector_expand(vector_t *vector, size_t new_capacity);

void vector_push(vector_t *vector, void *element);

void vector_free(vector_t *vector);

#endif //HTTP_PARSER_C_1_VECTOR_H
