//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

void bucket_sort(int arr[], int n) {
    int i, j, k, max_val, min_val, range, *bucket[MAX_SIZE];
    int *temp_arr = (int *) malloc(n * sizeof(int));
    clock_t start, end;
    float cpu_time_used;

    start = clock();

    // Find range of elements in array
    max_val = arr[0];
    min_val = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        } else if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    range = max_val - min_val + 1;

    // Create empty buckets
    for (i = 0; i < range; i++) {
        bucket[i] = NULL;
    }

    // Place elements in appropriate buckets
    for (i = 0; i < n; i++) {
        j = (arr[i] - min_val) * range / (max_val - min_val);
        if (bucket[j] == NULL) {
            bucket[j] = (int *) malloc(n * sizeof(int));
        }
        bucket[j][k++] = arr[i];
    }

    // Concatenate sorted buckets back into original array
    for (i = 0; i < range; i++) {
        if (bucket[i]!= NULL) {
            for (j = 0; j < k; j++) {
                temp_arr[j] = bucket[i][j];
            }
            k += j;
        }
    }

    for (i = 0; i < n; i++) {
        arr[i] = temp_arr[i];
    }

    end = clock();
    cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;

    printf("Bucket Sort completed in %f seconds.\n", cpu_time_used);
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}