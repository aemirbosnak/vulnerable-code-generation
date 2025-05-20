//Falcon-180B DATASET v1.0 Category: Sorting ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} Element;

void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(Element* arr, int n) {
    int i;
    for (i = 0; i < n - 1; i++) {
        int j = rand() % n;
        swap(&arr[i], &arr[j]);
    }
}

void quickSort(Element* arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int partition(Element* arr, int low, int high) {
    Element pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].data < pivot.data) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void printArray(Element* arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    Element arr[MAX_SIZE];
    int n;
    srand(time(NULL));

    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    printf("Enter the elements to be sorted:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    shuffle(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}