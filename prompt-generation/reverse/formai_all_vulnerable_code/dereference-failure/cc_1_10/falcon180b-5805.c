//Falcon-180B DATASET v1.0 Category: Memory management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int capacity;
    int size;
} IntArray;

IntArray *createIntArray(int initialCapacity) {
    IntArray *array = (IntArray *)malloc(sizeof(IntArray));
    if (array == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    array->data = (int *)malloc(initialCapacity * sizeof(int));
    if (array->data == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    array->capacity = initialCapacity;
    array->size = 0;
    return array;
}

void addIntToArray(IntArray *array, int value) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->data = (int *)realloc(array->data, array->capacity * sizeof(int));
    }
    array->data[array->size++] = value;
}

int main() {
    IntArray *array1 = createIntArray(10);
    IntArray *array2 = createIntArray(5);

    addIntToArray(array1, 1);
    addIntToArray(array1, 2);
    addIntToArray(array1, 3);
    addIntToArray(array1, 4);
    addIntToArray(array1, 5);

    addIntToArray(array2, 10);
    addIntToArray(array2, 20);
    addIntToArray(array2, 30);
    addIntToArray(array2, 40);
    addIntToArray(array2, 50);

    int *data1 = array1->data;
    int *data2 = array2->data;

    for (int i = 0; i < array1->size; i++) {
        printf("%d ", data1[i]);
    }
    printf("\n");

    for (int i = 0; i < array2->size; i++) {
        printf("%d ", data2[i]);
    }
    printf("\n");

    free(array1->data);
    free(array1);
    free(array2->data);
    free(array2);

    return 0;
}