/*
 * +----------------------------------------+
 * |           Example Useage               |
 * +----------------------------------------+
 *
 * #define VECTOR_IMPLEMENTATION
 * #include "vector.h"
 * #include <stdio.h>
 *
 * DEFINE_VECTOR(int)
 *
 * int main() {
 *   intVector vector;
 *   int_vector_init(&vector, sizeof(int));
 *
 *   for (int i = 0; i < 10; i++) {
 *     int_vector_push_back(&vector, i);
 *   }
 *
 *   for (size_t i = 0; i < vector.size; i++) {
 *     int value = int_vector_get(&vector, i);
 *     printf("%d ", value);
 *   }
 *   printf("\n");
 *
 *   int_vector_free(&vector);
 *   return 0;
 * }
 *
 */
#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFINE_VECTOR(type)                                                    \
  typedef struct {                                                             \
    type *data;                                                                \
    size_t size;                                                               \
    size_t capacity;                                                           \
  } type##Vector;                                                              \
                                                                               \
  void type##_vector_init(type##Vector *vector, size_t initial_capacity) {     \
    vector->data = (type *)malloc(initial_capacity * sizeof(type));            \
    vector->size = 0;                                                          \
    vector->capacity = initial_capacity;                                       \
  }                                                                            \
                                                                               \
  void type##_vector_resize(type##Vector *vector, size_t new_capacity) {       \
    vector->data = (type *)realloc(vector->data, new_capacity * sizeof(type)); \
    vector->capacity = new_capacity;                                           \
  }                                                                            \
                                                                               \
  void type##_vector_push_back(type##Vector *vector, type element) {           \
    if (vector->size == vector->capacity) {                                    \
      type##_vector_resize(vector, vector->capacity * 2);                      \
    }                                                                          \
    vector->data[vector->size++] = element;                                    \
  }                                                                            \
                                                                               \
  type type##_vector_get(type##Vector *vector, size_t index) {                 \
    if (index >= vector->size) {                                               \
      fprintf(stderr, "Index out of bounds\n");                                \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
    return vector->data[index];                                                \
  }                                                                            \
                                                                               \
  void type##_vector_free(type##Vector *vector) {                              \
    free(vector->data);                                                        \
    vector->data = NULL;                                                       \
    vector->size = 0;                                                          \
    vector->capacity = 0;                                                      \
  }

#endif // VECTOR_IMPLEMENTATION
