#define VECTOR_IMPLEMENTATION
#include <stdio.h>
#include "vector.h"

int main() {
    Vector vector;
    vector_init(&vector, sizeof(int), 4);

    for (int i = 0; i < 10; i++) {
        vector_push_back(&vector, &i);
    }

    for (size_t i = 0; i < vector.size; i++) {
        int *value = (int *)vector_get(&vector, i);
        printf("%d ", *value);
    }
    printf("\n");

    vector_free(&vector);
    return 0;
}