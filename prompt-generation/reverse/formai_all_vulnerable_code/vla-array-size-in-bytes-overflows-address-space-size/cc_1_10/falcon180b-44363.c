//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    int data;
    int index;
} BucketElement;

void bucketSort(int arr[], int n) {
    int i, j, max = arr[0], min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }
    int range = max - min + 1;
    BucketElement *bucket[range];
    for (i = 0; i < range; i++) {
        bucket[i] = (BucketElement *)malloc(sizeof(BucketElement) * n);
        memset(bucket[i], 0, sizeof(BucketElement) * n);
    }
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / (max - min) * range;
        bucket[j]->data = arr[i];
        bucket[j]->index = i;
    }
    int k = 0;
    for (i = 0; i < range; i++) {
        for (j = 0; j < bucket[i]->data; j++) {
            arr[k++] = bucket[i]->index;
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}