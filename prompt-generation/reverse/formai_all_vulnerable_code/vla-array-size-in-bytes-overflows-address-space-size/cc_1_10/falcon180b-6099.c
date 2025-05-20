//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucketSort(int arr[], int n) {
    int i, j, k, max, min;
    int *bucket[n];
    int count[n];

    for (i = 0; i < n; i++) {
        bucket[i] = (int *)malloc(n * sizeof(int));
        count[i] = 0;
    }

    max = arr[0];
    min = arr[0];

    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }

        if (arr[i] < min) {
            min = arr[i];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            k = (arr[i] - min) * n / (max - min);

            if (k == n) {
                k--;
            }

            bucket[k] = (int *)realloc(bucket[k], (count[k] + 1) * sizeof(int));
            bucket[k][count[k]] = arr[i];
            count[k]++;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[j * n + i] = bucket[i][j];
        }
    }

    for (i = 0; i < n; i++) {
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

    clock_t start = clock();
    bucketSort(arr, n);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("The sorted array is:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nTime taken: %.6f seconds", time_taken);

    return 0;
}