//Falcon-180B DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define HEAP_INIT_SIZE 1024
#define HEAP_BLOCK_SIZE 32

typedef struct {
    size_t size;
    int free;
    struct block *next;
} block_t;

block_t *freeList = (void*)0;
char heap[HEAP_INIT_SIZE];

void init() {
    freeList = (block_t*)heap;
    freeList->size = HEAP_INIT_SIZE - sizeof(block_t);
    freeList->free = 1;
    freeList->next = (void*)0;
}

void *myMalloc(size_t numBytes) {
    block_t *current, *prev;
    void *result;

    current = freeList;
    while ((((current->size) < numBytes) || ((current->free) == 0)) && (current->next!= NULL)) {
        prev = current;
        current = current->next;
    }

    if (current->size == numBytes) {
        current->free = 0;
        result = (void*)(++current);
        return result;
    } else if (current->size > numBytes + sizeof(block_t)) {
        block_t *newBlock = (void*)((void*)current + numBytes + sizeof(block_t));
        newBlock->size = current->size - numBytes - sizeof(block_t);
        newBlock->free = 1;
        newBlock->next = current->next;
        current->size = numBytes;
        current->free = 0;
        current->next = newBlock;
        result = (void*)(++current);
        return result;
    }

    return NULL;
}

void myFree(void* ptr) {
    if (ptr!= NULL) {
        block_t* blk = (block_t*)ptr;
        --blk;
        blk->free = 1;
    }
}

int main() {
    char* str1 = (char*)myMalloc(10);
    char* str2 = (char*)myMalloc(20);

    if (str1!= NULL) {
        strcpy(str1, "Hello");
        printf("str1: %s\n", str1);
    } else {
        printf("Memory error!\n");
    }

    if (str2!= NULL) {
        strcpy(str2, "World");
        printf("str2: %s\n", str2);
    } else {
        printf("Memory error!\n");
    }

    myFree(str1);
    myFree(str2);

    return 0;
}