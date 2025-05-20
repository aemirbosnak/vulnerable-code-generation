//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert an element into its correct position in the sorted bucket
void insert(int arr[], int n, int element) {
    int i = 0;
    while (arr[i] < element) {
        i++;
    }
    swap(&arr[i], &arr[i+1]);
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int bucket[MAX];
    int i, j, k;
    for (i = 0; i < n; i++) {
        if (arr[i] < 0) {
            arr[i] *= -1;
        }
        bucket[arr[i] % MAX]++;
    }
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < bucket[i]; j++) {
            arr[k] = i;
            k++;
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = { -3, -1, 0, 2, 4, 6, -7, -9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}