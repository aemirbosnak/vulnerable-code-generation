//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    struct Block* next;
    char data[1];
} Block;

Block* head = NULL;

void print_memory() {
    Block* current = head;
    printf("Memory blocks:\n");
    while (current != NULL) {
        printf("Block size: %ld, Data: %s\n", current->size, (current->data));
        current = current->next;
    }
}

void* my_malloc(size_t size) {
    if (size == 0) {
        fprintf(stderr, "Error: size is zero\n");
        return NULL;
    }

    Block* new_block = (Block*)calloc(1, sizeof(Block) + size);
    if (new_block == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        return NULL;
    }

    new_block->size = size;
    new_block->next = head;
    head = new_block;

    return (void*)(new_block->data);
}

void my_free(void* ptr) {
    Block* current = head;
    Block* previous = NULL;

    while (current != NULL && current->data < (char*)ptr) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        fprintf(stderr, "Error: Memory block not found\n");
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

int main() {
    char* str1 = (char*)my_malloc(50 * sizeof(char));
    char* str2 = (char*)my_malloc(100 * sizeof(char));

    strcpy(str1, "Hello World!");
    strcpy(str2, "This is a minimalist C memory management example.");

    print_memory();

    my_free(str1);
    my_free(str2);

    print_memory();

    return 0;
}