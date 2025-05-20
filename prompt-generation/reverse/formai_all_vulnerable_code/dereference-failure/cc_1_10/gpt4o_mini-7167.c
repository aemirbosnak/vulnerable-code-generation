//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 2
#define GROWTH_FACTOR 2

typedef struct {
    char **data;
    size_t size;
    size_t capacity;
} DynamicArray;

DynamicArray* createArray() {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (!array) {
        perror("Failed to create array");
        exit(EXIT_FAILURE);
    }
    
    array->capacity = INITIAL_SIZE;
    array->size = 0;
    array->data = (char **)malloc(array->capacity * sizeof(char *));
    if (!array->data) {
        perror("Failed to allocate initial data array");
        free(array);
        exit(EXIT_FAILURE);
    }
    
    return array;
}

void resizeArray(DynamicArray *array) {
    array->capacity *= GROWTH_FACTOR;
    array->data = (char **)realloc(array->data, array->capacity * sizeof(char *));
    if (!array->data) {
        perror("Failed to resize data array");
        free(array);
        exit(EXIT_FAILURE);
    }
}

void addString(DynamicArray *array, const char *str) {
    if (array->size >= array->capacity) {
        resizeArray(array);
    }
    
    array->data[array->size] = (char *)malloc((strlen(str) + 1) * sizeof(char));
    if (!array->data[array->size]) {
        perror("Failed to allocate string");
        free(array);
        exit(EXIT_FAILURE);
    }
    
    strcpy(array->data[array->size], str);
    array->size++;
}

void printArray(const DynamicArray *array) {
    printf("Dynamic Array Contents:\n");
    for (size_t i = 0; i < array->size; i++) {
        printf("%s\n", array->data[i]);
    }
}

void freeArray(DynamicArray *array) {
    for (size_t i = 0; i < array->size; i++) {
        free(array->data[i]);
    }
    free(array->data);
    free(array);
}

int main() {
    DynamicArray *myArray = createArray();
    
    addString(myArray, "Hello");
    addString(myArray, "World");
    addString(myArray, "Dynamic");
    addString(myArray, "Array");
    addString(myArray, "Memory");
    addString(myArray, "Management");
    
    printArray(myArray);
    
    freeArray(myArray);
    
    return 0;
}