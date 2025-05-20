//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void printArray(int arr[], int size) {
    for (int i=0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int size) {
    int i, j;
    int min_val = arr[0], max_val = arr[0];
    int range, bucket_count, k;
    int **buckets;

    for (i = 1; i < size; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        } else if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    range = max_val - min_val;

    bucket_count = range / SIZE;

    buckets = (int **) malloc(sizeof(int *) * bucket_count);

    for (i = 0; i < bucket_count; i++) {
        buckets[i] = (int *) malloc(sizeof(int) * SIZE);
    }

    for (i = 0; i < size; i++) {
        k = (arr[i] - min_val) / SIZE;
        buckets[k][i % SIZE] = arr[i];
    }

    for (i = 0; i < bucket_count; i++) {
        for (j = 0; j < SIZE; j++) {
            if (buckets[i][j]) {
                printf("%d ", buckets[i][j]);
            }
        }
    }
}

int main() {
    int arr[10] = {4, 7, 2, 5, 1, 3, 10, 8, 9, 6};

    printf("Input array: ");
    printArray(arr, 10);

    printf("Sorted array: ");
    bucketSort(arr, 10);

    return 0;
}