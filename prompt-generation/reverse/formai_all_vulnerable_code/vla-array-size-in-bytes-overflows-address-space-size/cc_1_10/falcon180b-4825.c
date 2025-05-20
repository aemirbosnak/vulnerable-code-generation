//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void bucketSort(int arr[], int size) {
    int i, j, max_val, min_val, range, bucket_size, *bucket[MAX_SIZE];
    int *temp_arr;

    max_val = arr[0];
    min_val = arr[0];

    for (i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        } else if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    range = max_val - min_val + 1;
    bucket_size = range / MAX_SIZE;

    temp_arr = (int *) malloc(size * sizeof(int));
    for (i = 0; i < size; i++) {
        temp_arr[i] = arr[i];
    }

    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *) malloc(size * sizeof(int));
    }

    for (i = 0; i < size; i++) {
        j = temp_arr[i] / bucket_size;
        bucket[j] = (int *) realloc(bucket[j], (j + 1) * sizeof(int));
        bucket[j][j] = temp_arr[i];
    }

    for (i = 0; i < size; i++) {
        arr[i] = bucket[temp_arr[i] / bucket_size][temp_arr[i] % bucket_size];
    }

    for (i = 0; i < MAX_SIZE; i++) {
        free(bucket[i]);
    }
    free(temp_arr);
}

int main() {
    int n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}