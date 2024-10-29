#define VECTOR_IMPLEMENTATION
#include "vector.h"
#include <stdio.h>

DEFINE_VECTOR(int)

int main() {
  intVector vector;
  int_vector_init(&vector, sizeof(int));

  for (int i = 0; i < 10; i++) {
    int_vector_push_back(&vector, i);
  }

  for (size_t i = 0; i < vector.size; i++) {
    int value = int_vector_get(&vector, i);
    printf("%d ", value);
  }
  printf("\n");

  int_vector_free(&vector);
  return 0;
}