//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
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
    int* bucket = (int*)malloc(range * sizeof(int));

    for (int i = 0; i < n; i++) {
        int index = arr[i] - min;
        bucket[index]++;
    }

    for (int i = 1; i < range; i++) {
        bucket[i] += bucket[i - 1];
    }

    int* sortedArr = (int*)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        int index = arr[i] - min;
        sortedArr[--bucket[index]] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = sortedArr[i];
    }

    free(bucket);
    free(sortedArr);
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    quickSort(arr, 0, n - 1);
    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}