//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to create buckets for the elements
void create_buckets(int* arr, int n, int* buckets, int bucket_size) {
    for (int i = 0; i < n; i++) {
        int index = arr[i] / bucket_size;
        buckets[index] += 1;
    }
}

// Function to count the elements in each bucket
void count_elements(int* arr, int n, int* buckets, int bucket_size) {
    for (int i = 0; i < bucket_size; i++) {
        buckets[i] += buckets[i] == 0? 1 : 0;
    }
}

// Function to sort the elements using bucket sort
void sort_elements(int* arr, int n, int* buckets, int bucket_size) {
    for (int i = 0; i < bucket_size; i++) {
        int* bucket_elements = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            if (arr[j] >= buckets[i] * bucket_size) {
                bucket_elements[buckets[i] - 1 - buckets[i] % bucket_size] = arr[j];
                buckets[i] += 1;
            }
        }
        for (int j = 0; j < n; j++) {
            arr[j] = bucket_elements[j];
        }
        free(bucket_elements);
    }
}

// Function to print the sorted array
void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(0));
    int n = 100;
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    int* buckets = malloc(n * sizeof(int));
    int bucket_size = 10;

    create_buckets(arr, n, buckets, bucket_size);
    count_elements(arr, n, buckets, bucket_size);
    sort_elements(arr, n, buckets, bucket_size);

    printf("Original array:\n");
    print_array(arr, n);

    printf("Sorted array using bucket sort:\n");
    print_array(arr, n);

    free(arr);
    free(buckets);

    return 0;
}