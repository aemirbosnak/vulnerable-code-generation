//Falcon-180B DATASET v1.0 Category: Memory management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the size of memory block
#define SIZE 100

// Define the structure of memory block
typedef struct {
    char *data;
    int size;
} MemoryBlock;

// Initialize the memory block with default data
void initMemoryBlock(MemoryBlock *block) {
    block->data = (char*) malloc(block->size);
    if (block->data == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    strcpy(block->data, "Default data");
}

// Allocate memory block
MemoryBlock* allocateMemoryBlock() {
    MemoryBlock *block = (MemoryBlock*) malloc(sizeof(MemoryBlock));
    if (block == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    initMemoryBlock(block);
    return block;
}

// Free memory block
void freeMemoryBlock(MemoryBlock *block) {
    free(block->data);
    free(block);
}

// Copy memory block
MemoryBlock* copyMemoryBlock(MemoryBlock *src) {
    MemoryBlock *dest = allocateMemoryBlock();
    strcpy(dest->data, src->data);
    return dest;
}

// Concatenate memory blocks
MemoryBlock* concatenateMemoryBlocks(MemoryBlock *dest, MemoryBlock *src) {
    int dest_size = strlen(dest->data);
    int src_size = strlen(src->data);
    MemoryBlock *result = (MemoryBlock*) malloc(sizeof(MemoryBlock));
    result->data = (char*) malloc(dest_size + src_size + 1);
    if (result->data == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    strcpy(result->data, dest->data);
    strcat(result->data, src->data);
    result->size = dest_size + src_size;
    freeMemoryBlock(dest);
    freeMemoryBlock(src);
    return result;
}

int main() {
    MemoryBlock *block1 = allocateMemoryBlock();
    MemoryBlock *block2 = allocateMemoryBlock();
    MemoryBlock *block3 = copyMemoryBlock(block1);
    MemoryBlock *block4 = concatenateMemoryBlocks(block2, block3);
    printf("Block1: %s\n", block1->data);
    printf("Block2: %s\n", block2->data);
    printf("Block3: %s\n", block3->data);
    printf("Block4: %s\n", block4->data);
    freeMemoryBlock(block1);
    freeMemoryBlock(block2);
    freeMemoryBlock(block3);
    freeMemoryBlock(block4);
    return 0;
}