//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000

void bucket_sort(int arr[], int n) {
    int i, j, k, max_val, min_val;
    int *buckets[MAX_SIZE];
    int bucket_counts[MAX_SIZE];
    int *sorted_arr = malloc(n * sizeof(int));

    if (sorted_arr == NULL) {
        printf("Error: memory allocation failed.\n");
        exit(1);
    }

    max_val = arr[0];
    min_val = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    for (i = 0; i < MAX_SIZE; i++) {
        buckets[i] = NULL;
    }

    for (i = 0; i < n; i++) {
        j = (arr[i] - min_val) * MAX_SIZE / (max_val - min_val);
        if (buckets[j] == NULL) {
            buckets[j] = malloc(MAX_SIZE * sizeof(int));
            if (buckets[j] == NULL) {
                printf("Error: memory allocation failed.\n");
                exit(1);
            }
        }
        buckets[j] = realloc(buckets[j], (k + 1) * sizeof(int));
        buckets[j][k] = arr[i];
        bucket_counts[j]++;
    }

    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < bucket_counts[i]; j++) {
            sorted_arr[j] = buckets[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        arr[i] = sorted_arr[i];
    }

    free(sorted_arr);
}

int main() {
    int i, n;
    int *arr;

    srand(time(NULL));
    n = rand() % 1000 + 1;
    arr = malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Error: memory allocation failed.\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    printf("Before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n);

    printf("After sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}