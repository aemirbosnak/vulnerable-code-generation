//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return (x - y);
}

void bucketSort(int arr[], int n) {
    int i, j, k, max, min;
    int *bucket[MAX_SIZE];

    for (i = 0; i < MAX_SIZE; i++)
        bucket[i] = NULL;

    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    for (i = 0; i < n; i++) {
        k = (int)((arr[i] - min) * MAX_SIZE / (max - min));
        if (bucket[k] == NULL) {
            bucket[k] = (int *)malloc(sizeof(int));
            *(int *)bucket[k] = arr[i];
        } else {
            bucket[k] = (int *)realloc(bucket[k], sizeof(int) * (j + 1));
            *(int *)bucket[k] = arr[i];
        }
    }

    i = 0;
    for (j = 0; j < MAX_SIZE; j++) {
        if (bucket[j]!= NULL) {
            for (k = 0; k < *(int *)bucket[j]; k++) {
                arr[i++] = *(int *)bucket[j] + k;
            }
            free(bucket[j]);
            bucket[j] = NULL;
        }
    }
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}