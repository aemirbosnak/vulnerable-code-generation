//Falcon-180B DATASET v1.0 Category: Memory management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_SIZE 1000 // Size of the heap

typedef struct block {
    size_t size; // Size of the block
    int free; // Flag indicating whether this block is available or not
    struct block *next; // Pointer to the next block
} Block;

Block *freeList = (void*)0; // Initialize free list to NULL

// Function to initialize the heap
void init() {
    char *heap = (char*)malloc(HEAP_SIZE); // Allocate memory for the heap
    if (heap == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    freeList = (Block*)heap; // Set the free list to the beginning of the heap
    freeList->size = HEAP_SIZE - sizeof(Block);
    freeList->free = 1;
    freeList->next = NULL;
}

// Function to allocate a block of memory from the heap
void *myMalloc(size_t numBytes) {
    Block *current, *prev;
    void *result;

    current = freeList;
    while ((((current->size) < numBytes) || ((current->free) == 0)) && (current!= NULL)) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("No memory left!\n");
        return NULL;
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

    return NULL;
}

// Function to free a block of memory back to the heap
void myFree(void* ptr) {
    if (ptr == NULL)
        return;

    Block* blk = (Block*)ptr;
    --blk;
    blk->free = 1;
}

int main() {
    init();

    int* num = (int*)myMalloc(sizeof(int));
    *num = 10;

    char* str = (char*)myMalloc(sizeof(char) * 6);
    strcpy(str, "hello");

    printf("Number: %d, String: %s\n", *num, str);

    myFree(num);
    myFree(str);

    return 0;
}