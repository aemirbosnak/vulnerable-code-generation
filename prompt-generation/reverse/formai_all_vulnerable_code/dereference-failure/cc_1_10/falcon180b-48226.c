//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum size of memory block

// structure to hold information about each memory block
typedef struct {
    size_t size;
    int free;
    struct block *next;
} block_t;

// initialize the memory
void init() {
    block_t *head = (void*)0;
    head->size = MAX_SIZE;
    head->free = 1;
    head->next = (void*)0;
}

// allocate a memory block of given size
void *my_malloc(size_t size) {
    block_t *current = (void*)0;
    block_t *prev = (void*)0;
    while (current->size < size && current->free == 0) {
        prev = current;
        current = current->next;
    }
    if (current->size == size) {
        current->free = 0;
        return (void*)(++current);
    } else if (current->size > size) {
        block_t *new_block = (void*)current;
        new_block->size = size;
        new_block->free = 1;
        new_block->next = current->next;
        current->size -= size;
        current->next = new_block;
        return (void*)(++new_block);
    }
    return NULL;
}

// free a memory block
void my_free(void *ptr) {
    if (ptr == (void*)0)
        return;
    block_t *current = (block_t*)ptr;
    current->free = 1;
}

// print the current state of memory
void print_memory() {
    block_t *current = (void*)0;
    while (current!= NULL) {
        if (current->free == 0)
            printf("%.6p - %.6p (%.4zu bytes) in use\n", current, current->next, current->size);
        else
            printf("%.6p - %.6p (%.4zu bytes) free\n", current, current->next, current->size);
        current = current->next;
    }
}

int main() {
    init();
    void *ptr1 = my_malloc(100);
    void *ptr2 = my_malloc(200);
    void *ptr3 = my_malloc(300);
    print_memory();
    my_free(ptr1);
    my_free(ptr3);
    print_memory();
    return 0;
}