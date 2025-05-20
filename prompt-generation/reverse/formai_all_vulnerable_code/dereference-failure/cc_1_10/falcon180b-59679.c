//Falcon-180B DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Block {
    size_t size;
    bool isFree;
    struct Block *next;
} Block;

Block *freeList = NULL;

void init() {
    freeList = (Block *)malloc(sizeof(Block));
    freeList->size = 0;
    freeList->isFree = true;
    freeList->next = NULL;
}

void *myMalloc(size_t numBytes) {
    Block *current = freeList;
    while ((current->size < numBytes) && (current->next!= NULL)) {
        current = current->next;
    }

    if (current->size == numBytes) {
        current->isFree = false;
        return (void *)((char *)current + sizeof(Block));
    } else if (current->size > numBytes) {
        Block *newBlock = (Block *)malloc(sizeof(Block));
        newBlock->size = current->size - numBytes;
        newBlock->isFree = true;
        newBlock->next = current->next;
        current->size = numBytes;
        current->isFree = false;
        current->next = newBlock;
        return (void *)((char *)current + sizeof(Block));
    }

    return NULL;
}

void myFree(void *ptr) {
    if (ptr == NULL) {
        return;
    }

    char *current = (char *)ptr;
    current -= sizeof(Block);
    Block *block = (Block *)current;

    if ((block->size > 0) && (!block->isFree)) {
        block->isFree = true;
    }
}

int main() {
    init();

    void *p1 = myMalloc(10);
    void *p2 = myMalloc(20);
    void *p3 = myMalloc(30);

    printf("Pointer 1: %p\n", p1);
    printf("Pointer 2: %p\n", p2);
    printf("Pointer 3: %p\n", p3);

    myFree(p1);
    myFree(p2);
    myFree(p3);

    return 0;
}