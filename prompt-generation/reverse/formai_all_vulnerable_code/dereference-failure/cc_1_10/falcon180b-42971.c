//Falcon-180B DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 100
#define BLOCK_SIZE 32

typedef struct block {
    size_t size;
    int free;
    struct block *next;
} Block;

Block *freeList = (void*)0;

void init() {
    freeList = (Block*)malloc(sizeof(Block));
    freeList->size = 0;
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

    if ((current->size) == numBytes) {
        current->free = 0;
        return (void*)(++current);
    } else if ((current->size) > (numBytes + BLOCK_SIZE)) {
        Block *newBlock = (void*)((void*)current + numBytes + BLOCK_SIZE);
        newBlock->size = (current->size) - numBytes - BLOCK_SIZE;
        newBlock->free = 1;
        newBlock->next = current->next;
        current->size = numBytes;
        current->free = 0;
        current->next = newBlock;
        return (void*)(++current);
    } else {
        return NULL;
    }
}

void myFree(void* ptr) {
    if (ptr!= freeList) {
        Block* blk = (Block*)ptr;
        --blk;
        blk->free = 1;
    }
}

int main() {
    char* str1 = (char*)myMalloc(10);
    char* str2 = (char*)myMalloc(20);

    strcpy(str1, "Hello");
    strcpy(str2, "World");

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    myFree(str1);
    myFree(str2);

    return 0;
}