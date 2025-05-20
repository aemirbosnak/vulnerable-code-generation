//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000

// function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to sort an array using bucket sort
void bucketSort(int arr[], int n) {
    int i, j, index;
    int buckets[MAX_VALUE];

    // initialize all buckets to empty
    for (i = 0; i < MAX_VALUE; i++) {
        buckets[i] = -1;
    }

    // put each element in its bucket
    for (i = 0; i < n; i++) {
        index = arr[i] % MAX_VALUE;
        buckets[index] = i;
    }

    // sort each bucket using insertion sort
    for (i = 0; i < MAX_VALUE; i++) {
        if (buckets[i]!= -1) {
            for (j = buckets[i]; j < n - 1 && arr[j] <= arr[j + 1]; j++) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// function to fill an array with random values
void fillArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
}

// main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    fillArray(arr, n);

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}