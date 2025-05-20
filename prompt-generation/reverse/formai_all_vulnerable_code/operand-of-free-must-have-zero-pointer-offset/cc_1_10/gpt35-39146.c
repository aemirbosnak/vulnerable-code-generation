//FormAI DATASET v1.0 Category: Memory management ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define NUM_BLOCKS 100
#define BLOCK_SIZE 1000

char* memoryPool;

struct node {
    char* data;
    size_t size;
    struct node* next;
};

struct node* head = NULL;

void initMemoryPool() {
    memoryPool = (char*)malloc(NUM_BLOCKS * BLOCK_SIZE * sizeof(char));
    if (!memoryPool) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
}

void* allocate(size_t size) {
    struct node* current = head;
    struct node* prev = NULL;

    while (current) {
        if (current->size >= size) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }

            void* ptr = current->data;
            free(current);

            return ptr;
        }

        prev = current;
        current = current->next;
    }

    char* data = memoryPool;
    memoryPool += BLOCK_SIZE;
    
    struct node* block = (struct node*)malloc(sizeof(struct node));
    if (!block) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    block->data = data;
    block->size = size;
    block->next = NULL;

    return block->data;
}

void release(void* ptr) {
    if (ptr < (void*)memoryPool || ptr > (void*)(memoryPool + NUM_BLOCKS * BLOCK_SIZE)) {
        printf("Memory address is out of bounds.\n");
        return;
    }

    struct node* current = head;
    struct node* prev = NULL;
    while (current) {
        if (ptr == current->data) {
            printf("Freeing memory block at address %p.\n", ptr);

            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }

            free(current);

            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Memory block not found at address %p.\n", ptr);
}

int main() {
    initMemoryPool();

    char* ptr = (char*)allocate(200 * sizeof(char));
    printf("Allocated block of size 200 at address %p.\n", ptr);

    char* ptr2 = (char*)allocate(100 * sizeof(char));
    printf("Allocated block of size 100 at address %p.\n", ptr2);

    release(ptr);

    char* ptr3 = (char*)allocate(500 * sizeof(char));
    printf("Allocated block of size 500 at address %p.\n", ptr3);

    release(ptr2);
    release(ptr3);

    free(memoryPool);

    return 0;
}