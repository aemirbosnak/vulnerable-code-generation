//Falcon-180B DATASET v1.0 Category: Sorting ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} pair;

void swap(pair* a, pair* b) {
    pair temp = *a;
    *a = *b;
    *b = temp;
}

int partition(pair arr[], int low, int high) {
    int pivot = arr[(int)(rand() % high)].data;
    pair temp = arr[high];
    arr[high] = arr[low];
    arr[low] = temp;

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].data < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

void quickSort(pair arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(pair arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    pair arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    srand(time(NULL));
    quickSort(arr, 0, size - 1);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}