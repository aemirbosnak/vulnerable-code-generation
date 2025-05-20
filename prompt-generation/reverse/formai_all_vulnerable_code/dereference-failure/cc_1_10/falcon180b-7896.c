//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000 // Maximum size of the array
#define MAX_VALUE 100000 // Maximum value of each element in the array
#define NUM_BUCKETS 10000 // Number of buckets in the bucket sort algorithm

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void create_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand_int(1, MAX_VALUE);
    }
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int *arr, int size) {
    int *buckets = malloc(NUM_BUCKETS * sizeof(int));
    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / (MAX_VALUE / NUM_BUCKETS);
        buckets[bucket_index]++;
    }

    for (int i = 1; i < NUM_BUCKETS; i++) {
        buckets[i] += buckets[i - 1];
    }

    int *sorted_arr = malloc(size * sizeof(int));
    for (int i = size - 1; i >= 0; i--) {
        int bucket_index = arr[i] / (MAX_VALUE / NUM_BUCKETS);
        sorted_arr[--buckets[bucket_index]] = arr[i];
    }

    for (int i = 0; i < size; i++) {
        arr[i] = sorted_arr[i];
    }

    free(buckets);
    free(sorted_arr);
}

int main() {
    srand(time(NULL));

    int size = rand_int(1, MAX_SIZE);
    int *arr = malloc(size * sizeof(int));

    printf("Original array:\n");
    create_array(arr, size);
    print_array(arr, size);

    printf("Sorted array:\n");
    bucket_sort(arr, size);
    print_array(arr, size);

    free(arr);

    return 0;
}