//Falcon-180B DATASET v1.0 Category: Sorting ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

void fillArray(int arr[], int size) {
    int i;
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Array size is too large.\n");
        return 0;
    }

    fillArray(arr, size);
    printf("Unsorted array:\n");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);
    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}