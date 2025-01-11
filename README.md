# ArrayList


**Example**
```c
#include "arraylist.h"
#include <stdio.h>

DEFINE_ARRAY_LIST(int)

int main() {
    intArrayList vector;
    intArrayListInit(&vector, sizeof(int));

    for (int i = 0; i < 10; i++) {
        intArrayListPush(&vector, i);
    }

    for (size_t i = 0; i < vector.size; i++) {
        int* value = intArrayListGet(&vector, i);
        printf("%d ", *value);
    }
    printf("\n");

    intArrayListFree(&vector);
    return 0;
}
```
