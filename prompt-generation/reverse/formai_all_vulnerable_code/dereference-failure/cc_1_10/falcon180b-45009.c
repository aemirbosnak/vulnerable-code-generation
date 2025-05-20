//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array using the last element as pivot
int partition(int arr[], int n, int pivot) {
    int i = 0;
    for (int j = 0; j < n - 1; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[n - 1]);
    return i;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int range = max - min + 1;
    int *bucket = (int *) malloc(range * sizeof(int));
    memset(bucket, 0, range * sizeof(int));
    for (int i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }
    for (int i = 0; i < range; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            arr[j * range + i] = i + min;
        }
    }
    free(bucket);
}

// Function to print the sorted array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array: ");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}