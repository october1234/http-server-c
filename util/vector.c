//
// Created by Ian lin on 2024/2/26.
//

#include "vector.h"

#include <stdlib.h>
#include <libc.h>

#include "util.h"

#define INITIAL_CAPACITY 5

vector_t vector_create_stack(size_t element_size) {
    vector_t vector = {
        .data = allocate_memory(element_size, INITIAL_CAPACITY),
        .element_size = element_size,
        .size = 0,
        .capacity = INITIAL_CAPACITY,
    };
    return vector;
}

vector_t *vector_create_heap(size_t element_size) {
    vector_t *vector = allocate_memory(sizeof(vector_t), 1);

    vector->data = allocate_memory(element_size, INITIAL_CAPACITY);
    vector->element_size = element_size;
    vector->size = 0;
    vector->capacity = INITIAL_CAPACITY;

    return vector;
}

void vector_expand(vector_t *vector, size_t new_capacity) {
    if (new_capacity <= vector->capacity) return; // No expansion needed
    vector->data = reallocate_memory(vector->data, vector->element_size, new_capacity);
    vector->capacity = new_capacity;
}

void vector_push(vector_t *vector, void *element) {
    if (vector->size == vector->capacity)
        vector_expand(vector, vector->capacity * 2);

    size_t index = vector->size;
    memcpy(vector->data + (index * vector->element_size), element, vector->element_size);
    vector->size++;
}

void vector_free(vector_t *vector) {
    free(vector->data);
    free(vector);
}