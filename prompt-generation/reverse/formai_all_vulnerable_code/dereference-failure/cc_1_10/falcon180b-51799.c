//Falcon-180B DATASET v1.0 Category: Sorting ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    int index;
} node;

// Function to swap two nodes
void swap(node* a, node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to partition the array
node* partition(node* arr, int low, int high) {
    node pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].data < pivot.data) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return &arr[i + 1];
}

// Function to perform quick sort
void quickSort(node* arr, int low, int high) {
    if (low < high) {
        node* pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the sorted array
void printArray(node* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    node* arr = (node*) malloc(size * sizeof(node));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    quickSort(arr, 0, size - 1);

    printf("Sorted array:\n");
    printArray(arr, size);

    free(arr);
    return 0;
}