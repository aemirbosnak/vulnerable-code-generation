//Falcon-180B DATASET v1.0 Category: Sorting ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} element;

void swap(element* a, element* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

int partition(element arr[], int low, int high) {
    int pivot = arr[high].data;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].data < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(element arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void print_array(element arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    element arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        arr[i].data = rand() % 1000;
        arr[i].index = i;
    }

    printf("Unsorted array:\n");
    print_array(arr, size);

    quick_sort(arr, 0, size - 1);

    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}