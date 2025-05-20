//Falcon-180B DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 16

typedef struct {
    void* data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray* createDynamicArray() {
    DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));
    da->data = (void*)malloc(CHUNK_SIZE);
    da->size = 0;
    da->capacity = CHUNK_SIZE;
    return da;
}

void resizeDynamicArray(DynamicArray* da) {
    da->capacity += CHUNK_SIZE;
    da->data = (void*)realloc(da->data, da->capacity);
}

void addElementToDynamicArray(DynamicArray* da, void* element) {
    if (da->size == da->capacity) {
        resizeDynamicArray(da);
    }
    memcpy(da->data + da->size, element, sizeof(element));
    da->size++;
}

void printDynamicArray(DynamicArray* da) {
    int i;
    for (i = 0; i < da->size; i++) {
        printf("%p ", da->data + i);
    }
    printf("\n");
}

int main() {
    DynamicArray* da = createDynamicArray();
    int i;
    for (i = 0; i < 10; i++) {
        addElementToDynamicArray(da, &i);
    }
    printDynamicArray(da);
    return 0;
}