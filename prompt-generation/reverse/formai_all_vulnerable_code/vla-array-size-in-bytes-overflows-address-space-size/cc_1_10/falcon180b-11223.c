//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void bucketSort(int arr[], int n) {
    int i, j, k;
    int *bucket[MAX_SIZE];
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *)malloc(sizeof(int) * n);
    }

    for (i = 0; i < n; i++) {
        k = arr[i] * MAX_SIZE / (n - 1);
        bucket[k] = (int *)realloc(bucket[k], sizeof(int) * (n - i + 1));
        bucket[k][k - arr[i]] = arr[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (bucket[j][i]!= 0) {
                arr[i] = bucket[j][i];
                break;
            }
        }
    }

    for (i = 0; i < MAX_SIZE; i++) {
        free(bucket[i]);
    }
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

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}