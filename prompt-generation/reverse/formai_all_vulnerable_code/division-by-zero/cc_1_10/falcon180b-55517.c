//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 100000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int bucketSize = max / n;
    int* buckets = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        buckets[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        buckets[bucketIndex]++;
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        buckets[bucketIndex]--;
        arr[--buckets[bucketIndex]] = arr[i];
    }

    free(buckets);
}

int main() {
    srand(time(NULL));
    int arr[MAX_SIZE];
    int n = rand() % MAX_SIZE + 1;

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX_SIZE;
    }

    printf("Before sorting:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("After sorting:\n");
    printArray(arr, n);

    return 0;
}