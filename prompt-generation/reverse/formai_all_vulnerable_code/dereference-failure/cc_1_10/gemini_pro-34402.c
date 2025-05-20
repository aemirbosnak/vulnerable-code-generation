//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAGIC 0xdeadbeef
#define BLOCK_SIZE 1024

typedef struct block {
    int size;
    struct block *next;
} block;

block *free_list = NULL;

void *my_malloc(int size) {
    block *b;

    if (free_list == NULL) {
        b = malloc(BLOCK_SIZE);
        b->size = BLOCK_SIZE - sizeof(block);
        b->next = NULL;
        free_list = b;
    }

    b = free_list;
    while (b != NULL) {
        if (b->size >= size) {
            block *new_block = (block *)((char *)b + sizeof(block) + size);
            new_block->size = b->size - size - sizeof(block);
            new_block->next = b->next;
            b->size = size;
            b->next = new_block;
            return (void *)((char *)b + sizeof(block));
        }
        b = b->next;
    }

    return NULL;
}

void my_free(void *ptr) {
    block *b = (block *)((char *)ptr - sizeof(block));

    if (b->size < 0) {
        fprintf(stderr, "Error: attempt to free invalid pointer\n");
        abort();
    }

    b->size = -b->size;
    b->next = free_list;
    free_list = b;
}

int main() {
    int *p = my_malloc(sizeof(int));
    *p = 42;
    printf("%d\n", *p);
    my_free(p);
    return 0;
}