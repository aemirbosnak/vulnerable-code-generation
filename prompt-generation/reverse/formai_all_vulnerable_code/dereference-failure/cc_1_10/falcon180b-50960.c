//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
} IntArray;

void init_array(IntArray *arr, int size) {
    arr->data = malloc(size * sizeof(int));
    arr->size = size;
}

void free_array(IntArray *arr) {
    free(arr->data);
}

void print_array(IntArray arr) {
    int i;
    for (i = 0; i < arr.size; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");
}

int main() {
    IntArray arr1, arr2;
    int i, j, n;

    srand(time(NULL));
    n = rand() % MAX_SIZE + 1;

    init_array(&arr1, n);
    init_array(&arr2, n);

    for (i = 0; i < n; i++) {
        arr1.data[i] = rand() % 100;
        arr2.data[i] = rand() % 100;
    }

    printf("Array 1: ");
    print_array(arr1);

    printf("Array 2: ");
    print_array(arr2);

    for (i = 0; i < n; i++) {
        arr1.data[i] += arr2.data[i];
    }

    printf("Sum of arrays: ");
    print_array(arr1);

    free_array(&arr1);
    free_array(&arr2);

    return 0;
}