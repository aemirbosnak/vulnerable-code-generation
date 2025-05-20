//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_SIZE 1024

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

void *myMalloc(size_t numBytes) {
    Block *current, *prev;
    void *result;

    current = freeList;
    while ((((current->size) < numBytes) || ((current->free) == 0)) && (current!= freeList)) {
        prev = current;
        current = current->next;
    }

    if (current->size == numBytes) {
        current->free = 0;
        result = (void*)(++current);
        return result;
    } else if (current->size > numBytes + sizeof(Block)) {
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

    return (void*)0;   // Out of memory
}

void myFree(void* ptr) {
    if (ptr == (void*)0 || ptr == (void*)(--freeList))
        return;

    Block* blk = (Block*)ptr;
    --blk;
    blk->free = 1;
}

int main() {
    char* ptr1 = (char*)myMalloc(10);
    char* ptr2 = (char*)myMalloc(20);

    printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);

    strcpy(ptr1, "Hello");
    strcpy(ptr2, "World");

    printf("ptr1 = %s, ptr2 = %s\n", ptr1, ptr2);

    myFree(ptr1);
    myFree(ptr2);

    return 0;
}