//Falcon-180B DATASET v1.0 Category: Memory management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum size of the memory block

typedef struct {
    int size;
    char *data;
} MemoryBlock;

// function to initialize the memory block
void init_memory_block(MemoryBlock *block) {
    block->size = 0;
    block->data = (char *) malloc(MAX_SIZE);
}

// function to allocate memory in the block
char *allocate_memory(MemoryBlock *block, int size) {
    char *ptr = block->data;
    block->size += size;
    return ptr;
}

// function to deallocate memory in the block
void deallocate_memory(MemoryBlock *block, char *ptr, int size) {
    block->size -= size;
    memset(ptr, 0, size); // set the deallocated memory to zero
}

// function to print the memory block status
void print_memory_block(MemoryBlock *block) {
    printf("Memory block status:\n");
    printf("Size: %d\n", block->size);
    printf("Data: %s\n", block->data);
}

int main() {
    MemoryBlock block;
    init_memory_block(&block);

    char *ptr1 = allocate_memory(&block, 50);
    strcpy(ptr1, "Hello World!");

    char *ptr2 = allocate_memory(&block, 30);
    strcpy(ptr2, "This is a test.");

    print_memory_block(&block);

    deallocate_memory(&block, ptr1, 50);
    deallocate_memory(&block, ptr2, 30);

    print_memory_block(&block);

    return 0;
}