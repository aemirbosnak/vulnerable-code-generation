//Falcon-180B DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 1000 // size of the heap

// structure for a block of memory
typedef struct block {
    size_t size; // size of the block
    int free; // flag indicating whether this block is available or not
    struct block *next; // pointer to the next block
} Block;

// initialize the heap
void init() {
    Block *heap = (void*)0; // start of the heap
    heap->size = HEAP_SIZE - sizeof(Block);
    heap->free = 1;
    heap->next = (void*)0;
}

// our own version of malloc
void *my_malloc(size_t num) {
    Block *heap = (void*)0; // start of the heap
    while ((heap->size) < num) {
        heap = heap->next;
        if (heap == (void*)0) {
            printf("Out of memory\n");
            exit(1);
        }
    }
    heap->free = 0;
    return (void*)(++heap);
}

// our own version of free
void my_free(void* ptr) {
    if (ptr == (void*)0)
        return;
    Block* blk = (Block*)ptr;
    --blk;
    blk->free = 1;
}

// main function
int main() {
    init(); // initialize the heap
    int* a = (int*)my_malloc(sizeof(int)); // allocate memory for an integer
    *a = 10; // set the value of the integer
    int* b = (int*)my_malloc(sizeof(int)); // allocate memory for another integer
    *b = 20; // set the value of the integer
    int* c = (int*)my_malloc(sizeof(int)); // allocate memory for yet another integer
    *c = 30; // set the value of the integer
    my_free(a); // free the memory allocated for the first integer
    my_free(b); // free the memory allocated for the second integer
    my_free(c); // free the memory allocated for the third integer
    return 0;
}