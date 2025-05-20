//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_HEAP_SIZE 1024
#define MAX_OBJECT_SIZE 64

typedef struct {
    void* data;
    size_t size;
} object_t;

typedef struct {
    object_t* heap[MAX_HEAP_SIZE];
    size_t capacity;
    size_t size;
} heap_t;

heap_t* create_heap(size_t capacity) {
    heap_t* heap = (heap_t*)calloc(1, sizeof(heap_t));
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

void* allocate(heap_t* heap, size_t size) {
    if (heap->size >= heap->capacity) {
        printf("Out of memory! Heap is full.\n");
        return NULL;
    }

    size_t object_size = (size_t)((size + 7) / 8) * 8;
    object_t* object = (object_t*)calloc(1, object_size);
    heap->heap[heap->size++] = object;

    return object->data;
}

void deallocate(heap_t* heap, void* data) {
    object_t* object = (object_t*)data;
    heap->size--;
    free(object);
}

void print_heap(heap_t* heap) {
    printf("Heap: ");
    for (size_t i = 0; i < heap->size; i++) {
        object_t* object = heap->heap[i];
        printf("[%p, %zu] ", object->data, object->size);
    }
    printf("\n");
}

int main() {
    heap_t* heap = create_heap(MAX_HEAP_SIZE);

    void* p1 = allocate(heap, 10);
    void* p2 = allocate(heap, 20);
    void* p3 = allocate(heap, 30);

    deallocate(heap, p1);
    deallocate(heap, p2);
    deallocate(heap, p3);

    print_heap(heap);

    return 0;
}