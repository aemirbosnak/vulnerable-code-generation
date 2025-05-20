//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int bucketSize = max / n;
    int *buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = (int *)malloc(bucketSize * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] >= i * bucketSize && arr[j] < (i + 1) * bucketSize) {
                int k = 0;
                while (buckets[i][k]!= -1) {
                    k++;
                }
                buckets[i][k] = arr[j];
            }
        }
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSize; j++) {
            if (buckets[i][j]!= -1) {
                arr[index++] = buckets[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}