//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    struct Block* next;
    char data[1];
} Block;

Block* heap = NULL;

void print_memory() {
    Block* current = heap;
    printf("\nMemory Dump:\n");
    while (current != NULL) {
        printf("Block Size: %ld, Address: %p, Data: %s\n", current->size, current, current->data);
        current = current->next;
    }
}

void* my_malloc(size_t size) {
    if (size == 0) {
        fprintf(stderr, "Invalid size!\n");
        return NULL;
    }

    Block* new_block = (Block*) calloc(1, sizeof(Block) + size);

    if (new_block == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }

    new_block->size = size;

    if (heap == NULL) {
        heap = new_block;
    } else {
        Block* current = heap;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_block;
    }

    return (void*) (new_block + 1);
}

void my_free(void* ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Invalid pointer!\n");
        return;
    }

    Block* block_to_free = (Block*) ((char*) ptr - sizeof(Block));

    if (block_to_free->next != NULL) {
        block_to_free->size += ((char*) block_to_free->next - ((char*) block_to_free)) + sizeof(Block);
    }

    if (heap == block_to_free) {
        heap = block_to_free->next;
    } else {
        Block* current = heap;
        while (current->next != block_to_free) {
            current = current->next;
        }
        current->next = block_to_free->next;
    }

    free(block_to_free);
}

int main() {
    char* str1 = (char*) my_malloc(10);
    strcpy(str1, "Hello, World!");
    print_memory();

    char* str2 = (char*) my_malloc(20);
    strcpy(str2, "This is a memory management example!");
    print_memory();

    my_free(str1);
    print_memory();

    my_free(str2);
    print_memory();

    my_malloc(50);
    print_memory();

    return 0;
}