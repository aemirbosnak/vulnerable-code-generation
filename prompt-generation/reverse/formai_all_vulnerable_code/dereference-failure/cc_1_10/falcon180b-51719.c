//Falcon-180B DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEAP_SIZE 1000 // size of the heap

typedef struct block {
    size_t size; // size of the block
    int free; // flag indicating if this block is available or not
    struct block *next; // pointer to the next block
} Block;

Block *freeList = (void*)0; // initialize free list to NULL

// Function to initialize our heap
void init() {
    char *heap = (char*)malloc(HEAP_SIZE); // allocate memory for the heap
    if(heap == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    freeList = (Block*)heap; // set the first block as the free list
    freeList->size = HEAP_SIZE - sizeof(Block);
    freeList->free = 1;
    freeList->next = NULL;
}

// Our malloc function
void *myMalloc(size_t numBytes) {
    Block *current = freeList;
    while(current!= NULL && current->size < numBytes) {
        current = current->next;
    }

    if(current == NULL) {
        printf("Out of memory\n");
        return NULL;
    }

    if(current->size == numBytes) {
        current->free = 0;
        return (void*)(++current);
    } else {
        Block *newBlock = (void*)current + numBytes + sizeof(Block);
        if((void*)newBlock > (void*)freeList + HEAP_SIZE) {
            printf("Out of memory\n");
            return NULL;
        }
        newBlock->size = current->size - numBytes - sizeof(Block);
        newBlock->free = 1;
        newBlock->next = current->next;
        current->size = numBytes;
        current->free = 0;
        current->next = newBlock;
        return (void*)(++current);
    }
}

// Our free function
void myFree(void* ptr) {
    if(ptr == NULL) {
        return;
    }

    Block* blk = (Block*)ptr - 1;
    blk->free = 1;
}

int main() {
    init();

    int* num = (int*)myMalloc(sizeof(int));
    *num = 5;

    char* str = (char*)myMalloc(10);
    strcpy(str, "Hello");

    printf("%d %s\n", *num, str);

    myFree(num);
    myFree(str);

    return 0;
}