//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    int* data;
    int size;
} IntArray;

IntArray* createIntArray(int size) {
    IntArray* arr = malloc(sizeof(IntArray));
    arr->data = malloc(sizeof(int) * size);
    arr->size = size;
    for (int i = 0; i < size; i++) {
        arr->data[i] = rand() % 100;
    }
    return arr;
}

void printIntArray(IntArray* arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

void freeIntArray(IntArray* arr) {
    free(arr->data);
    free(arr);
}

void bubbleSort(IntArray* arr) {
    int n = arr->size;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr->data[j] > arr->data[j + 1]) {
                int temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    IntArray* arr = createIntArray(MAX_SIZE);
    bubbleSort(arr);
    printIntArray(arr);
    freeIntArray(arr);
    return 0;
}