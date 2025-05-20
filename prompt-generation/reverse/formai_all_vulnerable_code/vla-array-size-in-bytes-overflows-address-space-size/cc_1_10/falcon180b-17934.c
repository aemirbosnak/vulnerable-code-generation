//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot element
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int bucketSize = range / n;

    int* bucket[n];

    for (int i = 0; i < n; i++) {
        bucket[i] = (int*)malloc(bucketSize * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        int index = arr[i] - min;
        bucket[index] = (int*)realloc(bucket[index], (bucketSize + 1) * sizeof(int));
        bucket[index][bucketSize] = arr[i];
    }

    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSize; j++) {
            arr[k++] = bucket[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        free(bucket[i]);
    }
}

// Function to print the sorted array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

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