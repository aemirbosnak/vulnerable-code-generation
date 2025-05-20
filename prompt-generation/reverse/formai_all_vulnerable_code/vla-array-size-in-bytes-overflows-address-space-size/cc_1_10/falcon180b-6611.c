//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

int compareInt(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    if (x < y)
        return -1;
    else if (x > y)
        return 1;
    else
        return 0;
}

void bucketSort(int arr[], int n) {
    int i, j, k;
    int *bucket[MAX_SIZE];
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = NULL;
    }
    for (i = 0; i < n; i++) {
        k = arr[i] / (MAX_SIZE / n);
        bucket[k] = (int *)realloc(bucket[k], (k + 1) * sizeof(int));
        bucket[k][k] = arr[i];
    }
    for (i = 0; i < n; i++) {
        k = arr[i] / (MAX_SIZE / n);
        for (j = 0; j <= k; j++) {
            if (bucket[j]!= NULL && compareInt(bucket[j], &arr[i]) == 0) {
                break;
            }
        }
        if (j == k + 1) {
            bucket[k] = (int *)realloc(bucket[k], (k + 2) * sizeof(int));
            bucket[k][k + 1] = arr[i];
        }
    }
    int index = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        if (bucket[i]!= NULL) {
            for (j = 0; j <= k; j++) {
                arr[index++] = bucket[i][j];
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}