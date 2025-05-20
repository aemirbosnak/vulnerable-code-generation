//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} BucketNode;

void createBucket(BucketNode buckets[], int size) {
    for (int i = 0; i < size; i++) {
        buckets[i].data = 0;
        buckets[i].index = -1;
    }
}

void insertElement(BucketNode buckets[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (buckets[i].data == 0) {
            buckets[i].data = element;
            buckets[i].index = i;
            return;
        }
    }
}

void printBucket(BucketNode buckets[], int size) {
    for (int i = 0; i < size; i++) {
        if (buckets[i].data!= 0) {
            printf("%d ", buckets[i].data);
        } else {
            printf("-1 ");
        }
    }
    printf("\n");
}

void bucketSort(int arr[], int size) {
    BucketNode buckets[MAX_SIZE];
    createBucket(buckets, size);
    for (int i = 0; i < size; i++) {
        insertElement(buckets, size, arr[i]);
    }
    for (int i = 0; i < size; i++) {
        arr[i] = buckets[i].data;
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}