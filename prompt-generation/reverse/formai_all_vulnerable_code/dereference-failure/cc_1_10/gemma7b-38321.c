//Gemma-7B DATASET v1.0 Category: Memory management ; Style: retro
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
    newBlock->next = NULL;
    newBlock->data = (void*)((char*)newBlock + sizeof(MemoryBlock));

    if (head == NULL) {
        head = newBlock;
    } else {
        head->next = newBlock;
        head = newBlock;
    }

    return newBlock->data;
}

void free(void* ptr) {
    MemoryBlock* current = head;
    MemoryBlock* previous = NULL;

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
    void* ptr = allocate(20);
    printf("Pointer: %p\n", ptr);

    free(ptr);
    printf("Pointer after free: %p\n", ptr);

    return 0;
}