//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define RANGE 1000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(int arr[], int n) {
    int i, j, k, max, min;
    int *bucket[MAX];

    for (i = 0; i < MAX; i++) {
        bucket[i] = (int *) malloc(n * sizeof(int));
        if (bucket[i] == NULL) {
            printf("Memory error\n");
            exit(0);
        }
    }

    for (i = 0; i < n; i++) {
        arr[i] = rand() % RANGE;
    }

    max = arr[0];
    min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < n; j++) {
            if (arr[j] >= i * (max - min) / MAX && arr[j] < (i + 1) * (max - min) / MAX) {
                bucket[i][k++] = arr[j];
            }
        }
    }

    for (i = 0; i < n; i++) {
        arr[i] = bucket[arr[i] / (max - min) * MAX][--k];
    }

    for (i = 0; i < MAX; i++) {
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

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}