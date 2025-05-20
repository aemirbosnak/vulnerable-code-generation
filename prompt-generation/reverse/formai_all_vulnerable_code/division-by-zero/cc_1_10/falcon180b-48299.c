//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void bucketSort(int arr[], int n) {
    int i, j, maxVal, minVal;
    int *bucket[MAX_SIZE];

    for (i = 0; i < n; i++) {
        if (arr[i] < 0) {
            arr[i] = -arr[i];
        }
    }

    maxVal = arr[0];
    minVal = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }

    for (i = 0; i < n; i++) {
        if (arr[i] < 0) {
            arr[i] = -arr[i];
        }
    }

    for (i = 0; i < n; i++) {
        bucket[arr[i] / (maxVal / MAX_SIZE)] = &arr[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr[j] == i) {
                arr[j] = *(int *) bucket[i];
                break;
            }
        }
    }
}

int main() {
    int arr[] = { -3, -1, 4, 1, -5, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("After Sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}