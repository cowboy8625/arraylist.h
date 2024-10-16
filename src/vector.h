/*
 * +----------------------------------------+
 * |           Example Useage               |
 * +----------------------------------------+
 *
 * #define VECTOR_IMPLEMENTATION
 * #include <stdio.h>
 * #include "vector.h"
 *
 * int main() {
 *     Vector vector;
 *     vector_init(&vector, sizeof(int), 4);
 *
 *     for (int i = 0; i < 10; i++) {
 *         vector_push_back(&vector, &i);
 *     }
 *
 *     for (size_t i = 0; i < vector.size; i++) {
 *         int *value = (int *)vector_get(&vector, i);
 *         printf("%d ", *value);
 *     }
 *     printf("\n");
 *
 *     vector_free(&vector);
 *     return 0;
 * }
 *
 */
#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  void *data;
  size_t element_size;
  size_t size;
  size_t capacity;
} Vector;

void vector_init(Vector *vector, size_t element_size, size_t initial_capacity);
void vector_resize(Vector *vector, size_t new_capacity);
void vector_push_back(Vector *vector, void *element);
void *vector_get(Vector *vector, size_t index);
void vector_free(Vector *vector);

#endif // VECTOR_H

#ifdef VECTOR_IMPLEMENTATION

void vector_init(Vector *vector, size_t element_size, size_t initial_capacity) {
  vector->data = malloc(initial_capacity * element_size);
  vector->element_size = element_size;
  vector->size = 0;
  vector->capacity = initial_capacity;
}

void vector_resize(Vector *vector, size_t new_capacity) {
  vector->data = realloc(vector->data, new_capacity * vector->element_size);
  vector->capacity = new_capacity;
}

void vector_push_back(Vector *vector, void *element) {
  if (vector->size == vector->capacity) {
    vector_resize(vector, vector->capacity * 2);
  }
  void *target = (char *)vector->data + (vector->size * vector->element_size);
  memcpy(target, element, vector->element_size);
  vector->size++;
}

void *vector_get(Vector *vector, size_t index) {
  if (index >= vector->size) {
    fprintf(stderr, "Index out of bounds\n");
    exit(EXIT_FAILURE);
  }
  return (char *)vector->data + (index * vector->element_size);
}

void vector_free(Vector *vector) {
  free(vector->data);
  vector->data = NULL;
  vector->size = 0;
  vector->capacity = 0;
  vector->element_size = 0;
}

#endif // VECTOR_IMPLEMENTATION
