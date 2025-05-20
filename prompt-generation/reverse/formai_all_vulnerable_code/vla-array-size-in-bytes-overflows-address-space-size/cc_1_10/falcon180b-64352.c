//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void bucket_sort(int arr[], int n) {
    int i, j, k;
    int *bucket[MAX_SIZE];
    int max = arr[0];
    int min = arr[0];

    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int bucket_size = range / n;

    for (i = 0; i < n; i++) {
        bucket[i] = (int *)malloc(bucket_size * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        k = (arr[i] - min) / bucket_size;
        bucket[k] = (int *)realloc(bucket[k], sizeof(int) * (j + 1));
        bucket[k][j] = arr[i];
    }

    int index = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < bucket_size; j++) {
            if (bucket[i][j]!= -1) {
                arr[index++] = bucket[i][j];
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}