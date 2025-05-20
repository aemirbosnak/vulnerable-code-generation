//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 10

typedef struct {
    int bottom;
    int top;
    int data[BUCKET_SIZE];
} Bucket;

void bucketSort(int arr[], int left, int right, Bucket buckets[]) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        bucketSort(arr, left, mid, buckets);
        bucketSort(arr, mid + 1, right, buckets);

        int i = left;
        int j = 0;
        for (int index = left; index <= right; index++) {
            if (arr[index] < buckets[j].top) {
                buckets[j].data[buckets[j].bottom++] = arr[index];
            } else {
                j++;
            }
        }

        int k = 0;
        for (int i = 0; i < j; i++) {
            arr[left + k++] = buckets[i].data[buckets[i].bottom--];
        }

        for (int index = left; index <= right; index++) {
            buckets[index / (BUCKET_SIZE / 2)].top = arr[index] > buckets[index / (BUCKET_SIZE / 2)].top ? arr[index] : buckets[index / (BUCKET_SIZE / 2)].top;
        }
    }
}

int main() {
    int arr[] = {2, 5, 8, 3, 1, 9, 6, 4, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    Bucket buckets[size / (BUCKET_SIZE / 2)];
    memset(buckets, 0, sizeof(Bucket) * (size / (BUCKET_SIZE / 2)));

    bucketSort(arr, 0, size - 1, buckets);

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}