//Falcon-180B DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

void init(DynamicArray *array, int capacity) {
    array->data = (int *)malloc(capacity * sizeof(int));
    array->size = 0;
    array->capacity = capacity;
}

void resize(DynamicArray *array) {
    int newCapacity = array->capacity * 2;
    int *newData = (int *)realloc(array->data, newCapacity * sizeof(int));
    if (newData == NULL) {
        printf("Error: Memory reallocation failed.\n");
        exit(1);
    }
    array->data = newData;
    array->capacity = newCapacity;
}

void push(DynamicArray *array, int value) {
    if (array->size == array->capacity) {
        resize(array);
    }
    array->data[array->size++] = value;
}

int pop(DynamicArray *array) {
    if (array->size == 0) {
        printf("Error: Array is empty.\n");
        exit(1);
    }
    return array->data[--array->size];
}

void print(DynamicArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    DynamicArray array;
    init(&array, 10);
    for (int i = 0; i < 100; i++) {
        int choice = rand() % 3;
        switch (choice) {
            case 0:
                push(&array, rand() % 100);
                break;
            case 1:
                printf("Popped element: %d\n", pop(&array));
                break;
            case 2:
                print(&array);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    free(array.data);
    return 0;
}