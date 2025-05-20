//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// A custom memory allocator that provides a simple interface to manage memory.
typedef struct {
    void* memory;
    size_t size;
} MemoryBlock;

MemoryBlock* allocate(size_t size) {
    MemoryBlock* block = malloc(sizeof(MemoryBlock));
    block->memory = malloc(size);
    block->size = size;
    return block;
}

void deallocate(MemoryBlock* block) {
    free(block->memory);
    free(block);
}

// A simple linked list that stores MemoryBlocks.
typedef struct Node {
    MemoryBlock* block;
    struct Node* next;
} Node;

Node* head = NULL;

// Adds a MemoryBlock to the linked list.
void push(MemoryBlock* block) {
    Node* node = malloc(sizeof(Node));
    node->block = block;
    node->next = head;
    head = node;
}

// Removes a MemoryBlock from the linked list.
void pop(MemoryBlock* block) {
    Node* current = head;
    Node* previous = NULL;
    while (current && current->block != block) {
        previous = current;
        current = current->next;
    }
    if (current) {
        if (previous) {
            previous->next = current->next;
        } else {
            head = current->next;
        }
        free(current);
    }
}

// Prints the memory usage of each MemoryBlock in the linked list.
void printMemoryUsage() {
    Node* current = head;
    while (current) {
        printf("Memory block: %p, size: %zu\n", current->block->memory, current->block->size);
        current = current->next;
    }
}

int main() {
    // Allocate some memory blocks.
    MemoryBlock* block1 = allocate(100);
    MemoryBlock* block2 = allocate(200);
    MemoryBlock* block3 = allocate(300);

    // Push the memory blocks to the linked list.
    push(block1);
    push(block2);
    push(block3);

    // Print the memory usage.
    printMemoryUsage();

    // Pop a memory block from the linked list.
    pop(block2);

    // Print the memory usage.
    printMemoryUsage();

    // Deallocate the remaining memory blocks.
    deallocate(block1);
    deallocate(block3);

    return 0;
}