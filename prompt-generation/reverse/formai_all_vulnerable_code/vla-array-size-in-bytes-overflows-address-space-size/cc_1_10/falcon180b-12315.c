//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

struct element {
    int data;
    int index;
};

void swap(struct element *a, struct element *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
    temp = a->index;
    a->index = b->index;
    b->index = temp;
}

int partition(struct element arr[], int low, int high) {
    int pivot = arr[(low + high) / 2].data;
    struct element temp = arr[(low + high) / 2];

    arr[(low + high) / 2] = arr[high];
    arr[high] = temp;

    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].data < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(struct element arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void printarray(struct element arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
}

int main() {
    srand(time(NULL));

    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    struct element arr[size];

    for (int i = 0; i < size; i++) {
        arr[i].data = rand() % 1000;
        arr[i].index = i;
    }

    quicksort(arr, 0, size - 1);

    printf("Sorted array: ");
    printarray(arr, size);

    return 0;
}