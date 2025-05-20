//Falcon-180B DATASET v1.0 Category: Memory management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // maximum size of the array

typedef struct {
    int *arr; // pointer to the integer array
    int size; // current size of the array
    int capacity; // maximum capacity of the array
} Array;

// function to initialize an empty array
void initArray(Array *a) {
    a->arr = NULL;
    a->size = 0;
    a->capacity = MAX_SIZE;
    a->arr = (int *) malloc(a->capacity * sizeof(int));
}

// function to add an element to the array
void addElement(Array *a, int element) {
    if (a->size == a->capacity) {
        a->capacity *= 2;
        a->arr = (int *) realloc(a->arr, a->capacity * sizeof(int));
    }
    a->arr[a->size++] = element;
}

// function to remove an element from the array
void removeElement(Array *a, int index) {
    if (index >= 0 && index < a->size) {
        for (int i = index; i < a->size - 1; i++) {
            a->arr[i] = a->arr[i + 1];
        }
        a->size--;
    }
}

// function to print the array
void printArray(Array a) {
    for (int i = 0; i < a.size; i++) {
        printf("%d ", a.arr[i]);
    }
    printf("\n");
}

// main function
int main() {
    Array a;
    initArray(&a); // initialize an empty array
    
    addElement(&a, 1); // add element 1
    addElement(&a, 2); // add element 2
    addElement(&a, 3); // add element 3
    addElement(&a, 4); // add element 4
    addElement(&a, 5); // add element 5
    
    printArray(a); // print the array: 1 2 3 4 5
    
    removeElement(&a, 2); // remove element 3
    printArray(a); // print the array: 1 2 4 5
    
    return 0;
}