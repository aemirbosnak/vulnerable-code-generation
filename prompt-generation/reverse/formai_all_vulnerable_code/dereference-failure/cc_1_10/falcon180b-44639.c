//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function to generate random integers within the given range
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to swap two elements in the array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bucket sort on the given array
void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int bucketSize = max / n;
    int* buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = (int*) malloc(bucketSize * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        int j = 0;
        while (j < bucketSize &&!buckets[bucketIndex][j]) {
            j++;
        }
        buckets[bucketIndex][j] = arr[i];
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSize; j++) {
            if (buckets[i][j]) {
                arr[k++] = buckets[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
}

// Function to print the given array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int n = generateRandomNumber(1, MAX_SIZE);
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = generateRandomNumber(1, MAX_SIZE);
    }

    printf("Before sorting:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("After sorting:\n");
    printArray(arr, n);

    return 0;
}