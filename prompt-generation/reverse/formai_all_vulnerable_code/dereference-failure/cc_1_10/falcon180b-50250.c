//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the array
#define MAX_SIZE 1000

// Define the structure for the array
typedef struct {
    int *array;
    int size;
} Array;

// Create a new array with the given size
Array createArray(int size) {
    Array arr = {
       .array = (int *)malloc(size * sizeof(int)),
       .size = size
    };
    return arr;
}

// Add an element to the array
void addElement(Array *arr, int element) {
    if (arr->size >= MAX_SIZE) {
        printf("Error: Array is full.\n");
        return;
    }
    arr->array[arr->size++] = element;
}

// Search for an element in the array
bool searchElement(Array *arr, int element) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->array[i] == element) {
            return true;
        }
    }
    return false;
}

// Delete an element from the array
void deleteElement(Array *arr, int element) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->array[i] == element) {
            for (int j = i; j < arr->size - 1; j++) {
                arr->array[j] = arr->array[j + 1];
            }
            arr->size--;
            return;
        }
    }
}

// Print the elements of the array
void printArray(Array arr) {
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.array[i]);
    }
    printf("\n");
}

int main() {
    Array arr = createArray(5);
    addElement(&arr, 1);
    addElement(&arr, 2);
    addElement(&arr, 3);
    addElement(&arr, 4);
    addElement(&arr, 5);
    printArray(arr);

    int element = 3;
    if (searchElement(&arr, element)) {
        printf("Element %d found.\n", element);
    } else {
        printf("Element %d not found.\n", element);
    }

    deleteElement(&arr, element);
    printArray(arr);

    return 0;
}