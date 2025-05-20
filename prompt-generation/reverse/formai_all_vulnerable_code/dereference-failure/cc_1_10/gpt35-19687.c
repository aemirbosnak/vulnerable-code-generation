//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// define the maximum and minimum values to be sorted
#define MAX_VALUE 100
#define MIN_VALUE 1

// function for bucket sort implementation
void bucketSort(int arr[], int n) {
    // create the buckets
    int buckets[MAX_VALUE - MIN_VALUE + 1];

    // initialize all the buckets to 0
    for (int i = 0; i < MAX_VALUE - MIN_VALUE + 1; i++) {
        buckets[i] = 0;
    }

    // increment the counter for each value encountered in the array
    for (int i = 0; i < n; i++) {
        buckets[arr[i] - MIN_VALUE]++;
    }

    // sort the array by iterating over the buckets and placing each value in the appropriate position
    int index = 0;
    for (int i = 0; i < MAX_VALUE - MIN_VALUE + 1; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = i + MIN_VALUE;
        }
    }
}

int main() {
    printf("Welcome to the bucket sort program!\n\n");

    // prompt the user for input
    printf("Please enter the size of the array you wish to sort: ");
    int size;
    scanf("%d", &size);

    // dynamically allocate memory for the array
    int* arr = (int*)malloc(size * sizeof(int));

    // populate the array with random numbers
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    // print the unsorted array
    printf("\nUnsorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // use bucket sort to sort the array
    bucketSort(arr, size);

    // print the sorted array
    printf("\n\nSorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // free the dynamically allocated memory and exit the program
    free(arr);
    printf("\n\nThank you for using the bucket sort program!\n");
    return 0;
}