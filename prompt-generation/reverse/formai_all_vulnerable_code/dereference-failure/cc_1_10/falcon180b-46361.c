//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: modular
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bucketSort(int arr[], int n) {
    int i, j, max = arr[0], min = arr[0], range, bucket[MAX];

    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }

    range = max - min + 1;
    for (i = 0; i < range; i++)
        bucket[i] = 0;

    for (i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }

    for (i = 1; i < range; i++)
        bucket[i] += bucket[i - 1];

    for (i = n - 1; i >= 0; i--) {
        j = arr[i] - min;
        bucket[j]--;
        arr[bucket[j]] = arr[i];
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}