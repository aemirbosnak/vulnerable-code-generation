//FormAI DATASET v1.0 Category: Memory management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 500

// Structure to represent each block of memory
typedef struct Block {
    int size;
    struct Block *prev;
    struct Block *next;
    char data[BLOCK_SIZE];
} Block;

// Global variables to keep track of the head and tail blocks
Block *head;
Block *tail;

// Helper function to split a block into two separate blocks
void splitBlock(Block *block, int size) {
    if (block->size <= size || size <= 0) {
        return;
    }

    Block *newBlock = (Block*) malloc(sizeof(Block));
    newBlock->size = block->size - size - sizeof(Block);
    newBlock->prev = block;
    newBlock->next = block->next;

    if (block->next != NULL) {
        block->next->prev = newBlock;
    } else {
        tail = newBlock;
    }

    block->size = size;
    block->next = newBlock;
}

// Function to allocate a block of size 'size' bytes
void *myMalloc(int size) {
    if (size <= 0) {
        return NULL;
    }

    // First fit algorithm to find a large enough free block of memory
    Block *current = head;
    while (current != NULL) {
        if (current->size >= size) {
            splitBlock(current, size);
            return current->data;
        }
        current = current->next;
    }

    // If no free block was found, allocate a new block of memory from the OS
    Block *newBlock = (Block*) malloc(sizeof(Block) + size);
    if (newBlock == NULL) {
        return NULL;
    }
    newBlock->size = size;
    newBlock->next = NULL;
    newBlock->prev = tail;

    if (tail != NULL) {
        tail->next = newBlock;
    } else {
        head = newBlock;
    }

    tail = newBlock;

    return newBlock->data;
}

// Function to free a previously allocated block of memory
void myFree(void *ptr) {
    Block *current = head;
    while (current != NULL) {
        if (current->data == ptr) {
            current->size = 0;

            // Combine adjacent free blocks together
            if (current->prev != NULL && current->prev->size == 0) {
                current->prev->size += sizeof(Block) + current->size;
                current->prev->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                current = current->prev;
            }
            if (current->next != NULL && current->next->size == 0) {
                current->size += sizeof(Block) + current->next->size;
                current->next = current->next->next;
                if (current->next != NULL) {
                    current->next->prev = current;
                } else {
                    tail = current;
                }
            }
            return;
        }
        current = current->next;
    }
}

int main() {
    // Example usage of myMalloc and myFree
    int *arr = (int*)myMalloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    myFree(arr);

    return 0;
}