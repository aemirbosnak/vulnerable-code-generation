//FormAI DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Size of memory
#define MAX_SIZE 1024

// Memory block structure
typedef struct memoryBlock {
    int start;
    int end;
    struct memoryBlock* next;
    struct memoryBlock* prev;
} memoryBlock;

// Global memory block pointers
memoryBlock* memoryStart = NULL;
memoryBlock* memoryEnd = NULL;

// Function to print the memory blocks
void printMemoryBlocks() {
    printf("Memory Blocks: ");
    memoryBlock* curr = memoryStart;
    while (curr != NULL) {
        printf("[%d,%d] ", curr->start, curr->end);
        curr = curr->next;
    }
    printf("\n");
}

// Function to initialize the memory
void initializeMemory() {
    memoryStart = (memoryBlock*)malloc(sizeof(memoryBlock));
    memoryEnd = (memoryBlock*)malloc(sizeof(memoryBlock));
    memoryStart->start = 0;
    memoryStart->end = MAX_SIZE - 1;
    memoryStart->next = memoryEnd;
    memoryStart->prev = NULL;
    memoryEnd->start = MAX_SIZE;
    memoryEnd->end = MAX_SIZE + 1;
    memoryEnd->next = NULL;
    memoryEnd->prev = memoryStart;
}

// Function to split a memory block
void splitBlock(memoryBlock* block, int size) {
    int oldEnd = block->end;
    block->end = block->start + size - 1;
    memoryBlock* newBlock = (memoryBlock*)malloc(sizeof(memoryBlock));
    newBlock->start = block->end + 1;
    newBlock->end = oldEnd;
    newBlock->next = block->next;
    newBlock->prev = block;
    block->next->prev = newBlock;
    block->next = newBlock;
}

// Function to free a memory block
void freeMemory(memoryBlock* block) {
    block->prev->next = block->next;
    block->next->prev = block->prev;
    free(block);
}

// Function to allocate memory
void* allocateMemory(int size) {
    memoryBlock* curr = memoryStart;
    while (curr != NULL) {
        if (curr->end - curr->start + 1 >= size) {
            if (curr->end - curr->start + 1 == size) {
                void* ptr = (void*)(long)curr->start;
                freeMemory(curr);
                return ptr;
            }
            splitBlock(curr, size);
            void* ptr = (void*)(long)curr->start;
            return ptr;
        }
        curr = curr->next;
    }
    return NULL;
}

int main() {
    initializeMemory();
    printMemoryBlocks();

    int* ptr1 = (int*)allocateMemory(sizeof(int) * 5);
    printf("Allocated 20 bytes of memory starting at address %p\n", ptr1);
    printMemoryBlocks();

    int* ptr2 = (int*)allocateMemory(sizeof(int) * 3);
    printf("Allocated 12 bytes of memory starting at address %p\n", ptr2);
    printMemoryBlocks();

    int* ptr3 = (int*)allocateMemory(sizeof(int) * 2);
    printf("Allocated 8 bytes of memory starting at address %p\n", ptr3);
    printMemoryBlocks();

    free(ptr2);
    printf("Freed memory starting at address %p\n", ptr2);
    printMemoryBlocks();

    void* ptr4 = allocateMemory(sizeof(int) * 3);
    printf("Allocated 12 bytes of memory starting at address %p\n", ptr4);
    printMemoryBlocks();

    freeMemory(memoryStart->next);
    printf("Freed memory starting at address %p\n", memoryStart->next);
    printMemoryBlocks();

    int* ptr5 = (int*)allocateMemory(sizeof(int) * 2);
    printf("Allocated 8 bytes of memory starting at address %p\n", ptr5);
    printMemoryBlocks();

    free(ptr1);
    free(ptr3);
    free(ptr4);
    free(ptr5);

    return 0;
}