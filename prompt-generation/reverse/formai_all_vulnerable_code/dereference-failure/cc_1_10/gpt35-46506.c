//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10 // size of input array
#define BUCKET_SIZE 5 // size of each bucket

// function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// function to perform bucket sort
void bucketSort(int arr[], int n) {
    // create n/bucket_size empty buckets
    int bucket_count = (n / BUCKET_SIZE) + 1;
    int buckets[bucket_count][BUCKET_SIZE];
    int bucket_indexes[bucket_count];

    // initialize all buckets as empty
    for (int i = 0; i < bucket_count; i++) {
        bucket_indexes[i] = 0;
    }

    // put elements in the appropriate buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / BUCKET_SIZE;
        int bucket_pos = bucket_indexes[bucket_index];

        buckets[bucket_index][bucket_pos] = arr[i];
        bucket_indexes[bucket_index]++;

        // if bucket is full, sort it using insertion sort
        if (bucket_indexes[bucket_index] == BUCKET_SIZE) {
            insertionSort(buckets[bucket_index], BUCKET_SIZE);
        }
    }

    // merge all the sorted buckets
    int output_index = 0;
    for (int i = 0; i < bucket_count; i++) {
        int bucket_pos = bucket_indexes[i];

        // if bucket is not empty, copy its content to the output array
        if (bucket_pos > 0) {
            for (int j = 0; j < bucket_pos; j++) {
                arr[output_index] = buckets[i][j];
                output_index++;
            }
        }
    }
}

// function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// main function
int main() {
    int arr[SIZE] = { 22, 45, 12, 8, 10, 6, 72, 81, 33, 18 };
    printf("Input array: ");
    printArray(arr, SIZE);

    bucketSort(arr, SIZE);

    printf("Sorted array: ");
    printArray(arr, SIZE);

    return 0;
}