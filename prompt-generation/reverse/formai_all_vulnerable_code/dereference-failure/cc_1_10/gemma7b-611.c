//Gemma-7B DATASET v1.0 Category: Memory management ; Style: funny
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_MEMORY 1024

typedef struct MemoryBlock {
    struct MemoryBlock* next;
    void* data;
    int size;
} MemoryBlock;

MemoryBlock* head = NULL;

void* allocate(int size) {
    MemoryBlock* newBlock = (MemoryBlock*)malloc(sizeof(MemoryBlock) + size);
    newBlock->next = head;
    head = newBlock;
    newBlock->size = size;
    return (void*)newBlock->data;
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
    void* ptr = allocate(10);
    strcpy(ptr, "Hello, world!");
    printf("%s\n", ptr);

    free(ptr);
    ptr = allocate(20);
    strcpy(ptr, "Goodbye, world!");
    printf("%s\n", ptr);

    free(ptr);

    return 0;
}