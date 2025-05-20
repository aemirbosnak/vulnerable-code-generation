//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY_SIZE 100
#define BLOCK_SIZE 16

typedef struct {
    int *array;
    size_t size;
    size_t capacity;
} dynamic_array;

static void *malloc_safe(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    // Check if the memory block is already in use
    if (ptr == (void *)0xdeadbeef) {
        free(ptr);
        printf("Memory block is already in use\n");
        return malloc_safe(size);
    }
    return ptr;
}

static void free_safe(void *ptr) {
    if (ptr == NULL) {
        return;
    }
    if (*(int *)ptr == 0xdeadbeef) {
        // Memory block is already freed, do nothing
        return;
    }
    free(ptr);
    *(int *)ptr = 0xdeadbeef;
}

static void print_array(dynamic_array *array) {
    printf("Array: ");
    for (size_t i = 0; i < array->size; i++) {
        printf("%d ", array->array[i]);
    }
    printf("\n");
}

int main() {
    dynamic_array *array = malloc_safe(sizeof(dynamic_array));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    array->array = malloc_safe(MAX_ARRAY_SIZE * sizeof(int));
    if (array->array == NULL) {
        printf("Memory allocation failed\n");
        free_safe(array);
        return 1;
    }
    array->size = 0;
    array->capacity = MAX_ARRAY_SIZE;

    // Add elements to the array
    for (size_t i = 0; i < 10; i++) {
        int element = i * 2;
        array->array[array->size++] = element;
        if (array->size >= array->capacity) {
            // Reallocate the array when it's full
            dynamic_array *new_array = malloc_safe(2 * array->capacity * sizeof(int));
            if (new_array == NULL) {
                printf("Memory allocation failed\n");
                return 1;
            }
            // Copy the existing elements to the new array
            for (size_t j = 0; j < array->size; j++) {
                new_array->array[j] = array->array[j];
            }
            // Free the old array
            free_safe(array->array);
            array->array = new_array->array;
            array->capacity *= 2;
        }
    }

    // Print the array
    print_array(array);

    // Free the array and its elements
    for (size_t i = 0; i < array->size; i++) {
        free_safe(array->array[i]);
    }
    free_safe(array->array);
    free_safe(array);

    return 0;
}