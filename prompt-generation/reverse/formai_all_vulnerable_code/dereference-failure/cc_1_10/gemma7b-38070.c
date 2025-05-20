//Gemma-7B DATASET v1.0 Category: Memory management ; Style: statistical
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_MEMORY 1024

typedef struct MemoryBlock {
    void *data;
    struct MemoryBlock *next;
} MemoryBlock;

MemoryBlock *head = NULL;

void *allocate(int size) {
    MemoryBlock *newBlock = malloc(sizeof(MemoryBlock) + size);
    newBlock->data = (void *) ((char *)newBlock + sizeof(MemoryBlock));
    newBlock->next = NULL;

    if (head == NULL) {
        head = newBlock;
    } else {
        head->next = newBlock;
        head = newBlock;
    }

    return newBlock->data;
}

void free(void *ptr) {
    MemoryBlock *block = head;
    MemoryBlock *prev = NULL;

    while (block) {
        if (block->data == ptr) {
            if (prev) {
                prev->next = block->next;
            } else {
                head = block->next;
            }

            free(block);
            return;
        }

        prev = block;
        block = block->next;
    }

    return;
}

int main() {
    allocate(10);
    allocate(20);
    allocate(30);
    allocate(40);

    free(allocate(50));
    free(allocate(60));

    return 0;
}