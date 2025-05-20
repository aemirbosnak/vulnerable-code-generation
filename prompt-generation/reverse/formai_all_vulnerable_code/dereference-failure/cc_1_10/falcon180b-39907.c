//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

typedef struct {
    int *data;
    int size;
} IntArray;

void init_array(IntArray *array, int size) {
    array->data = (int*) malloc(size * sizeof(int));
    array->size = size;
}

void fill_array(IntArray *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        array->data[i] = rand() % 100;
    }
}

void print_array(IntArray *array) {
    int i;
    for (i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

void free_array(IntArray *array) {
    free(array->data);
}

int main() {
    IntArray arr1, arr2;
    int i, j, k;
    clock_t start, end;

    init_array(&arr1, MAX_SIZE);
    init_array(&arr2, MAX_SIZE);

    fill_array(&arr1, MAX_SIZE);
    fill_array(&arr2, MAX_SIZE);

    start = clock();
    for (i = 0; i < MAX_SIZE; i++) {
        arr2.data[i] = arr1.data[i] * 2;
    }
    end = clock();

    printf("Time taken to multiply an array of %d elements: %f seconds\n", MAX_SIZE, (double)(end - start) / CLOCKS_PER_SEC);

    free_array(&arr1);
    free_array(&arr2);

    return 0;
}