//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUCKETS 10
#define BUCKET_SIZE 50

// Custom Bucket Structure
typedef struct Bucket {
    int top;
    int capacity;
    int* data;
} Bucket;

// Function to create a new bucket
Bucket* createBucket() {
    Bucket* bucket = (Bucket*)malloc(sizeof(Bucket));
    bucket->capacity = BUCKET_SIZE;
    bucket->top = -1;
    bucket->data = (int*)calloc(BUCKET_SIZE, sizeof(int));
    return bucket;
}

// Function to resize a bucket
Bucket* resizeBucket(Bucket* bucket) {
    int* newData = (int*)realloc(bucket->data, (BUCKET_SIZE * 2) * sizeof(int));
    if (newData == NULL) {
        printf("Reallocation failed\n");
        free(bucket->data);
        free(bucket);
        return NULL;
    }
    bucket->capacity *= 2;
    bucket->data = newData;
    return bucket;
}

// Function to insert an element into a bucket
void insertIntoBucket(Bucket* bucket, int value) {
    if (bucket->top >= (bucket->capacity - 1)) {
        bucket = resizeBucket(bucket);
        if (bucket == NULL) {
            printf("Error: Could not resize bucket\n");
            return;
        }
    }
    bucket->data[++(bucket->top)] = value;
}

// Function to merge two buckets
void mergeBuckets(Bucket* bucket1, Bucket* bucket2) {
    int i = 0, j = 0, k = 0;

    while (i <= bucket1->top && j <= bucket2->top) {
        if (bucket1->data[i] <= bucket2->data[j]) {
            printf("%d ", bucket1->data[i]);
            i++;
        } else {
            printf("%d ", bucket2->data[j]);
            j++;
        }
    }

    while (i <= bucket1->top) {
        printf("%d ", bucket1->data[i]);
        i++;
    }

    while (j <= bucket2->top) {
        printf("%d ", bucket2->data[j]);
        j++;
    }
}

// Function to sort the elements using Bucket Sort
void bucketSort(int arr[], int size) {
    int i;
    Bucket* buckets[MAX_BUCKETS];

    for (i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = createBucket();
    }

    for (i = 0; i < size; i++) {
        int index = (arr[i] % (MAX_BUCKETS)) / (BUCKET_SIZE / 5);
        insertIntoBucket(buckets[index], arr[i]);
    }

    for (i = 0; i < MAX_BUCKETS; i++) {
        if (buckets[i]->top >= 0) {
            Bucket* temp = buckets[i];
            buckets[i] = buckets[i + 1];
            buckets[i + 1] = temp;
        }
    }

    for (i = 0; i < MAX_BUCKETS - 1; i++) {
        mergeBuckets(buckets[i], buckets[i + 1]);
        printf("\n");
    }

    mergeBuckets(buckets[i], NULL);

    for (int i = 0; i < MAX_BUCKETS; i++) {
        free(buckets[i]->data);
        free(buckets[i]);
    }
}

// Driver code
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    bucketSort(arr, n);

    printf("\nSorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}