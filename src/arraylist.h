/*
 * +----------------------------------------+
 * |           Example Useage               |
 * +----------------------------------------+
 *
 * #include "arraylist.h"
 * #include <stdio.h>
 *
 * DEFINE_ARRAY_LIST(int)
 *
 * int main() {
 *   intArrayList vector;
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
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Usaged if you dont want to have a header file
#define DEFINE_ARRAY_LIST(type)                                                \
  DEFINE_ARRAY_LIST_HEADER(type)                                               \
  DEFINE_ARRAY_LIST_IMPLEMENTATION(type)

#define DEFINE_ARRAY_LIST_HEADER(type)                                         \
  typedef struct {                                                             \
    type *data;                                                                \
    size_t size;                                                               \
    size_t capacity;                                                           \
  } type##ArrayList;                                                           \
                                                                               \
  void type##ArrayListInit(type##ArrayList *vector, size_t initial_capacity);  \
  void type##ArrayListResize(type##ArrayList *vector, size_t new_capacity);    \
  void type##ArrayListPush(type##ArrayList *vector, type element);             \
  type type##ArrayListPop(type##ArrayList *vector);                            \
  type *type##ArrayListGet(type##ArrayList *vector, size_t index);             \
  void type##ArrayListClearRetainSize(type##ArrayList *vector);                \
  void type##ArrayListFree(type##ArrayList *vector);

#define DEFINE_ARRAY_LIST_IMPLEMENTATION(type)                                 \
  void type##ArrayListInit(type##ArrayList *vector, size_t initial_capacity) { \
    vector->data = (type *)malloc(initial_capacity * sizeof(type));            \
    vector->size = 0;                                                          \
    vector->capacity = initial_capacity;                                       \
  }                                                                            \
                                                                               \
  void type##ArrayListResize(type##ArrayList *vector, size_t new_capacity) {   \
    vector->data = (type *)realloc(vector->data, new_capacity * sizeof(type)); \
    vector->capacity = new_capacity;                                           \
  }                                                                            \
                                                                               \
  void type##ArrayListPush(type##ArrayList *vector, type element) {            \
    if (vector->size == vector->capacity) {                                    \
      type##ArrayListResize(vector, vector->capacity * 2);                     \
    }                                                                          \
    vector->data[vector->size++] = element;                                    \
  }                                                                            \
                                                                               \
  type type##ArrayListPop(type##ArrayList *vector) {                           \
    if (vector->size == 0) {                                                   \
      fprintf(stderr, "ArrayList is empty\n");                                 \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
    type value = vector->data[--vector->size];                                 \
    return value;                                                              \
  }                                                                            \
                                                                               \
  type *type##ArrayListGet(type##ArrayList *vector, size_t index) {            \
    if (index >= vector->size) {                                               \
      fprintf(stderr, "Index out of bounds\n");                                \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
    return &vector->data[index];                                               \
  }                                                                            \
                                                                               \
  void type##ArrayListClearRetainSize(type##ArrayList *vector) {               \
    vector->size = 0;                                                          \
  }                                                                            \
                                                                               \
  void type##ArrayListFree(type##ArrayList *vector) {                          \
    free(vector->data);                                                        \
    vector->data = NULL;                                                       \
    vector->size = 0;                                                          \
    vector->capacity = 0;                                                      \
  }

#endif // ARRAY_LIST_IMPLEMENTATION
