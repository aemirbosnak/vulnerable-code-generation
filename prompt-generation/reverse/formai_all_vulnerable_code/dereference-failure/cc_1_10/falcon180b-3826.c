//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000

void bucket_sort(int arr[], int n)
{
    int i, j, k, num_buckets, max_value, *count;
    int **bucket;

    max_value = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    num_buckets = max_value / 10 + 1;
    bucket = (int **)malloc(num_buckets * sizeof(int *));
    for (i = 0; i < num_buckets; i++) {
        bucket[i] = (int *)malloc(n * sizeof(int));
        count = bucket[i];
        for (j = 0; j < n; j++) {
            count[arr[j] / 10]++;
        }
        for (j = 1; j < 10; j++) {
            count[j] += count[j - 1];
        }
        for (j = n - 1; j >= 0; j--) {
            k = arr[j] / 10;
            bucket[k][--count[k]] = arr[j];
        }
    }

    for (i = 0; i < n; i++) {
        arr[i] = bucket[arr[i] / 10][--count[arr[i] / 10]];
    }

    for (i = 0; i < num_buckets; i++) {
        free(bucket[i]);
    }
    free(bucket);
}

int main()
{
    int n, i;
    int *arr;

    srand(time(NULL));
    n = rand() % MAX_SIZE + 1;
    arr = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX_VALUE;
    }

    printf("Original array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}