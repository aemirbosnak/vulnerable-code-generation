//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000
#define MAX_VALUE 1000000

typedef struct {
    int *array;
    int size;
} Array;

int *generateArray(int size) {
    int *array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % MAX_VALUE;
    }
    return array;
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main() {
    Array arr = {0};
    clock_t start, end;

    start = clock();
    arr.array = generateArray(SIZE);
    arr.size = SIZE;
    end = clock();
    double time1 = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Generated array:\n");
    printArray(arr.array, arr.size);

    start = clock();
    sort(arr.array, arr.size);
    end = clock();
    double time2 = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    printArray(arr.array, arr.size);

    printf("Time taken to generate array: %lf seconds\n", time1);
    printf("Time taken to sort array: %lf seconds\n", time2);

    free(arr.array);
    return 0;
}