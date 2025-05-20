//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int* bucketSort(int* arr, int size) {
    int i, j, n;
    int* buckets = (int*) malloc(MAX_SIZE * sizeof(int));
    int* sortedArr = (int*) malloc(size * sizeof(int));

    for (i = 0; i < MAX_SIZE; i++) {
        buckets[i] = -1;
    }

    for (i = 0; i < size; i++) {
        n = arr[i] * MAX_SIZE;
        if (buckets[n] == -1) {
            buckets[n] = i;
        } else {
            j = buckets[n];
            while (j!= -1) {
                j = (j + 1) % MAX_SIZE;
            }
            buckets[n] = j;
        }
    }

    for (i = 0; i < MAX_SIZE; i++) {
        if (buckets[i]!= -1) {
            sortedArr[i] = arr[buckets[i]];
        }
    }

    for (i = 0; i < size; i++) {
        arr[i] = sortedArr[i];
    }

    free(buckets);
    free(sortedArr);

    return arr;
}

int main() {
    int arr[] = { 9, 7, 3, 1, 5, 8, 6, 2, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int* sortedArr = bucketSort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArr[i]);
    }
    printf("\n");

    return 0;
}