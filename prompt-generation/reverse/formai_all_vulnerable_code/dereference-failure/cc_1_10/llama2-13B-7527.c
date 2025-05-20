//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_HEAP_SIZE 1024
#define MAX_OBJECT_SIZE 32

typedef struct object {
    void* data;
    size_t size;
    struct object* next;
} object_t;

typedef struct heap {
    object_t* head;
    size_t capacity;
} heap_t;

static inline void* allocate(heap_t* heap, size_t size) {
    if (heap->capacity == 0) {
        heap->capacity = 128;
        heap->head = malloc(sizeof(object_t) * heap->capacity);
        if (heap->head == NULL) {
            fprintf(stderr, "Failed to allocate memory for heap\n");
            exit(EXIT_FAILURE);
        }
    }

    void* data = heap->head->data;
    heap->head = heap->head->next;
    heap->head->data = NULL;
    heap->head->size = size;
    return data;
}

static inline void deallocate(heap_t* heap, void* data) {
    object_t* obj = (object_t*) data;
    obj->next = heap->head;
    heap->head = obj;
    heap->capacity -= obj->size;
}

int main() {
    heap_t heap;
    heap.head = NULL;
    heap.capacity = 0;

    char* str = "Hello, world!";
    size_t str_size = strlen(str) + 1;

    // Allocate memory for the string
    void* data = allocate(&heap, str_size);
    if (data == NULL) {
        fprintf(stderr, "Failed to allocate memory for string\n");
        exit(EXIT_FAILURE);
    }

    // Copy the string into the allocated memory
    memcpy(data, str, str_size);

    // Allocate memory for an integer
    int* int_data = allocate(&heap, sizeof(int));
    if (int_data == NULL) {
        fprintf(stderr, "Failed to allocate memory for integer\n");
        exit(EXIT_FAILURE);
    }

    // Set the value of the integer
    *int_data = 42;

    // Deallocate memory for the integer
    deallocate(&heap, int_data);

    // Deallocate memory for the string
    deallocate(&heap, data);

    return 0;
}