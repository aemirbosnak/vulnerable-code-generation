//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUCKETS 10

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    // Create buckets
    float **buckets = (float **)malloc(MAX_BUCKETS * sizeof(float *));
    int *bucketSizes = (int *)malloc(MAX_BUCKETS * sizeof(int));

    for (int i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float));
        bucketSizes[i] = 0;
    }

    // Distributing input array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * MAX_BUCKETS);
        if (bucketIndex >= MAX_BUCKETS) {
            bucketIndex = MAX_BUCKETS - 1; // Handle the case when arr[i] == 1
        }
        buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
        bucketSizes[bucketIndex]++;
    }

    // Sort individual buckets and concatenate
    int index = 0;
    for (int i = 0; i < MAX_BUCKETS; i++) {
        if (bucketSizes[i] > 0) {
            // Sort each bucket
            for (int j = 0; j < bucketSizes[i]; j++) {
                for (int k = 0; k < bucketSizes[i] - j - 1; k++) {
                    if (buckets[i][k] > buckets[i][k + 1]) {
                        // Swap
                        float temp = buckets[i][k];
                        buckets[i][k] = buckets[i][k + 1];
                        buckets[i][k + 1] = temp;
                    }
                }
            }
            // Add sorted bucket to output array
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    // Free allocated memory for buckets
    for (int i = 0; i < MAX_BUCKETS; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Function to print the array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// Main function to execute the bucket sort
int main() {
    int n;
    printf("Welcome to the Bucket Sort Program!\n");
    printf("Please enter the number of elements to sort: ");
    
    // Read number of elements
    scanf("%d", &n);
    float *arr = (float *)malloc(n * sizeof(float));
    
    // Read elements
    printf("Please enter %d numbers in the range [0, 1]:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // Display the unsorted array
    printf("Unsorted array:\n");
    printArray(arr, n);

    // Perform bucket sort
    bucketSort(arr, n);

    // Display the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    // Free allocated memory for the input array
    free(arr);
    
    printf("Thank you for using the program!\n");
    return 0;
}