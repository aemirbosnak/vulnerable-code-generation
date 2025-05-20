//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000
#define MAX_RANGE 1000000

int *generate_array(int size, int range) {
    int *arr = (int *)malloc(size * sizeof(int));
    int i;

    for (i = 0; i < size; i++) {
        arr[i] = rand() % range;
    }

    return arr;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bucket_sort(int *arr, int size, int max_range) {
    int i, j, *bucket[MAX_RANGE];

    for (i = 0; i < MAX_RANGE; i++) {
        bucket[i] = (int *)malloc(size * sizeof(int));
    }

    for (i = 0; i < size; i++) {
        int index = arr[i] / max_range * MAX_RANGE;
        bucket[index] = realloc(bucket[index], (index + 1) * sizeof(int));
        bucket[index][index] = arr[i];
    }

    for (i = 0; i < MAX_RANGE; i++) {
        for (j = 0; j < size; j++) {
            if (bucket[i][j]!= 0) {
                arr[j] = bucket[i][j];
            }
        }
    }

    for (i = 0; i < MAX_RANGE; i++) {
        free(bucket[i]);
    }
}

void print_array(int *arr, int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {
    int size = 100000, max_range = 1000000;
    int *arr = generate_array(size, max_range);

    printf("Unsorted array:\n");
    print_array(arr, size);

    clock_t start = clock();
    bucket_sort(arr, size, max_range);
    clock_t end = clock();

    printf("Sorted array:\n");
    print_array(arr, size);

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Elapsed time: %lf seconds\n", elapsed_time);

    return 0;
}