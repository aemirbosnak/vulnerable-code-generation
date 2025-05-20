//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bucket size
#define BUCKET_SIZE 1000

// Function to sort an array using bucket sort
void sortArray(int arr[], int n) {
    // Create buckets
    int* buckets = (int*)malloc(BUCKET_SIZE * sizeof(int));
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = 0;
    }

    // Sort each bucket
    for (int i = 0; i < n; i++) {
        buckets[arr[i] / BUCKET_SIZE]++;
    }

    // Combine buckets
    int min_index, min_value, min_count;
    int max_index, max_value, max_count;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        min_index = min_count = min_value = BUCKET_SIZE + 1;
        max_index = max_count = max_value = -1;
        for (int j = 0; j < BUCKET_SIZE; j++) {
            if (buckets[j] < min_count) {
                min_count = buckets[j];
                min_index = j;
                min_value = i * BUCKET_SIZE + j;
            }
            if (buckets[j] > max_count) {
                max_count = buckets[j];
                max_index = j;
                max_value = i * BUCKET_SIZE + j;
            }
        }
        if (min_value!= BUCKET_SIZE + 1) {
            for (int k = 0; k < BUCKET_SIZE; k++) {
                if (buckets[k] == min_count) {
                    buckets[k] = max_count;
                    arr[min_index] = max_value;
                }
            }
        }
    }

    // Free memory
    free(buckets);
}

// Function to generate random array
int* generateRandomArray(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int* arr = generateRandomArray(n);
    sortArray(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    free(arr);
    return 0;
}