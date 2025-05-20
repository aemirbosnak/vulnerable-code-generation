//Gemma-7B DATASET v1.0 Category: Memory management ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_ALLOCATIONS 1024

typedef struct MemoryBlock {
    struct MemoryBlock* next;
    char* data;
    int size;
} MemoryBlock;

MemoryBlock* freeList = NULL;

void* alloc(int size) {
    MemoryBlock* newBlock = NULL;

    if (freeList) {
        newBlock = freeList;
        freeList = newBlock->next;
    } else {
        newBlock = malloc(sizeof(MemoryBlock));
        newBlock->next = NULL;
        newBlock->data = malloc(size);
        newBlock->size = size;
    }

    return newBlock->data;
}

void free(void* ptr) {
    MemoryBlock* block = ptr;

    if (block) {
        free(block->data);
        block->next = freeList;
        freeList = block;
    }
}

int main() {
    alloc(10);
    alloc(20);
    alloc(30);
    alloc(40);
    alloc(50);

    free(alloc(60));
    free(alloc(70));

    return 0;
}