//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

void bucketSort(int arr[], int n) {
    int maxVal = arr[0], minVal = arr[0];
    int range, i;
    for (i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    range = maxVal - minVal + 1;
    int *bucket = (int *) malloc(range * sizeof(int));
    for (i = 0; i < range; i++) {
        bucket[i] = 0;
    }
    for (i = 0; i < n; i++) {
        bucket[arr[i] - minVal]++;
    }
    for (i = 0; i < n; i++) {
        arr[i] = minVal + bucket[arr[i] - minVal] - 1;
        bucket[arr[i] - minVal]--;
    }
}

int main() {
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start = clock();
    bucketSort(arr, n);
    clock_t end = clock();
    double elapsedTime = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Time taken: %.6f seconds\n", elapsedTime);
    return 0;
}