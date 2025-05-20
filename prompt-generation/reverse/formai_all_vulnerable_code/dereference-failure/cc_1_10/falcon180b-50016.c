//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000
#define MIN_VALUE -1000
#define MAX_VALUE 1000

typedef struct {
    int size;
    int *array;
} IntArray;

IntArray* createIntArray(int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    if (array == NULL) {
        printf("Error: Could not allocate memory for array.\n");
        exit(1);
    }
    array->size = size;
    array->array = (int*)malloc(sizeof(int) * size);
    if (array->array == NULL) {
        printf("Error: Could not allocate memory for array elements.\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        array->array[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
    return array;
}

void destroyIntArray(IntArray* array) {
    free(array->array);
    free(array);
}

void printIntArray(IntArray* array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->array[i]);
    }
    printf("\n");
}

void sortIntArray(IntArray* array) {
    for (int i = 0; i < array->size - 1; i++) {
        for (int j = i + 1; j < array->size; j++) {
            if (array->array[j] < array->array[i]) {
                int temp = array->array[i];
                array->array[i] = array->array[j];
                array->array[j] = temp;
            }
        }
    }
}

int main(int argc, char** argv) {
    srand(time(NULL));
    IntArray* array = createIntArray(MAX_SIZE);
    printIntArray(array);
    sortIntArray(array);
    printIntArray(array);
    destroyIntArray(array);
    return 0;
}