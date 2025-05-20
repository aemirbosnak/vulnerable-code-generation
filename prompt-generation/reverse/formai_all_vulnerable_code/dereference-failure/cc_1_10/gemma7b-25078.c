//Gemma-7B DATASET v1.0 Category: Memory management ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 1024

typedef struct MemoryBlock {
    struct MemoryBlock* next;
    void* data;
    int size;
} MemoryBlock;

MemoryBlock* head = NULL;

void* allocate(int size) {
    MemoryBlock* newBlock = (MemoryBlock*)malloc(sizeof(MemoryBlock) + size);
    newBlock->size = size;
    newBlock->next = head;
    head = newBlock;
    return (void*)newBlock->data;
}

void free(void* ptr) {
    MemoryBlock* current = head;
    MemoryBlock* previous = NULL;

    while (current) {
        if (ptr == current->data) {
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

    printf("Error: pointer not found\n");
    return;
}

int main() {
    allocate(10);
    allocate(20);
    allocate(30);
    allocate(40);

    free(allocate(50));

    return 0;
}