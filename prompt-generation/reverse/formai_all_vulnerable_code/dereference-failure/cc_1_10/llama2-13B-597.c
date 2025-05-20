//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEM 1024

struct mem_block {
    void* data;
    size_t size;
    struct mem_block* next;
};

struct mem_heap {
    struct mem_block* root;
    size_t heap_size;
};

void* alloc_mem(size_t size) {
    struct mem_block* new_block = (struct mem_block*) malloc(size);
    new_block->data = malloc(size);
    new_block->size = size;
    new_block->next = NULL;
    return new_block->data;
}

void free_mem(void* mem) {
    struct mem_block* block = (struct mem_block*) mem;
    free(block->data);
    free(block);
}

int main() {
    struct mem_heap* heap = (struct mem_heap*) malloc(sizeof(struct mem_heap));
    heap->root = NULL;
    heap->heap_size = 0;

    char* str1 = "Hello, world!";
    char* str2 = "This is a test string.";

    // Allocate memory for two strings
    void* mem1 = alloc_mem(strlen(str1) + 1);
    void* mem2 = alloc_mem(strlen(str2) + 1);
    strcpy(mem1, str1);
    strcpy(mem2, str2);

    // Add the memory blocks to the heap
    heap->root = (struct mem_block*) malloc(sizeof(struct mem_block));
    heap->root->data = mem1;
    heap->root->size = strlen(str1) + 1;
    heap->root->next = NULL;
    heap->heap_size++;

    heap->root = (struct mem_block*) malloc(sizeof(struct mem_block));
    heap->root->data = mem2;
    heap->root->size = strlen(str2) + 1;
    heap->root->next = NULL;
    heap->heap_size++;

    // Print the memory usage
    printf("Heap size: %zu\n", heap->heap_size);

    // Free the memory
    free_mem(heap->root->data);
    free_mem(heap->root->next->data);

    // Print the memory usage again
    printf("Heap size: %zu\n", heap->heap_size);

    return 0;
}