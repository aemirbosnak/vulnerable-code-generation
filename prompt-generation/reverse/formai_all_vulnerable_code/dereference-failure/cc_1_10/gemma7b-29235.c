//Gemma-7B DATASET v1.0 Category: Memory management ; Style: active
#include <stdlib.h>
#include <stdio.h>

// Define a memory management structure
typedef struct MemBlock {
    struct MemBlock* next;
    void* data;
    int size;
} MemBlock;

// Global variable to store the head of the memory management list
MemBlock* head = NULL;

// Function to allocate memory
void* alloc(int size) {
    MemBlock* newBlock = malloc(sizeof(MemBlock) + size);
    newBlock->next = head;
    head = newBlock;
    newBlock->size = size;
    newBlock->data = (void*) ((char*)newBlock + sizeof(MemBlock));
    return newBlock->data;
}

// Function to free memory
void free(void* ptr) {
    MemBlock* current = head;
    MemBlock* previous = NULL;

    while (current) {
        if (current->data == ptr) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    return;
}

int main() {
    // Allocate memory for a few blocks
    void* a = alloc(10);
    void* b = alloc(20);
    void* c = alloc(30);

    // Use the memory blocks
    printf("Block A size: %d\n", (int)a);
    printf("Block B size: %d\n", (int)b);
    printf("Block C size: %d\n", (int)c);

    // Free the memory blocks
    free(c);
    free(b);
    free(a);

    return 0;
}