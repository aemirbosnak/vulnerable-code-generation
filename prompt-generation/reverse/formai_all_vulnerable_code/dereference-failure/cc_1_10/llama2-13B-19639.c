//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HEAP_SIZE 1024
#define MEMORY_BLOCK_SIZE 64

typedef struct memory_block {
    void* data;
    size_t size;
    struct memory_block* next;
} memory_block_t;

typedef struct heap {
    memory_block_t* root;
    size_t heap_size;
} heap_t;

void* allocate(size_t size) {
    heap_t* heap = malloc(sizeof(heap_t));
    heap->root = NULL;
    heap->heap_size = 0;

    while (heap->heap_size < size) {
        memory_block_t* block = malloc(MEMORY_BLOCK_SIZE);
        block->data = malloc(size - heap->heap_size);
        block->size = size - heap->heap_size;
        block->next = heap->root;
        heap->root = block;
        heap->heap_size += block->size;

        if (heap->heap_size > size) {
            heap->heap_size -= block->size;
            block->size = 0;
            block->next = NULL;
        }
    }

    return heap->root->data;
}

void deallocate(void* data, size_t size) {
    heap_t* heap = malloc(sizeof(heap_t));
    heap->root = data;
    heap->heap_size = size;

    while (heap->heap_size > 0) {
        memory_block_t* block = heap->root;
        heap->root = block->next;
        free(block->data);
        free(block);
        heap->heap_size -= block->size;
    }

    free(heap);
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        size_t size = rand() % 1024 + 1;
        void* data = allocate(size);
        printf("Allocated %zu bytes at %p\n", size, data);

        for (int j = 0; j < size; j++) {
            char c = 'A' + rand() % 26;
            ((char*)data)[j] = c;
        }

        deallocate(data, size);
    }

    return 0;
}