//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void bucketSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

void bucketSort(int arr[], int n) {
    int i, j;
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
    int **bucket = (int **)malloc(range * sizeof(int *));
    for (i = 0; i < range; i++) {
        bucket[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        int index = (arr[i] - min) / (max - min) * range;
        bucket[index][i] = arr[i];
    }

    int k = 0;
    for (i = 0; i < range; i++) {
        for (j = 0; j < n; j++) {
            arr[k++] = bucket[i][j];
        }
    }

    for (i = 0; i < range; i++) {
        free(bucket[i]);
    }
    free(bucket);
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}