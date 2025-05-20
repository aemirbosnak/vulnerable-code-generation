//Falcon-180B DATASET v1.0 Category: Sorting ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int data;
    int index;
} SortData;

void swap(SortData arr[], int i, int j) {
    SortData temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(SortData arr[], int low, int high) {
    int pivot = arr[(low + high) / 2].data;
    while (low <= high) {
        while (arr[low].data < pivot)
            low++;
        while (arr[high].data > pivot)
            high--;
        if (low <= high) {
            swap(arr, low, high);
            low++;
            high--;
        }
    }
    return low;
}

void quickSort(SortData arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(SortData arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    SortData arr[size];
    printf("Enter the elements of the array:\n");
    srand(time(0));
    int i;
    for (i = 0; i < size; i++) {
        arr[i].data = rand() % 100;
        arr[i].index = i;
    }

    quickSort(arr, 0, size - 1);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}