//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

typedef struct {
    int *data;
    int size;
} Array;

void generateRandomArray(Array *arr) {
    srand(time(NULL));
    arr->data = (int*)malloc(MAX_SIZE * sizeof(int));
    arr->size = rand() % MAX_SIZE + 1;
    for (int i = 0; i < arr->size; i++) {
        arr->data[i] = rand() % MAX_SIZE;
    }
}

void printArray(Array arr) {
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");
}

void bucketSort(Array arr) {
    int max = arr.data[0];
    for (int i = 1; i < arr.size; i++) {
        if (arr.data[i] > max) {
            max = arr.data[i];
        }
    }
    int *buckets = (int*)malloc(MAX_SIZE * sizeof(int));
    for (int i = 0; i < MAX_SIZE; i++) {
        buckets[i] = 0;
    }
    for (int i = 0; i < arr.size; i++) {
        int index = arr.data[i] * MAX_SIZE / max;
        buckets[index]++;
    }
    int *sorted = (int*)malloc(arr.size * sizeof(int));
    int j = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int k = 0; k < buckets[i]; k++) {
            sorted[j++] = i * MAX_SIZE / MAX_SIZE + k;
        }
    }
    for (int i = 0; i < arr.size; i++) {
        arr.data[i] = sorted[i];
    }
    free(buckets);
    free(sorted);
}

int main() {
    Array arr;
    generateRandomArray(&arr);
    printf("Random array:\n");
    printArray(arr);
    bucketSort(arr);
    printf("Sorted array:\n");
    printArray(arr);
    free(arr.data);
    return 0;
}