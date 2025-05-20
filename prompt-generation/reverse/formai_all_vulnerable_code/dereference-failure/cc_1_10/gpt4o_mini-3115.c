//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUCKET_SIZE 10

// Function to perform bucket sort on an array
void bucketSort(float arr[], int n) {
    // Creating buckets
    int i, j;
    float **buckets = malloc(BUCKET_SIZE * sizeof(float *));
    int *bucketCounts = calloc(BUCKET_SIZE, sizeof(int));

    // Initialize each bucket dynamically
    for (i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = malloc(n * sizeof(float));
    }

    // Distributing input array elements into buckets
    for (i = 0; i < n; i++) {
        int index = (int)(arr[i] * BUCKET_SIZE);
        if (index >= BUCKET_SIZE) {
            index = BUCKET_SIZE - 1; // Handle overflow
        }
        buckets[index][bucketCounts[index]++] = arr[i];
    }

    // Sorting individual buckets and merging them
    int sortedIndex = 0;
    for (i = 0; i < BUCKET_SIZE; i++) {
        if (bucketCounts[i] > 0) {
            // Insertion sort for the individual bucket
            for (j = 1; j < bucketCounts[i]; j++) {
                float key = buckets[i][j];
                int k = j - 1;

                // Move elements of buckets[i][0..j-1] that are greater than key
                while (k >= 0 && buckets[i][k] > key) {
                    buckets[i][k + 1] = buckets[i][k];
                    k--;
                }
                buckets[i][k + 1] = key;
            }
            // Merging sorted bucket into the final array
            for (j = 0; j < bucketCounts[i]; j++) {
                arr[sortedIndex++] = buckets[i][j];
            }
        }
    }

    // Free allocated memory
    for (i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketCounts);
}

// Function to generate random floating-point numbers
void generateRandomArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (float)rand() / RAND_MAX; // Random float between 0 and 1
    }
}

// Function to print the array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    srand(time(NULL)); // Seed for random number generation

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamic memory allocation for the array
    float *arr = malloc(n * sizeof(float));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Generate random array
    generateRandomArray(arr, n);
    
    printf("Unsorted array:\n");
    printArray(arr, n);
    
    // Perform bucket sort
    bucketSort(arr, n);
    
    printf("Sorted array:\n");
    printArray(arr, n);

    // Clean up
    free(arr);
    
    return 0;
}