//Falcon-180B DATASET v1.0 Category: Memory management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_SIZE 1000 // size of the heap

typedef struct block {
    size_t size; // size of the block
    int free; // flag indicating whether this block is available or not
    struct block *next; // pointer to the next block
} Block;

Block *freeList = (void*)0; // initialize free list to NULL

// Function to initialize the heap
void init() {
    char *heap = (char*)malloc(HEAP_SIZE); // allocate memory for the heap
    if (heap == NULL) {
        printf("Error: could not allocate memory for heap.\n");
        exit(1);
    }
    freeList = (Block*)heap; // set the free list to the beginning of the heap
    freeList->size = HEAP_SIZE - sizeof(Block);
    freeList->free = 1;
    freeList->next = NULL;
}

// Function to allocate a block of memory from the heap
void *myMalloc(size_t numBytes) {
    Block *current, *prev;
    void *result;

    if (freeList == NULL) {
        printf("Error: heap is empty.\n");
        return NULL;
    }

    current = freeList;
    while ((((current->size) < numBytes) || ((current->free) == 0)) && (current->next!= NULL)) {
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

    return NULL;
}

// Function to free a block of memory in the heap
void myFree(void* ptr) {
    if (ptr == NULL) {
        return;
    }

    Block* block = (Block*)ptr;
    --block;

    block->free = 1;
}

// Main function
int main() {
    init(); // initialize the heap

    int* num1 = (int*)myMalloc(sizeof(int));
    *num1 = 10;

    int* num2 = (int*)myMalloc(sizeof(int));
    *num2 = 20;

    printf("Sum: %d\n", *num1 + *num2);

    myFree(num1);
    myFree(num2);

    return 0;
}