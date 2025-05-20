//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void bucket_sort(int arr[], int n);

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[MAX_SIZE];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void bucket_sort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int range = max / n;

    int *bucket[n];
    for (int i = 0; i < n; i++) {
        bucket[i] = (int *)malloc(sizeof(int) * range);
    }

    for (int i = 0; i < n; i++) {
        int index = (arr[i] / range) * range;
        bucket[index] = (int *)realloc(bucket[index], sizeof(int) * (range + 1));
        bucket[index][range] = arr[i];
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < range; k++) {
            arr[j++] = bucket[i][k];
        }
    }
}