//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX_BUCKETS 10
#define BUCKET_SIZE (1024 / sizeof(int))

typedef struct Bucket {
    int top;
    int* data;
} Bucket;

Bucket* buckets;

void init_buckets() {
    int i;
    buckets = (Bucket*)calloc(MAX_BUCKETS, sizeof(Bucket));
    for (i = 0; i < MAX_BUCKETS; i++) {
        buckets[i].top = -1;
        buckets[i].data = (int*)calloc(BUCKET_SIZE, sizeof(int));
    }
}

int hash_func(int key) {
    return abs(key % MAX_BUCKETS);
}

void free_buckets() {
    int i;
    for (i = 0; i < MAX_BUCKETS; i++) {
        free(buckets[i].data);
    }
    free(buckets);
}

void sort(int arr[], int n) {
    int i;
    init_buckets();
    for (i = 0; i < n; i++) {
        int index = hash_func(arr[i]);
        buckets[index].data[++buckets[index].top] = arr[i];
    }
    int j = 0;
    for (i = 0; i < MAX_BUCKETS; i++) {
        int k;
        if (buckets[i].top < 0) continue;
        for (k = 0; k <= buckets[i].top; k++) {
            arr[j++] = buckets[i].data[k];
        }
    }
}

void print_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 1, 6, 3, 9, 2, 5, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    clock_t start = clock();
    sort(arr, n);
    clock_t end = clock();
    printf("Sorted Array: ");
    print_array(arr, n);
    printf("Time taken: %f seconds\n", (float)(end - start) / CLOCKS_PER_SEC);
    free_buckets();
    return 0;
}