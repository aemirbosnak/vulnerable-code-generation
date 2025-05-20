//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4096
#define HEADER_SIZE 32

typedef struct Block {
    size_t size;
    struct Block* next;
    char data[1];
} Block;

Block* head = NULL;
Block* free_list = NULL;

void init_allocator() {
    head = malloc(BLOCK_SIZE);
    if (!head) {
        printf("Failed to initialize memory manager.\n");
        exit(EXIT_FAILURE);
    }

    head->size = BLOCK_SIZE - HEADER_SIZE;
    head->next = NULL;
    free_list = (Block*)((char*)head + HEADER_SIZE);
}

Block* allocate(size_t size) {
    Block* current = free_list;
    Block* previous = NULL;

    while (current != NULL) {
        if (current->size >= size + HEADER_SIZE) {
            current->size -= size + HEADER_SIZE;
            current = (Block*)((char*)current + size + HEADER_SIZE);
            free_list = current;

            return (Block*)((char*)previous + HEADER_SIZE);
        }

        previous = current;
        current = current->next;
    }

    Block* new_block = malloc(size + HEADER_SIZE);
    if (!new_block) {
        printf("Out of memory.\n");
        return NULL;
    }

    new_block->size = size;
    new_block->next = free_list;
    free_list = new_block;

    return new_block;
}

void deallocate(Block* block) {
    if (block < free_list || free_list < block) {
        printf("Invalid block.\n");
        return;
    }

    if (block->next != NULL) {
        Block* current = free_list;

        while (current->next != block) {
            current = current->next;
        }

        current->next = block->next;
    } else {
        free_list = block->next;
    }
}

int main() {
    init_allocator();

    char* str1 = (char*)allocate(50);
    strcpy(str1, "Hello, world!");

    char* str2 = (char*)allocate(100);
    strcpy(str2, "This is a longer string.");

    printf("%s\n", str1);
    printf("%s\n", str2);

    deallocate(str1);
    deallocate(str2);

    return 0;
}