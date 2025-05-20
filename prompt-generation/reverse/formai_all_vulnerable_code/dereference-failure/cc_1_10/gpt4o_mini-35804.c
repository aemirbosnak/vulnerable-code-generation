//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure representing a dynamic array
typedef struct {
    int *array;      // Pointer to the integer array
    size_t size;     // Current size of the array
    size_t capacity; // Current capacity of the array
} DynamicArray;

// Function to create a dynamic array
DynamicArray* create_dynamic_array(size_t initial_capacity) {
    DynamicArray *d_array = (DynamicArray *) malloc(sizeof(DynamicArray));
    if (!d_array) {
        fprintf(stderr, "Memory allocation failed for DynamicArray\n");
        exit(EXIT_FAILURE);
    }
    
    d_array->array = (int *) malloc(initial_capacity * sizeof(int));
    if (!d_array->array) {
        fprintf(stderr, "Memory allocation failed for array\n");
        free(d_array);
        exit(EXIT_FAILURE);
    }
    
    d_array->size = 0;
    d_array->capacity = initial_capacity;

    return d_array;
}

// Function to adjust the dynamic array's capacity
void resize_dynamic_array(DynamicArray *d_array) {
    d_array->capacity *= 2;
    d_array->array = (int *) realloc(d_array->array, d_array->capacity * sizeof(int));
    if (!d_array->array) {
        fprintf(stderr, "Memory reallocation failed during resize\n");
        free(d_array);
        exit(EXIT_FAILURE);
    }
}

// Function to add an element to the dynamic array
void add_element(DynamicArray *d_array, int element) {
    if (d_array->size == d_array->capacity) {
        printf("Resizing array from %zu to %zu...\n", d_array->capacity, d_array->capacity * 2);
        resize_dynamic_array(d_array);
    }
    
    d_array->array[d_array->size++] = element;
    printf("Added %d to the array. New size is %zu.\n", element, d_array->size);
}

// Function to free the dynamic array
void free_dynamic_array(DynamicArray *d_array) {
    free(d_array->array);
    free(d_array);
    printf("Dynamic array memory has been freed.\n");
}

// Function to print the current elements of the dynamic array
void print_array(DynamicArray *d_array) {
    printf("Current elements in the dynamic array: ");
    for (size_t i = 0; i < d_array->size; i++) {
        printf("%d ", d_array->array[i]);
    }
    printf("\n");
}

int main() {
    printf("Welcome to the shocking world of Dynamic Memory Management!\n");
    
    size_t initial_capacity;
    printf("Enter the initial capacity for the dynamic array: ");
    if (scanf("%zu", &initial_capacity) != 1) {
        fprintf(stderr, "Invalid input! Exiting...\n");
        return EXIT_FAILURE;
    }
    
    DynamicArray *d_array = create_dynamic_array(initial_capacity);
    
    char command;
    do {
        printf("Choose action: (a)dd a number, (p)rint array, (q)uit: ");
        scanf(" %c", &command);
        
        switch (command) {
            case 'a': {
                int number;
                printf("Enter a number to add: ");
                if(scanf("%d", &number) == 1) {
                    add_element(d_array, number);
                } else {
                    fprintf(stderr, "Invalid number! Please try again.\n");
                    scanf("%*s");  // Clear invalid input
                }
                break;
            }
            case 'p':
                print_array(d_array);
                break;
            case 'q':
                printf("Quitting! Cleaning up...\n");
                break;
            default:
                printf("Unknown command! Please choose again.\n");
        }
    } while (command != 'q');
    
    free_dynamic_array(d_array);
    return 0;
}