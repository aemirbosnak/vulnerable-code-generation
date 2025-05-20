//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

// Function prototypes
DynamicArray* create_array();
void destroy_array(DynamicArray *array);
void add_element(DynamicArray *array, int element);
void remove_element(DynamicArray *array);
void print_array(const DynamicArray *array);
void resize(DynamicArray *array, size_t new_capacity);

int main() {
    DynamicArray *array = create_array();
    int choice, value;

    while (1) {
        printf("\nDynamic Array Menu:\n");
        printf("1. Add Element\n");
        printf("2. Remove Element\n");
        printf("3. Print Array\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer to add: ");
                scanf("%d", &value);
                add_element(array, value);
                break;
            case 2:
                remove_element(array);
                break;
            case 3:
                print_array(array);
                break;
            case 4:
                destroy_array(array);
                return 0;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
}

// Function to create a new dynamic array
DynamicArray* create_array() {
    DynamicArray *array = (DynamicArray*)malloc(sizeof(DynamicArray));
    array->size = 0;
    array->capacity = INITIAL_CAPACITY;
    array->data = (int*)malloc(array->capacity * sizeof(int));
    return array;
}

// Function to destroy the dynamic array and free memory
void destroy_array(DynamicArray *array) {
    free(array->data);
    free(array);
    printf("Dynamic array destroyed successfully.\n");
}

// Function to add an element to the dynamic array
void add_element(DynamicArray *array, int element) {
    if (array->size == array->capacity) {
        resize(array, array->capacity * 2);
    }
    array->data[array->size++] = element;
    printf("Added %d to the array.\n", element);
}

// Function to remove the last element from the dynamic array
void remove_element(DynamicArray *array) {
    if (array->size > 0) {
        array->size--;
        if (array->size < array->capacity / 4) {
            resize(array, array->capacity / 2);
        }
        printf("Removed an element from the array.\n");
    } else {
        printf("Array is already empty. Nothing to remove.\n");
    }
}

// Function to print the current elements in the dynamic array
void print_array(const DynamicArray *array) {
    if (array->size == 0) {
        printf("The array is empty.\n");
        return;
    }
    printf("Dynamic Array: [ ");
    for (size_t i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("]\n");
}

// Function to resize the dynamic array to a new capacity
void resize(DynamicArray *array, size_t new_capacity) {
    array->data = (int*)realloc(array->data, new_capacity * sizeof(int));
    if (array->data != NULL) {
        array->capacity = new_capacity;
        printf("Resized array to new capacity: %zu\n", new_capacity);
    } else {
        printf("Memory reallocation failed.\n");
        exit(EXIT_FAILURE);
    }
}