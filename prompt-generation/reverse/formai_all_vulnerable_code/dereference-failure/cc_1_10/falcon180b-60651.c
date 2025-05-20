//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

typedef struct {
    int key;
    int index;
} Bucket;

void createBuckets(Bucket* buckets, int size) {
    for (int i = 0; i < size; i++) {
        buckets[i].index = -1;
    }
}

void insertBucket(Bucket* buckets, int* arr, int size, int range) {
    for (int i = 0; i < size; i++) {
        int index = arr[i] / range;
        if (buckets[index].index == -1) {
            buckets[index].index = i;
        } else {
            int j = buckets[index].index;
            while (j >= 0) {
                if (arr[j] < arr[i]) {
                    buckets[index].index = j;
                    break;
                }
                j--;
            }
        }
    }
}

void sortBucket(Bucket* buckets, int* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (buckets[i].index!= -1) {
            int j = buckets[i].index;
            arr[j] = arr[i];
            buckets[i].index = -1;
        }
    }
}

void bucketSort(int* arr, int size, int range) {
    Bucket* buckets = (Bucket*)malloc(MAX_SIZE * sizeof(Bucket));
    createBuckets(buckets, MAX_SIZE);
    insertBucket(buckets, arr, size, range);
    sortBucket(buckets, arr, size);
}

int main() {
    srand(time(NULL));
    int size = rand() % MAX_SIZE + 1;
    int range = rand() % MAX_RANGE + 1;
    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % range;
    }
    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, size, range);
    printf("After sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}