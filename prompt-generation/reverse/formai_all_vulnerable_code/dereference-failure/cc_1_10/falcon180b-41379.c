//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEAP_SIZE 1000000 // size of the heap
#define BLOCK_SIZE 16 // size of each block in the heap

typedef struct {
    size_t size; // size of the block
    int free; // flag indicating whether this block is available or not
    struct block *next; // pointer to the next block
} block;

block *freeList = (void*)0; // initialize free list to NULL
char heap[HEAP_SIZE]; // our heap

// Function to initialize our heap
void init() {
    freeList = (block*)heap; // point to the start of the heap
    freeList->size = HEAP_SIZE - sizeof(block);
    freeList->free = 1;
    freeList->next = (void*)0;
}

// Our malloc function
void *myMalloc(size_t numBytes) {
    block *current, *prev;
    void *result;
    
    if (!(freeList->size)) { // if our freelist isn't initialized yet
        init();
    }
    
    current = freeList;
    while ((((current->size) < numBytes) || ((current->free) == 0)) && (current->next!= NULL)) {
        prev = current;
        current = current->next;
    }

    if ((current->size) == numBytes) {
        current->free = 0;
        result = (void*)(++current);
        return result;
    } else if ((current->size) > (numBytes + sizeof(block))) {
        block *newBlock = (void*)((void*)current + numBytes + sizeof(block));
        newBlock->size = (current->size) - numBytes - sizeof(block);
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

// Our free function
void myFree(void* ptr) {
    if (((void*)heap <= ptr) && (ptr <= (void*)(heap + HEAP_SIZE))) {
        block* blk = (block*)ptr;
        --blk;
        blk->free = 1;
    }
}

int main() {
    char* ptr;
    int i;

    srand(time(NULL));

    for(i=0; i<10; i++) {
        ptr = (char*)myMalloc(rand() % 100);
        if(ptr!= NULL) {
            printf("Allocated %d bytes at %p\n", rand() % 100, ptr);
        }
    }

    for(i=0; i<10; i++) {
        myFree(ptr);
        ptr = (char*)myMalloc(rand() % 100);
        if(ptr!= NULL) {
            printf("Allocated %d bytes at %p\n", rand() % 100, ptr);
        }
    }

    return 0;
}