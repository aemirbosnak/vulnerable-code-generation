//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shocked
// *** WARNING: This code is intentionally shocking and should not be used as a reference for good programming practices. It is provided for entertainment purposes only. ***

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void generate_random_array(int arr[], int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size) {
    int max_val = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int bucket_size = max_val / size;

    int **buckets = malloc(size * sizeof(int *));

    for (int i = 0; i < size; i++) {
        buckets[i] = malloc(bucket_size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / bucket_size;
        int bucket_offset = arr[i] % bucket_size;

        int *bucket = buckets[bucket_index];

        for (int j = 0; j < bucket_offset; j++) {
            bucket[j] = bucket[j + 1];
        }

        bucket[bucket_offset] = arr[i];
    }

    int index = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < bucket_size; j++) {
            if (buckets[i][j]!= 0) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

int main() {
    int size = MAX_SIZE;

    int *arr = malloc(size * sizeof(int));

    generate_random_array(arr, size);

    print_array(arr, size);

    bucket_sort(arr, size);

    print_array(arr, size);

    free(arr);

    return 0;
}