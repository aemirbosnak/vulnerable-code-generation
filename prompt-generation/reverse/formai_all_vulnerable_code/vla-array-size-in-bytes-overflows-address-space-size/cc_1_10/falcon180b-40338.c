//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

void bucketSort(int arr[], int n) {
    int i, j, k, index;
    int *bucket[MAX_SIZE];

    for (i = 0; i < n; i++) {
        index = (int) (arr[i] * MAX_SIZE / (double) n);
        if (index == MAX_SIZE) {
            index = MAX_SIZE - 1;
        }
        if (bucket[index] == NULL) {
            bucket[index] = (int *) malloc(sizeof(int));
        }
        bucket[index] = realloc(bucket[index], sizeof(int) * (++k));
        bucket[index][k - 1] = arr[i];
    }

    for (i = 0; i < MAX_SIZE; i++) {
        if (bucket[i]!= NULL) {
            for (j = 0; j < k; j++) {
                arr[j * MAX_SIZE / n + i] = bucket[i][j];
            }
        }
    }
}

int main() {
    int i, n;
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