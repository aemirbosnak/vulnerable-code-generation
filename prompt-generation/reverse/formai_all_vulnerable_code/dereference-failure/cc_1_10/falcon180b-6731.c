//Falcon-180B DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEAP_SIZE 1000000

typedef struct block {
    size_t size;
    int free;
    struct block *next;
} block_t;

block_t *free_list = (void*)0;
char heap[HEAP_SIZE];

void init() {
    free_list = (block_t*)heap;
    free_list->size = HEAP_SIZE - sizeof(block_t);
    free_list->free = true;
    free_list->next = (void*)0;
}

void *my_malloc(size_t num) {
    block_t *current = free_list;
    while (current->size < num) {
        current = current->next;
    }

    if (current->size == num) {
        current->free = false;
        return (void*)(++current);
    } else {
        block_t *new_block = (void*)((char*)current + current->size + sizeof(block_t));
        new_block->size = current->size - num - sizeof(block_t);
        new_block->free = true;
        new_block->next = current->next;
        current->size = num;
        current->free = false;
        return (void*)(++current);
    }
}

void my_free(void* ptr) {
    if (ptr < heap || ptr >= heap + HEAP_SIZE) {
        printf("Invalid pointer\n");
        return;
    }

    block_t* blk = (block_t*)ptr;
    --blk;

    if (blk->free) {
        printf("Double free or invalid pointer\n");
        return;
    }

    blk->free = true;
}

int main() {
    init();

    void* p1 = my_malloc(10);
    void* p2 = my_malloc(20);
    void* p3 = my_malloc(30);

    printf("Allocated %d bytes at %p\n", 10, p1);
    printf("Allocated %d bytes at %p\n", 20, p2);
    printf("Allocated %d bytes at %p\n", 30, p3);

    my_free(p1);
    my_free(p2);
    my_free(p3);

    return 0;
}