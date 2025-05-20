//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    struct Block *next;
    char data[1];
} Block;

Block *head = NULL;

Block *allocate(size_t size) {
    if (size < 1) {
        fprintf(stderr, "Invalid size: %ld\n", size);
        exit(EXIT_FAILURE);
    }

    Block *new_block = (Block *)malloc(sizeof(Block) + size);
    if (!new_block) {
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }

    new_block->size = size;
    new_block->next = head;
    head = new_block;

    return (Block *)((char *)new_block + sizeof(Block) + size);
}

void free_memory(Block *prev_block, Block *current_block) {
    if (current_block) {
        free_memory(current_block, current_block->next);
        current_block->size = 0;
        current_block->next = prev_block;
    }
}

void free_mem(void *ptr, size_t size) {
    Block *prev_block = NULL;
    Block *current_block = head;

    while (current_block) {
        if ((char *)current_block <= ((char *)ptr - sizeof(Block)) &&
            (size_t)(((char *)ptr - ((char *)current_block)) + current_block->size) >= size) {

            free_memory(prev_block, current_block->next);
            current_block->size = 0;
            current_block->next = prev_block;
            break;
        }

        prev_block = current_block;
        current_block = current_block->next;
    }
}

int main() {
    char *str1 = (char *)allocate(50);
    strcpy(str1, "This is a string of length 50");

    char *str2 = (char *)allocate(30);
    strcpy(str2, "This is a string of length 30");

    printf("Str1: %s\n", str1);
    printf("Str2: %s\n", str2);

    free_mem(str1, 50);
    free_mem(str2, 30);

    return 0;
}