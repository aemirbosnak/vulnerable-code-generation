//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucketSort(int arr[], int n);

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int *bucket = (int *) malloc(range * sizeof(int));

    for (int i = 0; i < n; i++) {
        int index = (arr[i] - min) / (range / n);
        bucket[index]++;
    }

    int k = 0;
    for (int i = 0; i < range; i++) {
        while (bucket[i] > 0) {
            arr[k++] = i * (range / n) + min;
            bucket[i]--;
        }
    }

    free(bucket);
}