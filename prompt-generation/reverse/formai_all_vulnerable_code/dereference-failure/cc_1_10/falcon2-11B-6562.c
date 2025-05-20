//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a bucket
struct Bucket {
    int start;
    int end;
    int size;
    int *arr;
};

// Function to create a bucket
struct Bucket* create_bucket(int n) {
    struct Bucket *b = malloc(sizeof(struct Bucket));
    b->start = 0;
    b->end = n;
    b->size = 1;
    b->arr = malloc(n * sizeof(int));
    return b;
}

// Function to sort the array using bucket sort
void bucket_sort(int arr[], int n) {
    // Create buckets
    struct Bucket *buckets[n];
    int i;
    for (i = 0; i < n; i++)
        buckets[i] = create_bucket(n);

    // Count the number of elements in each bucket
    int *counts = malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        counts[i] = 0;
    for (int j = 0; j < n; j++)
        counts[arr[j]]++;

    // Merge the buckets
    for (i = 0; i < n; i++) {
        if (buckets[i]->start == buckets[i]->end)
            continue;
        int k = 0;
        for (int j = buckets[i]->start; j < buckets[i]->end; j++)
            arr[k++] = buckets[i]->arr[j];
        free(buckets[i]->arr);
        buckets[i]->arr = arr;
        buckets[i]->start = 0;
        buckets[i]->end = k;
        buckets[i]->size = 1;
        for (int j = 0; j < n; j++)
            if (arr[j] == buckets[i]->arr[0])
                counts[j]++;
        for (int j = 1; j < buckets[i]->size; j++)
            counts[buckets[i]->arr[j]]++;
        for (int j = 0; j < buckets[i]->size; j++)
            arr[j] = buckets[i]->arr[j];
        free(buckets[i]);
    }

    // Free memory
    free(counts);
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 3, 4, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucket_sort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}