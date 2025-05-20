//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000000

int *bucket_sort(int *arr, int n) {
    int min = arr[0], max = arr[0], range = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    range = max - min + 1;
    int *bucket = (int *)malloc(range * sizeof(int));
    for (int i = 0; i < range; i++) {
        bucket[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }
    int *sorted = (int *)malloc((n + range) * sizeof(int));
    sorted[0] = min;
    for (int i = 1; i < range; i++) {
        sorted[i] = min + i;
    }
    int k = 0;
    for (int i = 0; i < range; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            sorted[k++] = i + min;
        }
    }
    for (int i = 0; i < n; i++) {
        sorted[k++] = arr[i];
    }
    free(bucket);
    return sorted;
}

int main() {
    srand(time(NULL));
    int *arr = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 1000000;
    }
    int *sorted = bucket_sort(arr, N);
    printf("Sorted array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");
    free(arr);
    free(sorted);
    return 0;
}