//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucketSort(int *arr, int n, int numOfBuckets) {
    int i,j;
    int *count;
    int **buckets;

    count = (int*) calloc(numOfBuckets, sizeof(int));
    buckets = (int**) calloc(numOfBuckets, sizeof(int*));
    for (i = 0; i < numOfBuckets; i++) {
        buckets[i] = (int*) calloc(n, sizeof(int));
    }

    for (i = 0; i < n; i++) {
        int bucketNum = arr[i] / numOfBuckets;
        buckets[bucketNum][count[bucketNum]++] = arr[i];
    }

    for (i = 0; i < numOfBuckets; i++) {
        int bucketSize = count[i];
        int *tempBucket = buckets[i];
        for (j = 1; j < bucketSize; j++) {
            int k = tempBucket[j];
            int l = j - 1;
            while (l >= 0 && tempBucket[l] > k) {
                tempBucket[l+1] = tempBucket[l];
                l--;
            }
            tempBucket[l+1] = k;
        }
    }

    int index = 0;
    for (i = 0; i < numOfBuckets; i++) {
        int bucketSize = count[i];
        int *tempBucket = buckets[i];
        for (j = 0; j < bucketSize; j++) {
            arr[index++] = tempBucket[j];
        }
    }

    for (i = 0; i < numOfBuckets; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(count);
}

int main() {
    int i, n, range;
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int*) calloc(n, sizeof(int));
    printf("Enter the range of elements: ");
    scanf("%d", &range);

    // Seed the random number generator
    time_t t;
    srand((unsigned) time(&t));

    // Generate the random array
    for (i = 0; i < n; i++) {
        arr[i] = rand() % range;
    }

    printf("Before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n, 5);

    printf("\nAfter sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}