//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucketSort(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int bucket_size = max / n;
    int **buckets = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        buckets[i] = (int *)malloc((max + 1) * sizeof(int));
        for (int j = 0; j <= max; j++) {
            buckets[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] >= i * bucket_size && arr[j] < (i + 1) * bucket_size) {
                buckets[i][arr[j]]++;
            }
        }
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= max; j++) {
            while (buckets[i][j] > 0) {
                arr[k++] = j;
                buckets[i][j]--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start = clock();
    bucketSort(arr, n);
    clock_t end = clock();
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %lf seconds\n", time_taken);
    return 0;
}