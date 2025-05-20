//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
/* Bucket Sort Implementation in C */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define RANGE 100

// Function to generate random numbers between 0 and RANGE-1
void generateRandomArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % RANGE;
    }
}

// Function to sort the array using Bucket Sort
void bucketSort(int arr[], int n) {
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        } else if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int *bucket = (int *) malloc(range * sizeof(int));

    // Initialize all buckets to 0
    for (int i = 0; i < range; i++) {
        bucket[i] = 0;
    }

    // Place each element in its respective bucket
    for (int i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }

    // Modify the array by placing each element in its sorted position
    int index = 0;
    for (int i = 0; i < range; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            arr[index++] = i + min;
        }
    }

    free(bucket);
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    generateRandomArray(arr, n);

    printf("Unsorted Array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted Array:\n");
    printArray(arr, n);

    return 0;
}