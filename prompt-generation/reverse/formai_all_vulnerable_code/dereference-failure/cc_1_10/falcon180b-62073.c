//Falcon-180B DATASET v1.0 Category: Educational ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define INIT_SIZE 10
#define GROW_FACTOR 2

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray* createArray() {
    DynamicArray *array = (DynamicArray*) malloc(sizeof(DynamicArray));
    array->data = (int*) malloc(INIT_SIZE * sizeof(int));
    array->size = 0;
    array->capacity = INIT_SIZE;
    return array;
}

void resizeArray(DynamicArray *array) {
    array->capacity *= GROW_FACTOR;
    int *newData = (int*) malloc(array->capacity * sizeof(int));
    for (int i = 0; i < array->size; i++) {
        newData[i] = array->data[i];
    }
    free(array->data);
    array->data = newData;
}

void addElement(DynamicArray *array, int element) {
    if (array->size == array->capacity) {
        resizeArray(array);
    }
    array->data[array->size++] = element;
}

void removeElement(DynamicArray *array, int index) {
    if (index >= array->size) {
        printf("Index out of bounds\n");
        return;
    }
    for (int i = index; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->size--;
    if (array->size < array->capacity / 4) {
        resizeArray(array);
    }
}

void printArray(DynamicArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    DynamicArray *array = createArray();
    for (int i = 0; i < 10; i++) {
        addElement(array, rand() % 100);
    }
    printArray(array);
    for (int i = 0; i < 5; i++) {
        removeElement(array, rand() % array->size);
    }
    printArray(array);
    free(array->data);
    free(array);
    return 0;
}