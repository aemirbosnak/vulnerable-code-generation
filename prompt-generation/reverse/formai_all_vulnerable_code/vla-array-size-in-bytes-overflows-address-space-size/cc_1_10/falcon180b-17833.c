//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int range = max / n;
    int* bucket[n];

    for (int i = 0; i < n; i++) {
        bucket[i] = (int*)malloc(sizeof(int) * (range + 1));
    }

    for (int i = 0; i < n; i++) {
        bucket[i][0] = 0;
    }

    for (int i = 0; i < n; i++) {
        int index = arr[i] / range;
        bucket[index][arr[i] % range + 1]++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= range; j++) {
            arr[i * range + j - 1] = bucket[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        free(bucket[i]);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    srand(time(NULL));

    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);
    printf("Sorted array using Quick Sort:\n");
    printArray(arr, n);

    bucketSort(arr, n);
    printf("\nSorted array using Bucket Sort:\n");
    printArray(arr, n);

    return 0;
}