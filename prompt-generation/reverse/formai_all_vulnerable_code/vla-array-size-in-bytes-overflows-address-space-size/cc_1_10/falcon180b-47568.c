//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(int arr[], int n) {
    int i, j, max = arr[0], min = arr[0], range, bucket[MAX_SIZE];
    int* tempArr = (int*) malloc(n * sizeof(int));
    if (tempArr == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    for (i = 0; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    range = max - min + 1;
    for (i = 0; i < n; i++) {
        tempArr[i] = (arr[i] - min) * MAX_SIZE / range;
    }
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = 0;
    }
    for (i = 0; i < n; i++) {
        bucket[tempArr[i]]++;
    }
    for (i = 1; i < MAX_SIZE; i++) {
        bucket[i] += bucket[i - 1];
    }
    for (i = n - 1; i >= 0; i--) {
        tempArr[bucket[tempArr[i]] - 1] = arr[i];
        bucket[tempArr[i]]--;
    }
    for (i = 0; i < n; i++) {
        arr[i] = tempArr[i];
    }
    free(tempArr);
}

int main() {
    int i, n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    srand(time(NULL));
    printf("Before sorting:\n");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX_RANGE;
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, n);
    printf("After sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}