//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bucketSort(int arr[], int size) {
    int bucketSize = size / 10;
    int *bucket[MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *)malloc(bucketSize * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / bucketSize;
        bucket[bucketIndex][i % bucketSize] = arr[i];
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        quickSort(bucket[i], 0, size / 10 - 1);
    }

    int index = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < size / 10; j++) {
            arr[index++] = bucket[i][j];
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, size);

    bucketSort(arr, size);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}