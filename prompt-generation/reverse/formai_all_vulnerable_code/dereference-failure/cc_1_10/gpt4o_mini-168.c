//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Function to create a bucket
float* createBucket(int capacity) {
    return (float*)malloc(capacity * sizeof(float));
}

// Function to perform insertion sort on the bucket
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function for bucket sort
void bucketSort(float arr[], int n) {
    // Create an array of buckets
    int bucketCount = n;
    float** buckets = (float**)malloc(bucketCount * sizeof(float*));
    int* bucketSizes = (int*)malloc(bucketCount * sizeof(int));

    // Initialize each bucket
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = createBucket(n);
        bucketSizes[i] = 0;
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * bucketCount);
        if (bucketIndex >= bucketCount) {
            bucketIndex = bucketCount - 1;
        }
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Sort each bucket and merge
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    // Free memory for buckets
    for (int i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Function to print the array
void printArray(float arr[], int n) {
    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%0.2f ", arr[i]);
    }
    printf("\n");
}

// Function to fill the array with random floating-point numbers
void fillArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (float)rand() / (float)(RAND_MAX); // Random float between 0 and 1
    }
}

int main() {
    int n;
    printf("Welcome to the Peaceful Bucket Sort Program!\n");
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    // Check if the number is valid
    if(n <= 0) {
        printf("Let's keep it positive! Please enter a positive number.\n");
        return 1;
    }

    float* arr = (float*)malloc(n * sizeof(float));
    
    // Fill the array with random numbers
    fillArray(arr, n);

    printf("Unsorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%0.2f ", arr[i]);
    }
    printf("\n\n");

    // Peacefully sorting the array
    bucketSort(arr, n);

    // Printing the sorted array
    printArray(arr, n);

    // Release the allocated memory
    free(arr);
    printf("Sorting complete! May you find peace in the ordered numbers.\n");

    return 0;
}