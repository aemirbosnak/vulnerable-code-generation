//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucket_sort(int arr[], int n) {
    int i, j, max = arr[0], min = arr[0];
    int *bucket[n];

    for (i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    int range = max - min + 1;

    for (i = 0; i < n; i++) {
        bucket[i] = (int *)malloc(range * sizeof(int));
        for (j = 0; j < range; j++)
            bucket[i][j] = 0;
    }

    for (i = 0; i < n; i++) {
        bucket[arr[i] - min][arr[i]]++;
    }

    int k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < range; j++) {
            while (bucket[i][j]-- > 0) {
                arr[k++] = j + min;
            }
        }
    }
}

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}