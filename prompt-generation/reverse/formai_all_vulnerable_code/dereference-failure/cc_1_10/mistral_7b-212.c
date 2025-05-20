//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    struct Block* next;
    char data[1];
} Block;

Block* head = NULL;

void* my_malloc(size_t size) {
    if (size == 0) {
        fprintf(stderr, "Invalid size\n");
        return NULL;
    }

    Block* new_block = (Block*) malloc(sizeof(Block) + size);
    if (!new_block) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    new_block->size = size;
    new_block->next = head;
    head = new_block;

    return (void*) (new_block + 1);
}

void my_free(void* ptr) {
    Block* prev = NULL;
    Block* current = head;

    while (current != NULL) {
        if ((void*)(current + 1) == ptr) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

size_t my_heap_size() {
    Block* current = head;
    size_t size = 0;

    while (current != NULL) {
        size += current->size + sizeof(Block);
        current = current->next;
    }

    return size;
}

size_t my_num_allocated_blocks() {
    Block* current = head;
    size_t count = 0;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void my_print_allocated_blocks() {
    Block* current = head;

    printf("Details of allocated memory blocks:\n");
    printf("------------------------------------\n");

    while (current != NULL) {
        printf("Block address: %p\n", current);
        printf("Size: %zu bytes\n", current->size);
        printf("Data address: %p\n", (void*)(current + 1));
        current = current->next;
    }
}

int main() {
    char* str1 = my_malloc(20);
    char* str2 = my_malloc(30);

    if (str1 == NULL || str2 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    strcpy(str1, "Hello, World!");
    strcpy(str2, "This is a C program.");

    printf("Allocated strings:\n");
    printf("--------------------\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    my_print_allocated_blocks();

    my_free(str1);
    my_free(str2);

    my_print_allocated_blocks();

    printf("Size of heap: %zu bytes\n", my_heap_size());
    printf("Number of allocated blocks: %zu\n", my_num_allocated_blocks());

    return 0;
}