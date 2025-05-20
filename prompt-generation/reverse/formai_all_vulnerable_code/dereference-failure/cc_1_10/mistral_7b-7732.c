//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define BLOCK_SIZE 16

typedef struct Block {
    size_t size;
    struct Block* next;
    char data[1];
} Block;

Block* heap = NULL;
Block* free_list = NULL;

void* my_malloc(size_t size);
void my_free(void* ptr);

void init_heap() {
    heap = (Block*) calloc(1, sizeof(Block) + BLOCK_SIZE);
    heap->size = BLOCK_SIZE - sizeof(Block);
    free_list = (Block*) ((char*) heap + sizeof(Block));
}

void extend_heap() {
    size_t new_size;
    Block* current = heap;

    while (current->next != NULL) {
        current = current->next;
    }

    new_size = (current->size) + BLOCK_SIZE;
    Block* new_block = (Block*) calloc(1, new_size);

    current->next = new_block;
    new_block->size = BLOCK_SIZE - sizeof(Block);
    free_list = (Block*) ((char*) new_block + sizeof(Block));
}

void* my_malloc(size_t size) {
    if (size == 0) {
        return NULL;
    }

    if (heap == NULL) {
        init_heap();
    }

    if (free_list != NULL && free_list->size >= size) {
        Block* temp = free_list;
        free_list = free_list->next;
        temp->next = NULL;
        return (void*) ((char*) temp + sizeof(Block));
    }

    while (heap != NULL && heap->size < size + sizeof(Block)) {
        extend_heap();
    }

    if (heap == NULL) {
        return NULL;
    }

    Block* new_block = heap;
    heap = heap->next;
    new_block->size = size;
    new_block->next = NULL;

    return (void*) ((char*) new_block + sizeof(Block));
}

void my_free(void* ptr) {
    if (ptr == NULL) {
        return;
    }

    Block* free_node = (Block*) ((char*) ptr - sizeof(Block));

    free_node->next = free_list;
    free_list = free_node;
}

int main() {
    char* str1 = my_malloc(10);
    char* str2 = my_malloc(20);

    strcpy(str1, "Hello");
    strcpy(str2, "World");

    printf("str1: %s, length: %ld\n", str1, strlen(str1));
    printf("str2: %s, length: %ld\n", str2, strlen(str2));

    my_free(str1);
    my_free(str2);

    return 0;
}