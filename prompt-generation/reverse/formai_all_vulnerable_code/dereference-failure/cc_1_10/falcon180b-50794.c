//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

// Function to generate a random integer between min and max (inclusive)
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];

    // Find the minimum and maximum values in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range and bucket size
    int range = max - min + 1;
    int bucketSize = range / n;

    // Create n empty buckets
    int* buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = malloc(bucketSize * sizeof(int));
    }

    // Place each element in the appropriate bucket
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / bucketSize;
        int* bucket = buckets[bucketIndex];
        int j = 0;
        while (j < bucketSize && bucket[j]!= 0) {
            j++;
        }
        bucket[j] = arr[i];
    }

    // Concatenate the sorted buckets back into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < bucketSize && buckets[i][j]!= 0) {
            arr[index++] = buckets[i][j];
            j++;
        }
    }

    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
}

// Function to generate a random array of integers
void generateArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = randInt(1, MAX_SIZE);
    }
}

int main() {
    int n = randInt(1, MAX_SIZE);
    int arr[n];

    generateArray(arr, n);

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}