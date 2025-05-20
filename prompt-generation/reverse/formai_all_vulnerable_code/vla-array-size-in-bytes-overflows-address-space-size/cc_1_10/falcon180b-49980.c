//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define BUCKET_SIZE 10000

void bucketSort(int arr[], int n) {
    int i;
    int *bucket[BUCKET_SIZE];
    for (i = 0; i < BUCKET_SIZE; i++) {
        bucket[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }
    for (i = 0; i < n; i++) {
        int bucketIndex = arr[i] / BUCKET_SIZE;
        int j = 0;
        while (j < BUCKET_SIZE && bucket[bucketIndex][j]!= 0) {
            j++;
        }
        bucket[bucketIndex][j] = arr[i];
    }
    for (i = 0; i < n; i++) {
        int bucketIndex = arr[i] / BUCKET_SIZE;
        int j = 0;
        while (bucket[bucketIndex][j]!= arr[i]) {
            j++;
        }
        arr[i] = bucket[bucketIndex][j];
    }
    for (i = 0; i < BUCKET_SIZE; i++) {
        free(bucket[i]);
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    bucketSort(arr, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Time taken by bucket sort: %.3f seconds\n", cpu_time_used);
    return 0;
}