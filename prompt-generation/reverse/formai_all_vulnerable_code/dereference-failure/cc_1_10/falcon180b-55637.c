//Falcon-180B DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 1000 // size of the heap
#define BLOCK_SIZE 16 // size of each block in the heap
#define NUM_BLOCKS (HEAP_SIZE / BLOCK_SIZE) // number of blocks in the heap

typedef struct {
    int size; // size of the block
    int free; // flag indicating whether the block is free or not
} Block;

Block *heap = (void*)0; // initialize the heap to NULL

void init() {
    heap = (Block*)malloc(HEAP_SIZE); // allocate memory for the heap
    if (heap == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < NUM_BLOCKS; i++) {
        heap[i].size = BLOCK_SIZE;
        heap[i].free = 1;
    }
}

void *my_malloc(int size) {
    Block *current = heap;
    while ((current->size < size) || (current->free == 0)) {
        current++;
        if (current >= heap + NUM_BLOCKS) {
            current = heap; // wrap around to the beginning of the heap
        }
    }
    if (current->size == size) {
        current->free = 0;
        return (void*)(++current);
    } else {
        current->size = size;
        current->free = 0;
        return (void*)(++current);
    }
}

void my_free(void* ptr) {
    Block *current = (Block*)ptr;
    current--;
    if ((current < heap) || (current->free == 0)) {
        printf("Invalid pointer!\n");
        return;
    }
    current->free = 1;
}

int main() {
    init();
    int* p = (int*)my_malloc(4);
    *p = 10;
    int* q = (int*)my_malloc(4);
    *q = 20;
    int* r = (int*)my_malloc(8);
    *r = 30;
    my_free(p);
    my_free(q);
    my_free(r);
    return 0;
}