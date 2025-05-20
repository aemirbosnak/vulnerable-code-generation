//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
} Array;

void init_array(Array *array, int size) {
    array->data = (int *)malloc(size * sizeof(int));
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->data[i] = rand() % MAX_SIZE;
    }
}

void print_array(Array array) {
    for (int i = 0; i < array.size; i++) {
        printf("%d ", array.data[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(Array array) {
    for (int i = 1; i < array.size; i++) {
        int key = array.data[i];
        int j = i - 1;
        while (j >= 0 && array.data[j] > key) {
            swap(&array.data[j], &array.data[j + 1]);
            j--;
        }
        array.data[j + 1] = key;
    }
}

int main() {
    srand(time(NULL));
    Array array;
    int size = rand() % (MAX_SIZE / 2) + 1;
    init_array(&array, size);
    printf("Original array:\n");
    print_array(array);
    insertion_sort(array);
    printf("Sorted array:\n");
    print_array(array);
    return 0;
}