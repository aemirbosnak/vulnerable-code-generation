//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers within a range
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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
    int bucketSize = range / n;
    int* buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = (int*) malloc(bucketSize * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < range; j++) {
            if (arr[i] <= j && j <= max) {
                int bucketIndex = (arr[i] - min) / bucketSize;
                int position = 0;
                while (position < bucketSize && buckets[i][position] < j) {
                    position++;
                }
                for (int k = bucketSize - 1; k >= position; k--) {
                    buckets[i][k + 1] = buckets[i][k];
                }
                buckets[i][position] = j;
            }
        }
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSize; j++) {
            if (buckets[i][j]!= 0) {
                arr[index++] = buckets[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = generateRandomNumber(1, 100);
    }
    printf("Before sorting:\n");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("After sorting:\n");
    printArray(arr, n);
    return 0;
}