//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n) {
    int max_value = arr[0];
    int min_value = arr[0];
    for (int i = 1; i < n; i++) { // find the maximum and minimum value in the array
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
    }
    int bucket_size = 10; // size of each bucket
    int num_buckets = (max_value - min_value) / bucket_size + 1; // calculate the number of buckets

    int **buckets = (int **) malloc(num_buckets * sizeof(int *)); // create buckets array
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = (int *) malloc(n * sizeof(int));
    }

    int *bucket_count = (int *) calloc(num_buckets, sizeof(int)); // create bucket count array

    for (int i = 0; i < n; i++) {
        int bucket_index = (arr[i] - min_value) / bucket_size;
        buckets[bucket_index][bucket_count[bucket_index]] = arr[i];
        bucket_count[bucket_index]++;
    }

    for (int i = 0; i < num_buckets; i++) { // sort each bucket
        for (int j = 0; j < bucket_count[i] - 1; j++) {
            for (int k = 0; k < bucket_count[i] - j - 1; k++) {
                if (buckets[i][k] > buckets[i][k + 1]) {
                    int temp = buckets[i][k];
                    buckets[i][k] = buckets[i][k + 1];
                    buckets[i][k + 1] = temp;
                }
            }
        }
    }

    int index = 0;
    for (int i = 0; i < num_buckets; i++) { // concatenate the sorted buckets into the original array
        for (int j = 0; j < bucket_count[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }

    for (int i = 0; i < num_buckets; i++) { // free memory
        free(buckets[i]);
    }
    free(buckets);
    free(bucket_count);
}

int main() {
    int arr[] = {35, 23, 87, 77, 12, 98, 33, 47, 52, 62};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}