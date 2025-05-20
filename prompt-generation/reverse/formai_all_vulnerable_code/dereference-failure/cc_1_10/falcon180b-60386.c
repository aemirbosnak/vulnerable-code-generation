//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} IntArray;

void init_array(IntArray *arr) {
    arr->data = (int *)malloc(MAX_SIZE * sizeof(int));
    arr->size = 0;
}

void free_array(IntArray *arr) {
    free(arr->data);
}

void add_element(IntArray *arr, int element) {
    if (arr->size == MAX_SIZE) {
        printf("Array is full.\n");
        return;
    }
    arr->data[arr->size++] = element;
}

int get_element(IntArray *arr, int index) {
    if (index < 0 || index >= arr->size) {
        printf("Invalid index.\n");
        return -1;
    }
    return arr->data[index];
}

void remove_element(IntArray *arr, int index) {
    if (index < 0 || index >= arr->size) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

void sort_array(IntArray *arr) {
    for (int i = 0; i < arr->size - 1; i++) {
        for (int j = i + 1; j < arr->size; j++) {
            if (arr->data[i] > arr->data[j]) {
                int temp = arr->data[i];
                arr->data[i] = arr->data[j];
                arr->data[j] = temp;
            }
        }
    }
}

int main() {
    IntArray arr;
    init_array(&arr);

    add_element(&arr, 10);
    add_element(&arr, 20);
    add_element(&arr, 30);
    add_element(&arr, 40);

    sort_array(&arr);

    printf("Sorted array: ");
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", get_element(&arr, i));
    }
    printf("\n");

    remove_element(&arr, 2);

    printf("Array after removing element at index 2: ");
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", get_element(&arr, i));
    }
    printf("\n");

    free_array(&arr);
    return 0;
}