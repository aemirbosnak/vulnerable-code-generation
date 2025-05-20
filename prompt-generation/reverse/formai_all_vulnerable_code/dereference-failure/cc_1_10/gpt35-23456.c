//FormAI DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 1024
#define HEAP_SIZE 4096

/*
  Memory layout:

  |<- BLOCK_SIZE ->|<- BLOCK_SIZE ->|<- BLOCK_SIZE ->|<- BLOCK_SIZE ->|
  |                 |                 |                 |                 |
  |    BLOCK 1    |     BLOCK 2    |     BLOCK 3    |     BLOCK 4    |
  |                 |                 |                 |                 |
  |<------------------- HEAP_SIZE --------------------->|
*/

typedef struct block_header {
    size_t size;
    struct block_header *next;
    char data[1];
} block_header_t;

void* heap = NULL;
block_header_t *blocks_list = NULL;

void initialize_heap() {
    heap = malloc(HEAP_SIZE);
    block_header_t *first_block = (block_header_t*)heap;
    first_block->size = BLOCK_SIZE - sizeof(block_header_t);
    first_block->next = NULL;
    blocks_list = first_block;
}

void* my_malloc(size_t size) {
    block_header_t *current = blocks_list, *previous = NULL;
    
    while (current) {
        if (current->size >= size) {
            if (current->size - size >= sizeof(block_header_t)) {
                // Split the block
                block_header_t *new_block = (block_header_t*)((char*)current + sizeof(block_header_t) + size);
                new_block->size = current->size - sizeof(block_header_t) - size;
                new_block->next = current->next;
                current->next = new_block;
                current->size = size;
            }

            if (previous) {
                previous->next = current->next;
            } else {
                blocks_list = current->next;
            }

            return current->data;
        }

        previous = current;
        current = current->next;
    }

    return NULL;
}

void my_free(void* ptr) {
    block_header_t *current = (block_header_t*)((char*)ptr - sizeof(block_header_t));
    block_header_t *previous = NULL, *next = blocks_list;

    while (next && next < current) {
        previous = next;
        next = next->next;
    }

    if (previous) {
        previous->next = current;
    } else {
        blocks_list = current;
    }

    current->next = next;

    // Merge with previous block
    if (previous && (char*)previous + sizeof(block_header_t) + previous->size == (char*)current) {
        previous->size += sizeof(block_header_t) + current->size;
        previous->next = current->next;
        current = previous;
    }

    // Merge with next block
    if ((char*)current + sizeof(block_header_t) + current->size == (char*)next) {
        current->size += sizeof(block_header_t) + next->size;
        current->next = next->next;
    }
}

int main() {
    initialize_heap();

    int *x = (int*)my_malloc(sizeof(int));
    *x = 42;
    printf("Value of x: %d\n", *x);

    int *y = (int*)my_malloc(2 * sizeof(int));
    y[0] = 1;
    y[1] = 2;
    printf("Value of y[0]: %d\n", y[0]);
    printf("Value of y[1]: %d\n", y[1]);

    my_free(y);
    y = NULL;
    printf("y pointer freed\n");

    my_free(x);
    x = NULL;
    printf("x pointer freed\n");

    return 0;
}