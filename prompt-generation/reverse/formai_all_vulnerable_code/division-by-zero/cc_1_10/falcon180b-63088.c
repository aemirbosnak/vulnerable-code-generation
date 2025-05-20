//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void bucket_sort(int arr[], int n) {
    int i, j, k, max_val, min_val, range, bucket_size;
    int *bucket[MAX_SIZE];
    int count[MAX_SIZE] = {0};

    // Calculate range and bucket size
    max_val = arr[0];
    min_val = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
        else if (arr[i] < min_val)
            min_val = arr[i];
    }
    range = max_val - min_val + 1;
    bucket_size = range / n;

    // Create empty buckets
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *)malloc(bucket_size * sizeof(int));
        if (!bucket[i]) {
            printf("Memory error\n");
            exit(0);
        }
    }

    // Distribute elements into buckets
    for (i = 0; i < n; i++) {
        k = (arr[i] - min_val) / bucket_size;
        bucket[k] = (int *)realloc(bucket[k], (count[k] + 1) * sizeof(int));
        if (!bucket[k]) {
            printf("Memory error\n");
            exit(0);
        }
        bucket[k][count[k]] = arr[i];
        count[k]++;
    }

    // Concatenate sorted buckets
    j = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        for (k = 0; k < count[i]; k++) {
            arr[j++] = bucket[i][k];
        }
    }
}

int main() {
    int n, i;
    int arr[MAX_SIZE];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    srand(time(NULL));

    // Fill array with random integers
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("Unsorted array:\n");
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

    return 0;
}