//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

// Function prototypes
DynamicArray* create_array();
void destroy_array(DynamicArray* arr);
void add_element(DynamicArray* arr, int value);
void print_array(DynamicArray* arr);
void resize_array(DynamicArray* arr);
void remove_element(DynamicArray* arr, int index);

int main() {
    DynamicArray *arr = create_array();
    int choice, value, index;

    printf("Dynamic Array Memory Management Simulation\n");
    printf("1. Add Element\n2. Print Array\n3. Remove Element\n4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                add_element(arr, value);
                break;
            case 2:
                print_array(arr);
                break;
            case 3:
                printf("Enter index to remove: ");
                scanf("%d", &index);
                remove_element(arr, index);
                break;
            case 4:
                destroy_array(arr);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

DynamicArray* create_array() {
    DynamicArray *arr = (DynamicArray*)malloc(sizeof(DynamicArray));
    arr->size = 0;
    arr->capacity = INITIAL_CAPACITY;
    arr->data = (int*)malloc(arr->capacity * sizeof(int));
    return arr;
}

void destroy_array(DynamicArray* arr) {
    free(arr->data);
    free(arr);
}

void add_element(DynamicArray* arr, int value) {
    if (arr->size == arr->capacity) {
        resize_array(arr);
    }
    arr->data[arr->size] = value;
    arr->size++;
}

void print_array(DynamicArray* arr) {
    printf("Dynamic Array: ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

void resize_array(DynamicArray* arr) {
    arr->capacity *= 2;
    arr->data = (int*)realloc(arr->data, arr->capacity * sizeof(int));
    if (!arr->data) {
        fprintf(stderr, "Memory allocation failed during resizing\n");
        exit(EXIT_FAILURE);
    }
}

void remove_element(DynamicArray* arr, int index) {
    if (index < 0 || index >= arr->size) {
        printf("Index out of bounds.\n");
        return;
    }
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
    printf("Element removed from index %d\n", index);
}