//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Function to create a bucket
void create_bucket(int* arr, int n, int* bucket) {
    int i, j;
    for (i = 0; i < n; i++) {
        bucket[arr[i]] = i;
    }
}

// Function to put elements in their respective buckets
void put_in_bucket(int* arr, int n, int* bucket) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                int temp_bucket = bucket[arr[i]];
                bucket[arr[i]] = bucket[arr[j]];
                bucket[arr[j]] = temp_bucket;
            }
        }
    }
}

// Function to put elements in their respective buckets and return the buckets
void create_and_put_in_bucket(int* arr, int n, int* bucket) {
    create_bucket(arr, n, bucket);
    put_in_bucket(arr, n, bucket);
}

// Function to sort elements in their respective buckets
void sort_buckets(int* arr, int n, int* bucket) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                int temp_bucket = bucket[arr[i]];
                bucket[arr[i]] = bucket[arr[j]];
                bucket[arr[j]] = temp_bucket;
            }
        }
    }
}

// Function to merge the buckets
void merge_buckets(int* arr, int n, int* bucket) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (bucket[j] == i) {
                arr[k++] = arr[j];
            }
        }
    }
    while (k < n) {
        arr[k++] = 0;
    }
}

// Function to sort elements in the array
void sort_array(int* arr, int n) {
    int* bucket = (int*)malloc(n * sizeof(int));
    create_and_put_in_bucket(arr, n, bucket);
    sort_buckets(arr, n, bucket);
    merge_buckets(arr, n, bucket);
    free(bucket);
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort_array(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}