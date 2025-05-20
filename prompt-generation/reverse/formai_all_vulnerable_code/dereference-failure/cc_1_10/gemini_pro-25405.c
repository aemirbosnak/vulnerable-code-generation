//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Custom memory allocator
typedef struct {
    void *start;
    size_t size;
    struct mem_block *next;
} mem_block;

mem_block *free_list = NULL;

void *my_malloc(size_t size) {
    mem_block *block;

    // Try to find a free block of sufficient size
    for (block = free_list; block != NULL; block = block->next) {
        if (block->size >= size) {
            break;
        }
    }

    // If no free block found, allocate a new one
    if (block == NULL) {
        block = malloc(size + sizeof(mem_block));
        if (block == NULL) {
            return NULL;
        }
        block->start = (void *)((char *)block + sizeof(mem_block));
        block->size = size;
    }

    // Remove the block from the free list
    if (block != free_list) {
        mem_block *prev = free_list;
        while (prev->next != block) {
            prev = prev->next;
        }
        prev->next = block->next;
    } else {
        free_list = block->next;
    }

    return block->start;
}

void my_free(void *ptr) {
    mem_block *block = (mem_block *)((char *)ptr - sizeof(mem_block));

    // Add the block to the free list
    block->next = free_list;
    free_list = block;
}

// Example usage
int main() {
    int *ptr = (int *)my_malloc(sizeof(int));
    if (ptr == NULL) {
        return 1;
    }

    *ptr = 42;

    printf("%d\n", *ptr);

    my_free(ptr);

    return 0;
}