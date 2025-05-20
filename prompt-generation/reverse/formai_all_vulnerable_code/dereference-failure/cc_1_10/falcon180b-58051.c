//Falcon-180B DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum size of the array

typedef struct {
    int *array;
    int size;
    int capacity;
} DynamicArray;

// function to initialize the dynamic array
DynamicArray *initializeArray(int initialCapacity) {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    array->array = (int *)malloc(initialCapacity * sizeof(int));
    array->size = 0;
    array->capacity = initialCapacity;
    return array;
}

// function to add an element to the dynamic array
void addElement(DynamicArray *array, int element) {
    if (array->size == array->capacity) { // check if array is full
        array->capacity *= 2; // double the capacity if array is full
        array->array = (int *)realloc(array->array, array->capacity * sizeof(int)); // reallocate memory
    }
    array->array[array->size] = element;
    array->size++;
}

// function to remove an element from the dynamic array
void removeElement(DynamicArray *array, int index) {
    for (int i = index; i < array->size - 1; i++) {
        array->array[i] = array->array[i + 1];
    }
    array->size--;
}

// function to print the dynamic array
void printArray(DynamicArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->array[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray *array = initializeArray(MAX_SIZE); // initialize the dynamic array with maximum size
    addElement(array, 10);
    addElement(array, 20);
    addElement(array, 30);
    addElement(array, 40);
    addElement(array, 50);
    printArray(array); // print the dynamic array
    removeElement(array, 2); // remove the element at index 2
    printArray(array); // print the updated dynamic array
    free(array->array); // free the memory allocated for the array
    free(array); // free the memory allocated for the dynamic array
    return 0;
}