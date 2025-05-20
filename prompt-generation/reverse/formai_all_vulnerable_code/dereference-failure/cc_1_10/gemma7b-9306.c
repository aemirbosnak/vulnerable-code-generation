//Gemma-7B DATASET v1.0 Category: Memory management ; Style: statistical
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_MEMORY 1024

typedef struct MemoryBlock {
    struct MemoryBlock* next;
    void* data;
    int size;
} MemoryBlock;

MemoryBlock* createMemoryBlock(int size) {
    MemoryBlock* newBlock = malloc(sizeof(MemoryBlock) + size);
    newBlock->next = NULL;
    newBlock->data = (void*) ((char*)newBlock + sizeof(MemoryBlock));
    newBlock->size = size;
    return newBlock;
}

void freeMemoryBlock(MemoryBlock* block) {
    free(block);
}

int main() {
    MemoryBlock* head = NULL;
    int i = 0;

    for (i = 0; i < MAX_MEMORY; i++) {
        MemoryBlock* newBlock = createMemoryBlock(i);
        newBlock->data = (void*) rand();
        newBlock->size = rand() % 10;

        if (head == NULL) {
            head = newBlock;
        } else {
            head->next = newBlock;
            head = newBlock;
        }
    }

    head = NULL;

    for (i = 0; i < MAX_MEMORY; i++) {
        MemoryBlock* block = head;

        while (block) {
            if (block->size == i) {
                freeMemoryBlock(block);
                block = NULL;
            } else {
                block = block->next;
            }
        }
    }

    return 0;
}