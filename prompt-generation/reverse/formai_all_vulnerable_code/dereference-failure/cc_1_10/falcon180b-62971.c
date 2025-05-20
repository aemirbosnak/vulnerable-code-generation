//Falcon-180B DATASET v1.0 Category: Sorting ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Element;

void swap(Element *a, Element *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

int compare(const void *a, const void *b) {
    Element *elemA = (Element *)a;
    Element *elemB = (Element *)b;

    if (elemA->data < elemB->data) {
        return -1;
    } else if (elemA->data == elemB->data) {
        return 0;
    } else {
        return 1;
    }
}

void quicksort(Element arr[], int left, int right) {
    int i = left, j = right;
    Element pivot = arr[(left + right) / 2];
    Element temp;

    while (i <= j) {
        while (compare(&arr[i], &pivot) < 0)
            i++;
        while (compare(&arr[j], &pivot) > 0)
            j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j)
        quicksort(arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}

void printArray(Element arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }

    printf("\n");
}

int main() {
    srand(time(NULL));

    Element arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter %d integers:\n", size);

    for (int i = 0; i < size; i++) {
        arr[i].data = rand() % 100;
        arr[i].index = i;
    }

    quicksort(arr, 0, size - 1);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}