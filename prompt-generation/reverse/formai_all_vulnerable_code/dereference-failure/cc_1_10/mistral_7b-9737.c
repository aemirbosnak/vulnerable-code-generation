//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct MemoryBlock {
    size_t size;
    struct MemoryBlock* next;
} MemoryBlock;

MemoryBlock* head = NULL;

void print_memory_stats() {
    printf("\nCurrent memory usage:\n");
    MemoryBlock* current = head;
    size_t total = 0;

    while (current != NULL) {
        printf("Block size: %zu bytes\n", current->size);
        total += current->size;
        current = current->next;
    }

    printf("Total memory usage: %zu bytes\n", total);
}

void* cheerful_malloc(size_t size) {
    if (size == 0) {
        printf("Zero size allocation! That's a real mood booster!\n");
        return NULL;
    }

    MemoryBlock* new_block = (MemoryBlock*) malloc(sizeof(MemoryBlock) + size);

    if (new_block == NULL) {
        printf("Couldn't allocate memory, bummer!\n");
        return NULL;
    }

    new_block->size = size;
    new_block->next = head;
    head = new_block;

    printf("Allocated %zu bytes with a smile!\n", size);
    print_memory_stats();

    return (void*) (new_block + 1);
}

void cheerful_free(void* ptr) {
    if (ptr == NULL) {
        printf("Trying to free a null pointer! That's a real downer!\n");
        return;
    }

    MemoryBlock* current = head;

    while (current != NULL) {
        if ((void*) (current + 1) == ptr) {
            size_t block_size = current->size;
            void* next_block = current->next;

            free(current);
            print_memory_stats();

            printf("Freed %zu bytes and cheered up! Keep it positive!\n", block_size);
            return;
        }

        current = current->next;
    }

    printf("Invalid pointer! Let's try again with a positive mindset.\n");
}

int main() {
    char* message = cheerful_malloc(50 * sizeof(char));
    strcpy(message, "Cheerful C Memory Management");

    printf("Message allocated with %zu bytes: %s\n", strlen(message), message);

    cheerful_free(message);

    return 0;
}