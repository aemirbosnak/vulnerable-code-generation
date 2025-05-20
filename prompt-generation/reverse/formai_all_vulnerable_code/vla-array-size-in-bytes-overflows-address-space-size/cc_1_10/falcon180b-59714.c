//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define BUCKET_SIZE 10

typedef struct {
    int size;
    int *array;
} Bucket;

void createBuckets(Bucket *buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        buckets[i].size = 0;
        buckets[i].array = (int*)malloc(BUCKET_SIZE * sizeof(int));
    }
}

void destroyBuckets(Bucket *buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        free(buckets[i].array);
    }
}

void insertIntoSortedArray(int *array, int *sortedArray, int size) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        while (j >= 0 && sortedArray[j] > array[i]) {
            sortedArray[j+1] = sortedArray[j];
            j--;
        }
        sortedArray[j+1] = array[i];
        j++;
    }
}

void distributeIntoSortedArray(Bucket *buckets, int numBuckets, int *sortedArray) {
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            sortedArray[index++] = buckets[i].array[j];
        }
    }
}

void bucketSort(int *array, int size) {
    Bucket buckets[MAX_SIZE/BUCKET_SIZE];
    int numBuckets = size / BUCKET_SIZE;
    createBuckets(buckets, numBuckets);

    for (int i = 0; i < size; i++) {
        int bucketIndex = array[i] / BUCKET_SIZE;
        buckets[bucketIndex].array[buckets[bucketIndex].size++] = array[i];
    }

    int sortedArray[size];
    for (int i = 0; i < numBuckets; i++) {
        insertIntoSortedArray(buckets[i].array, sortedArray, buckets[i].size);
    }
    distributeIntoSortedArray(buckets, numBuckets, sortedArray);

    for (int i = 0; i < size; i++) {
        array[i] = sortedArray[i];
    }

    destroyBuckets(buckets, numBuckets);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *array = (int*)malloc(size * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000000;
    }

    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    bucketSort(array, size);

    printf("\nSorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    free(array);
    return 0;
}