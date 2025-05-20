//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucketSort(int arr[], int n) {
    int i, j, min, max, range;
    int *bucket[MAX_SIZE];

    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *)malloc(sizeof(int) * n);
    }

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100; // generate random numbers between 0 and 99
    }

    min = arr[0];
    max = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    range = max - min + 1;

    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / range * MAX_SIZE; // calculate the index of the bucket
        bucket[j] = realloc(bucket[j], sizeof(int) * (n + 1));
        bucket[j][n] = arr[i];
    }

    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", bucket[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        arr[i] = bucket[arr[i] - min][n - 1];
    }

    for (i = 0; i < MAX_SIZE; i++) {
        free(bucket[i]);
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    return 0;
}