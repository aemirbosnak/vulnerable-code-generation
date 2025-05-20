//Falcon-180B DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 1000 // Size of the heap

typedef struct block {
    size_t size; // Size of the block
    int free; // Flag indicating whether this block is available or not
    struct block *next; // Pointer to the next block
} Block;

Block *freeList = (void*)0; // Initialize free list to NULL

// Function to initialize the heap
void init() {
    void *heap = malloc(HEAP_SIZE);
    if (heap == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    freeList = (Block*)heap; // Set the free list to the start of the heap
    freeList->size = HEAP_SIZE - sizeof(Block);
    freeList->free = 1;
    freeList->next = NULL;
}

// Function to allocate a block of memory from the heap
void *myMalloc(size_t numBytes) {
    Block *current = freeList;
    while ((current->size < numBytes) && (current->next!= NULL))
        current = current->next;

    if (current->size == numBytes) {
        current->free = 0;
        return (void*)(++current);
    } else if (current->size > numBytes + sizeof(Block)) {
        Block *newBlock = (void*)((void*)current + numBytes + sizeof(Block));
        newBlock->size = current->size - numBytes - sizeof(Block);
        newBlock->free = 1;
        newBlock->next = current->next;
        current->size = numBytes;
        current->free = 0;
        return (void*)(++current);
    }
    return NULL;
}

// Function to free a block of memory back to the heap
void myFree(void* ptr) {
    if ((void*)freeList <= ptr && ptr <= (void*)(freeList + HEAP_SIZE)) {
        Block* blk = (Block*)ptr;
        --blk;
        blk->free = 1;
    }
}

int main() {
    init();
    void* ptr1 = myMalloc(10);
    void* ptr2 = myMalloc(20);
    void* ptr3 = myMalloc(30);
    printf("Allocated %d bytes at %p\n", 10, ptr1);
    printf("Allocated %d bytes at %p\n", 20, ptr2);
    printf("Allocated %d bytes at %p\n", 30, ptr3);
    myFree(ptr1);
    myFree(ptr2);
    myFree(ptr3);
    return 0;
}