//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// function to perform bucket sort
void bucketSort(float arr[], int n) {
    // Create n buckets
    int i, j;
    int count[n];
    for (i = 0; i < n; i++) {
        count[i] = 0;
    }
    // Initialize all buckets to empty
    float* bucket[n];
    for (i = 0; i < n; i++) {
        bucket[i] = NULL;
    }

    // Assign elements to the respective bucket
    for (i = 0; i < n; i++) {
        int bucket_idx = arr[i] * n;
        bucket[bucket_idx] = (float*) realloc(bucket[bucket_idx], ++count[bucket_idx] * sizeof(float));
        bucket[bucket_idx][count[bucket_idx]-1] = arr[i];
    }

    // Sort individual buckets using insertion sort
    for (i = 0; i < n; i++) {
        for (j = 1; j < count[i]; j++) {
            float temp = bucket[i][j];
            int k = j - 1;
            while (k >= 0 && bucket[i][k] > temp) {
                bucket[i][k+1] = bucket[i][k];
                k--;
            }
            bucket[i][k+1] = temp;
        }
    }

    // Concatenate all the sorted sub arrays
    int index = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[index++] = bucket[i][j];
        }
    }
}

// main function
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements:\n");
    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}