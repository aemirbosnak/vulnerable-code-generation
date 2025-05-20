//FormAI DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// struct to represent a block of memory
struct mem_block {
    size_t size;        // size of block in bytes
    int free;           // 1 if block is free, 0 if it is allocated
    struct mem_block *next; // pointer to the next block of memory
};

// the beginning of the memory block
struct mem_block *mem_start = NULL;

// function to initialize the memory block
void mem_init() {
    // allocate memory for the first block
    mem_start = malloc(sizeof(struct mem_block));
    mem_start->size = 4096; // 4 KB memory block
    mem_start->free = 1;
    mem_start->next = NULL;
}

// function to allocate memory
void *mem_alloc(size_t size) {
    // traverse the memory block to find a free block
    struct mem_block *current = mem_start;
    while (current) {
        if (current->free && current->size >= size) {
            // we have found a free block that is big enough
            if (current->size > size + sizeof(struct mem_block)) {
                // split the block into two
                struct mem_block *new_block = (void *)((char *)current + sizeof(struct mem_block) + size);
                new_block->size = current->size - size - sizeof(struct mem_block);
                new_block->free = 1;
                new_block->next = current->next;
                current->next = new_block;
                current->size = size;
            }
            current->free = 0;
            return (void *)(current + 1);
        }
        current = current->next;
    }
    // we couldn't find a free block that is big enough
    return NULL;
}

// function to free memory
void mem_free(void *ptr) {
    // find the block of memory that ptr points to
    struct mem_block *current = mem_start;
    while (current) {
        if ((void *)(current + 1) == ptr) {
            current->free = 1;
            // merge adjacent free blocks
            while (current->next && current->next->free) {
                current->size += sizeof(struct mem_block) + current->next->size;
                current->next = current->next->next;
            }
            return;
        }
        current = current->next;
    }
}

// function to print the memory block
void mem_print() {
    struct mem_block *current = mem_start;
    printf("Memory block:\n");
    while (current) {
        printf("\t%d bytes, %s\n", (int)current->size, current->free ? "free" : "allocated");
        current = current->next;
    }
}

int main() {
    // initialize the memory block
    mem_init();
    // allocate memory
    char *s1 = mem_alloc(10);
    char *s2 = mem_alloc(20);
    char *s3 = mem_alloc(30);
    // print the memory block
    mem_print();
    // free memory
    mem_free(s2);
    // print the memory block again
    mem_print();
    return 0;
}