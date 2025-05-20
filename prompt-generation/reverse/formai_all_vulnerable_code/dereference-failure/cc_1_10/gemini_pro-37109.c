//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: sophisticated
#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>

#define NUM_BUCKETS 10 // Can be adjusted

// Custom data type to represent values with their original indices
typedef struct {
    float value;
    int index;
} IndexValuePair;

// Function to sort values using bucket sort
void bucketSort(float *arr, int n) {
    // Create buckets
    IndexValuePair **buckets = malloc(NUM_BUCKETS * sizeof(IndexValuePair *));
    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = malloc(n * sizeof(IndexValuePair));
    }

    // Initialize all buckets to be empty
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < NUM_BUCKETS; j++) {
            buckets[j][i].value = FLT_MAX;
            buckets[j][i].index = -1;
        }
    }

    // Distribute values into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int) floor((arr[i] / (float) FLT_MAX) * NUM_BUCKETS);
        buckets[bucketIndex][i].value = arr[i];
        buckets[bucketIndex][i].index = i;
    }

    // Sort values within each bucket using insertion sort
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 1; j < n; j++) {
            IndexValuePair temp = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && temp.value < buckets[i][k].value) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = temp;
        }
    }

    // Concatenate sorted buckets into the original array
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 0; j < n; j++) {
            if (buckets[i][j].index != -1) {
                arr[index++] = buckets[i][j].value;
            }
        }
    }

    // Free memory
    for (int i = 0; i < NUM_BUCKETS; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

// Function to print an array
void printArray(float *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Initialize an array of values
    float arr[] = {0.897, 0.565, 0.656, 0.123, 0.343, 0.878, 0.234, 0.789, 0.987, 0.456};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}