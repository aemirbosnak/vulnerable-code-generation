//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void bucket_sort(int arr[], int n) {
    int i, j, k;
    int *buckets[BUCKET_SIZE];
    for (i = 0; i < BUCKET_SIZE; ++i) {
        buckets[i] = (int *) malloc(sizeof(int));
    }
    for (i = 0; i < n; ++i) {
        int bucket_idx = (arr[i] / BUCKET_SIZE);
        int *bucket = buckets[bucket_idx];
        int last_idx = bucket[0];
        bucket[last_idx + 1] = arr[i];
        bucket[0]++;
    }
    for (i = 0; i < BUCKET_SIZE; ++i) {
        int *bucket = buckets[i];
        for (j = 1; j <= bucket[0]; ++j) {
            int key = bucket[j];
            k = j - 1;
            while(k >= 1 && bucket[k] > key) {
                bucket[k+1] = bucket[k];
                k--;
            }
            bucket[k+1] = key;
        }
    }
    for (i = 0, k = 0; i < BUCKET_SIZE; ++i) {
        int *bucket = buckets[i];
        for (j = 1; j <= bucket[0]; ++j) {
            arr[k++] = bucket[j];
        }
        free(bucket);
    }
}

int main() {
    int n, i;
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    printf("Original array:\n");
    for (i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    bucket_sort(arr, n);
    printf("\nSorted array:\n");
    for (i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}