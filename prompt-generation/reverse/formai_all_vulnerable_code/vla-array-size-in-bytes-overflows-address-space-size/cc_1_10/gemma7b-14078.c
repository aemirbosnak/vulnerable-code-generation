//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int **arr, int n, int k) {
    int i, j, x, bucket[k], *temp = NULL;

    temp = (int *)malloc(n * sizeof(int));

    for (i = 0; i < k; i++)
        bucket[i] = 0;

    for (i = 0; i < n; i++) {
        x = arr[i];
        bucket[x]++;
    }

    for (i = 1; i < k; i++)
        bucket[i] += bucket[i - 1];

    for (i = n - 1; i >= 0; i--) {
        x = arr[i];
        temp[bucket[x] - 1] = arr[i];
        bucket[x]--;
    }

    free(temp);

    for (i = 0; i < n; i++)
        arr[i] = temp[i];
}

int main() {
    int n, k, i, *arr;

    scanf("Enter the number of elements: ", &n);
    scanf("Enter the number of buckets: ", &k);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d ", &arr[i]);

    bucketSort(arr, n, k);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}