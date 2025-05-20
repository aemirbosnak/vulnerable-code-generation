//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MEMORY_POOL_SIZE 1024

typedef struct memory_block {
    void* data;
    size_t size;
    struct memory_block* next;
} memory_block_t;

memory_block_t* memory_pool = NULL;

void* alloc_memory(size_t size) {
    if (size > MEMORY_POOL_SIZE) {
        printf("Oops! Requested memory exceeds pool size! 😱\n");
        return NULL;
    }

    if (memory_pool == NULL) {
        printf("Memory pool not initialized! 🤔\n");
        return NULL;
    }

    memory_block_t* new_block = (memory_block_t*) malloc(sizeof(memory_block_t));
    new_block->data = malloc(size);
    new_block->size = size;
    new_block->next = NULL;

    if (new_block == NULL) {
        printf("Memory allocation failed! 😠\n");
        return NULL;
    }

    if (memory_pool == NULL) {
        memory_pool = new_block;
    } else {
        memory_block_t* current = memory_pool;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_block;
    }

    return new_block->data;
}

void free_memory(void* memory) {
    memory_block_t* block = (memory_block_t*) memory;
    if (block == NULL) {
        printf("Invalid memory block! 😳\n");
        return;
    }

    if (block->next == NULL) {
        memory_pool = block->next;
    } else {
        memory_block_t* current = memory_pool;
        while (current->next != block) {
            current = current->next;
        }
        current->next = block->next;
    }

    free(block->data);
    free(block);
}

int main() {
    srand(time(NULL));

    // Allocate some memory
    void* memory1 = alloc_memory(100);
    void* memory2 = alloc_memory(200);
    void* memory3 = alloc_memory(300);

    // Use the memory
    char* str1 = (char*) memory1;
    char* str2 = (char*) memory2;
    char* str3 = (char*) memory3;

    strcpy(str1, "Happy coding!");
    strcat(str2, "😊");
    strcat(str3, "🎉");

    // Free the memory
    free_memory(memory1);
    free_memory(memory2);
    free_memory(memory3);

    return 0;
}