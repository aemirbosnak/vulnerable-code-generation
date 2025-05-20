//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Initialize random seed
    srand(time(NULL));

    // Generate random array of integers
    int arr_size = rand() % 50 + 1;
    int arr[arr_size];
    for (int i = 0; i < arr_size; i++) {
        arr[i] = rand() % 100;
    }

    // Print unsorted array
    printf("Unsorted array:\n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort array using bucket sort
    int max_val = arr[0];
    for (int i = 1; i < arr_size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int bucket_size = max_val / arr_size;
    int *buckets[arr_size];
    for (int i = 0; i < arr_size; i++) {
        buckets[i] = (int *)malloc(sizeof(int) * bucket_size);
    }

    for (int i = 0; i < arr_size; i++) {
        int bucket_idx = arr[i] / bucket_size;
        buckets[bucket_idx][arr[i] % bucket_size] = arr[i];
    }

    for (int i = 0; i < arr_size; i++) {
        for (int j = 0; j < bucket_size; j++) {
            arr[i * bucket_size + j] = buckets[i][j];
        }
    }

    // Print sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}