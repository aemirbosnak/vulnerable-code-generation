//Falcon-180B DATASET v1.0 Category: Sorting ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Element;

void swap(Element* a, Element* b);
int partition(Element* arr, int low, int high);
void quickSort(Element* arr, int low, int high);

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    Element* arr = (Element*) malloc(sizeof(Element) * size);

    printf("Enter the array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    quickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }

    free(arr);
    return 0;
}

void swap(Element* a, Element* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;

    temp = a->index;
    a->index = b->index;
    b->index = temp;
}

int partition(Element* arr, int low, int high) {
    Element pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].data < pivot.data) {
            swap(&arr[++i], &arr[j]);
        }
    }

    swap(&arr[++i], &arr[high]);

    return i;
}

void quickSort(Element* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}