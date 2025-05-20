//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Bucket;

void bucketSort(Bucket *arr, int n) {
    int i, j, k;
    int nBuckets = n / 10;
    Bucket *buckets[nBuckets];

    for (i = 0; i < nBuckets; i++) {
        buckets[i] = (Bucket *) malloc(sizeof(Bucket));
    }

    for (i = 0; i < n; i++) {
        k = arr[i].data / nBuckets;
        buckets[k]->index = i;
    }

    for (i = 0; i < nBuckets; i++) {
        k = i * 10;
        for (j = 0; j < 10; j++) {
            if (buckets[i]->index == -1) {
                break;
            }

            int temp = k + j;
            int tempIndex = buckets[i]->index;

            if (arr[tempIndex].data < temp) {
                k = tempIndex;
            } else {
                buckets[i]->index = tempIndex;
            }

            arr[k] = arr[tempIndex];
            buckets[i]->index = tempIndex;
        }
    }

    free(buckets);
}

int main() {
    int n, i;
    Bucket *arr;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr = (Bucket *) malloc(sizeof(Bucket) * n);

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        arr[i].data = rand() % 100;
        arr[i].index = i;
    }

    printf("Before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i].data);
    }

    bucketSort(arr, n);

    printf("\nAfter sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i].data);
    }

    return 0;
}