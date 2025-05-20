//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

/* Function to sort using Bucket Sort */
void bucketSort(float arr[], int n) {
    int i, j;
    float *bucket, max_val = arr[0], min_val = arr[0];

    /* Find the minimum and maximum values of the array */
    for(i = 1; i < n; i++) {
        if(arr[i] > max_val)
            max_val = arr[i];
        if(arr[i] < min_val)
            min_val = arr[i];
    }

    /* Compute the range of the values */
    float range = max_val - min_val;

    /* Create the buckets */
    int num_buckets = n;
    bucket = (float*) malloc(num_buckets * sizeof(float));
    for(i = 0; i < num_buckets; i++)
        bucket[i] = 0.0f;

    /* Distribute the elements into the buckets */
    for(i = 0; i < n; i++) {
        int bucket_idx = (int) ((arr[i] - min_val) / range * (num_buckets - 1));
        bucket[bucket_idx] = arr[i];
    }

    /* Sort each bucket using Insertion Sort */
    for(i = 0; i < num_buckets; i++) {
        float* bucket_i = bucket + i;
        for(j = 1; j < num_buckets; j++) {
            if(bucket_i[j] < bucket_i[j-1]) {
                float tmp = bucket_i[j];
                bucket_i[j] = bucket_i[j-1];
                bucket_i[j-1] = tmp;
            }
        }
    }

    /* Merge the sorted buckets */
    int idx = 0;
    for(i = 0; i < num_buckets; i++) {
        for(j = 0; j < num_buckets; j++) {
            if(bucket[j]) {
                arr[idx] = bucket[j];
                bucket[j] = 0.0f;
                idx++;
            }
        }
    }

    /* Free the memory used by the bucket array */
    free(bucket);
}

/* Function to print the sorted array */
void printArray(float arr[], int n) {
    printf("Sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%f ", arr[i]);
}

/* Main function */
int main() {
    float arr[] = {0.22, 0.45, 0.12, 1.0, 0.89, 0.77};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);
    printArray(arr, n);

    return 0;
}