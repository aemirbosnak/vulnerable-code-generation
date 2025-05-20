//FormAI DATASET v1.0 Category: Memory management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 4096

typedef struct block_header {
    size_t size;
    unsigned int is_free;
    struct block_header *next;
} block_header_t;

block_header_t *head = NULL;

block_header_t *find_free_block(size_t size) {
    block_header_t *current = head;
    while (current) {
        if (current->is_free && current->size >= size) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void split_block(block_header_t *block, size_t size) {
    if (!block || block->size < size + sizeof(block_header_t)) {
        return;
    }
    block_header_t *new_block = (block_header_t *)((char *)block + sizeof(block_header_t) + size);
    new_block->size = block->size - size - sizeof(block_header_t);
    new_block->is_free = 1;
    new_block->next = block->next;
    block->size = size;
    block->is_free = 0;
    block->next = new_block;
}

void *calloc(size_t num, size_t size) {
    size_t total_size = num * size;
    void *ptr = malloc(total_size);
    if (!ptr) {
        return NULL;
    }
    return memset(ptr, 0, total_size);
}

void *malloc(size_t size) {
    if (size <= 0) {
        return NULL;
    }
    block_header_t *block = find_free_block(size);
    if (block) {
        split_block(block, size);
        return (void *)(block + 1);
    }
    block = sbrk(0);
    void *request = sbrk(size + sizeof(block_header_t));
    if (request == (void*)-1) {
        return NULL;
    }
    block->size = size;
    block->is_free = 0;
    block->next = NULL;
    if (head) {
        head->next = block;
    }
    head = block;
    return (void *)(block + 1);
}

void merge_blocks() {
    block_header_t *current = head;
    while (current && current->next) {
        if (current->is_free && current->next->is_free) {
            current->size += current->next->size + sizeof(block_header_t);
            current->next = current->next->next;
        }
        current = current->next;
    }
}

void free(void *ptr) {
    if (!ptr) {
        return;
    }
    block_header_t *block = (block_header_t *)ptr - 1;
    if (block->is_free) {
        return;
    }
    block->is_free = 1;
    if (block->next && block->next->is_free) {
        merge_blocks();
    }
}

int main() {
    int *nums = malloc(10 * sizeof(int));
    nums[0] = 5;
    nums[1] = 10;
    nums[2] = 15;
    nums[3] = 20;
    nums[4] = 25;
    printf("%d\n", nums[2]);
    free(nums);
    return 0;
}