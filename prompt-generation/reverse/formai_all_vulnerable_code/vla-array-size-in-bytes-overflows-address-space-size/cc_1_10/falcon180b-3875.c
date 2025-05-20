//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bucketSort(int arr[], int n) {
    int i, j;
    int max = arr[0];
    int min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }

    int range = max - min + 1;
    int* bucket = (int*) malloc(range * sizeof(int));

    for (i = 0; i < range; i++)
        bucket[i] = 0;

    for (i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }

    int k = 0;
    for (i = 0; i < range; i++) {
        for (j = 0; j < bucket[i]; j++) {
            arr[k++] = i + min;
        }
    }

    free(bucket);
}

int main() {
    int i, n;
    srand(time(NULL));
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX;
    }

    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}