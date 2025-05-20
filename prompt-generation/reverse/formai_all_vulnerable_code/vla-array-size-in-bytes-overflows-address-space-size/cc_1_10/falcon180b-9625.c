//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void bucketSort(int arr[], int n) {
    int i, j, k;
    int *bucket[MAX_SIZE];
    int max = arr[0];
    int min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        } else if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int bucketSize = range / n;

    for (i = 0; i < n; i++) {
        bucket[i] = (int *) malloc(bucketSize * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < bucketSize; j++) {
            bucket[j][k] = 0;
        }
        k++;
    }

    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / bucketSize;
        bucket[j][k] = arr[i];
        k++;
    }

    i = 0;
    for (j = 0; j < n; j++) {
        for (k = 0; k < bucketSize; k++) {
            arr[i++] = bucket[j][k];
        }
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

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}