//FormAI DATASET v1.0 Category: Memory management ; Style: portable
#include <stdio.h>
#include <stdlib.h>

typedef struct memory_block {
    int tag;
    int size;
    void* address;
} MemBlock;

void* myMalloc(int size);
void myFree(void* ptr);
void printMemBlocks();
void defragMemory();

#define MEMORY_SIZE 1024
char memory[MEMORY_SIZE];
MemBlock* blocks[MEMORY_SIZE/sizeof(MemBlock)];
int numBlocks;

void* myMalloc(int size) {
    // check if there's enough space
    if (numBlocks * sizeof(MemBlock) + size > MEMORY_SIZE) {
        printf("Error: Memory full\n");
        return NULL;
    }

    // allocate memory
    void* ptr = memory + numBlocks * sizeof(MemBlock);
    blocks[numBlocks] = (MemBlock*) ptr;
    blocks[numBlocks]->tag = 1;
    blocks[numBlocks]->size = size;
    blocks[numBlocks]->address = ptr + sizeof(MemBlock);
    numBlocks++;

    return blocks[numBlocks-1]->address;
}

void myFree(void* ptr) {
    // find block with matching address
    int i;
    for (i = 0; i < numBlocks; i++) {
        if (blocks[i]->address == ptr) {
            free(blocks[i]->address);
            blocks[i]->tag = 0;
            return;
        }
    }
    printf("Error: Invalid address\n");
}

void printMemBlocks() {
    printf("Memory Blocks:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("Block %d: Tag: %d, Size: %d, Address: %p\n", i, blocks[i]->tag, blocks[i]->size, blocks[i]->address);
    }
}

void defragMemory() {
    int i, j;
    for (i = 0; i < numBlocks; i++) {
        if (blocks[i]->tag == 0) {
            // find next used block
            for (j = i+1; j < numBlocks; j++) {
                if (blocks[j]->tag == 1) {
                    // move block to free space
                    int bytesToMove = blocks[j]->size + sizeof(MemBlock);
                    memcpy(blocks[i], blocks[j], bytesToMove);
                    blocks[j]->tag = 0;
                    break;
                }
            }
        }
    }
}

int main() {
    printf("Memory Size: %d bytes\n", MEMORY_SIZE);

    // allocate some memory
    void* p1 = myMalloc(100);
    void* p2 = myMalloc(200);
    printf("Allocated p1, size: %d, address: %p\n", 100, p1);
    printf("Allocated p2, size: %d, address: %p\n", 200, p2);
    printMemBlocks();

    // free some memory
    myFree(p1);
    printf("Freed p1\n");
    printMemBlocks();

    // allocate some more memory
    void* p3 = myMalloc(50);
    printf("Allocated p3, size: %d, address: %p\n", 50, p3);
    printMemBlocks();

    // defragment memory
    defragMemory();
    printf("Defragmented memory\n");
    printMemBlocks();

    return 0;
}