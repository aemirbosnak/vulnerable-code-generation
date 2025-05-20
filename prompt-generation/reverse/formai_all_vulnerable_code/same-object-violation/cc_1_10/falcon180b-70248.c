//Falcon-180B DATASET v1.0 Category: Memory management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_SIZE 1000

typedef struct block {
    size_t size;
    int free;
    struct block *next;
} Block;

Block *freeList = (void*)0;
char heap[HEAP_SIZE];

void init() {
    freeList = (Block*)heap;
    freeList->size = HEAP_SIZE - sizeof(Block);
    freeList->free = 1;
    freeList->next = (void*)0;
}

void *malloc(size_t numBytes) {
    Block *current, *prev;
    void *result;

    if (!(freeList->size) || (freeList->size < numBytes)) {
        printf("Out of memory!\n");
        return (void*)0;
    }

    current = freeList;
    while ((((current->size) < numBytes) || ((current->free) == 0)) && (current->next!= 0)) {
        prev = current;
        current = current->next;
    }

    if (current->size == numBytes) {
        current->free = 0;
        result = (void*)(++current);
        return result;
    } else if (current->size > numBytes) {
        Block *newBlock = (void*)((void*)current + numBytes + sizeof(Block));
        newBlock->size = current->size - numBytes - sizeof(Block);
        newBlock->free = 1;
        newBlock->next = current->next;
        current->size = numBytes;
        current->free = 0;
        current->next = newBlock;
        result = (void*)(++current);
        return result;
    }

    return (void*)0;
}

void free(void* ptr) {
    if (((void*)heap <= ptr) && (ptr <= (void*)(heap + HEAP_SIZE))) {
        Block* blk = (Block*)ptr;
        --blk;
        blk->free = 1;
    }
}

int main() {
    char* ptr1 = (char*)malloc(10);
    char* ptr2 = (char*)malloc(20);

    if (ptr1!= 0 && ptr2!= 0) {
        printf("Malloc successful\n");
    } else {
        printf("Malloc failed\n");
    }

    free(ptr1);
    free(ptr2);

    return 0;
}