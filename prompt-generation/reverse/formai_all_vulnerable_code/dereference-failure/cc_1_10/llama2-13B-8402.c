//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OBJECTS 1000
#define OBJECT_SIZE 1024

typedef struct object {
    void* data;
    size_t size;
} object_t;

typedef struct heap {
    object_t* objects;
    size_t capacity;
    size_t size;
} heap_t;

void init_heap(heap_t* heap) {
    heap->objects = malloc(MAX_OBJECTS * sizeof(object_t));
    heap->capacity = MAX_OBJECTS;
    heap->size = 0;
}

void* alloc_object(heap_t* heap, size_t size) {
    if (heap->size == heap->capacity) {
        size_t new_capacity = heap->capacity * 2;
        object_t* new_objects = realloc(heap->objects, new_capacity * sizeof(object_t));
        if (!new_objects) {
            fprintf(stderr, "Out of memory\n");
            exit(EXIT_FAILURE);
        }
        heap->objects = new_objects;
        heap->capacity = new_capacity;
    }
    void* data = heap->objects + heap->size++;
    heap->objects[heap->size - 1].size = size;
    return data;
}

void free_object(heap_t* heap, void* object) {
    size_t index = (size_t)object - (size_t)heap->objects;
    if (index >= heap->size) {
        fprintf(stderr, "Invalid object\n");
        exit(EXIT_FAILURE);
    }
    heap->objects[index].data = NULL;
    heap->objects[index].size = 0;
    heap->size--;
}

int main() {
    heap_t heap;
    init_heap(&heap);

    // Allocate and free objects
    void* obj1 = alloc_object(&heap, 1024);
    void* obj2 = alloc_object(&heap, 2048);
    free_object(&heap, obj1);

    // Test heap properties
    if (heap.size != 1 || heap.capacity != MAX_OBJECTS) {
        fprintf(stderr, "Heap properties incorrect\n");
        exit(EXIT_FAILURE);
    }

    // Test object allocation and deallocation
    void* obj3 = alloc_object(&heap, 512);
    void* obj4 = alloc_object(&heap, 1536);
    free_object(&heap, obj3);
    free_object(&heap, obj4);

    // Test heap memory layout
    for (size_t i = 0; i < heap.size; i++) {
        if (heap.objects[i].data != NULL) {
            size_t size = heap.objects[i].size;
            void* data = heap.objects[i].data;
            printf("Object %zu: %p (%zu bytes)\n", i, data, size);
        }
    }

    return 0;
}