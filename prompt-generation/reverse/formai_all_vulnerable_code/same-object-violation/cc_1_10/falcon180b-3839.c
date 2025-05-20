//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_MEMORY_BLOCKS 1000
#define MAX_BLOCK_SIZE 1024 * 1024 // 1 MB

typedef struct {
    void* start;
    size_t size;
} MemoryBlock;

MemoryBlock blocks[MAX_MEMORY_BLOCKS];
int numBlocks = 0;
size_t totalMemory = 0;

bool isAllocated(void* ptr) {
    for (int i = 0; i < numBlocks; i++) {
        if (blocks[i].start <= ptr && blocks[i].start + blocks[i].size >= ptr) {
            return true;
        }
    }
    return false;
}

void addBlock(void* start, size_t size) {
    if (numBlocks >= MAX_MEMORY_BLOCKS) {
        printf("Error: Too many memory blocks\n");
        return;
    }
    blocks[numBlocks].start = start;
    blocks[numBlocks].size = size;
    numBlocks++;
    totalMemory += size;
}

void removeBlock(void* start, size_t size) {
    for (int i = 0; i < numBlocks; i++) {
        if (blocks[i].start == start && blocks[i].size == size) {
            numBlocks--;
            totalMemory -= size;
            for (int j = i; j < numBlocks; j++) {
                blocks[j] = blocks[j + 1];
            }
            return;
        }
    }
}

void printBlocks() {
    printf("Total memory: %zu bytes\n", totalMemory);
    printf("Number of blocks: %d\n", numBlocks);
    printf("Memory blocks:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("Block %d: %p - %p (%zu bytes)\n", i, blocks[i].start, blocks[i].start + blocks[i].size, blocks[i].size);
    }
}

int main() {
    addBlock((void*)0x100000, 1024 * 1024);
    addBlock((void*)0x200000, 1024 * 1024);
    addBlock((void*)0x300000, 1024 * 1024);
    printBlocks();

    removeBlock((void*)0x200000, 1024 * 1024);
    printBlocks();

    void* ptr = malloc(1024);
    if (isAllocated(ptr)) {
        printf("Allocated memory at %p\n", ptr);
    } else {
        printf("Memory not allocated\n");
    }

    free(ptr);
    printBlocks();

    return 0;
}