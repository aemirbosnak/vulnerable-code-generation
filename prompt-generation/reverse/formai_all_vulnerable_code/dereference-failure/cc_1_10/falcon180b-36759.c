//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int size;
    void *ptr;
} MemoryBlock;

MemoryBlock *memory = NULL;
int numBlocks = 0;

void init() {
    memory = (MemoryBlock *)malloc(sizeof(MemoryBlock));
    strcpy(memory->name, "Main Memory");
    memory->size = MAX_SIZE;
    memory->ptr = (void *)0;
    numBlocks++;
}

void addBlock(char *name, int size) {
    MemoryBlock *newBlock = (MemoryBlock *)malloc(sizeof(MemoryBlock));
    strcpy(newBlock->name, name);
    newBlock->size = size;
    newBlock->ptr = (void *)0;
    numBlocks++;
}

void removeBlock(char *name) {
    int i;
    for (i = 0; i < numBlocks; i++) {
        if (strcmp(memory[i].name, name) == 0) {
            free(memory[i].ptr);
            free(memory[i].name);
            free(memory[i].ptr);
            numBlocks--;
            return;
        }
    }
}

void *allocate(int size) {
    int i;
    for (i = 0; i < numBlocks; i++) {
        if (memory[i].size >= size) {
            void *ptr = (void *)((int)memory[i].ptr + memory[i].size - size);
            memory[i].size -= size;
            return ptr;
        }
    }
    printf("Out of memory!\n");
    exit(0);
}

void deallocate(void *ptr) {
    int i;
    for (i = 0; i < numBlocks; i++) {
        if (memory[i].ptr == ptr) {
            memory[i].size += ((int)ptr - (int)memory[i].ptr);
            return;
        }
    }
}

int main() {
    init();
    addBlock("Cyberdeck Memory", 256);
    addBlock("Neural Lace", 1024);
    void *ptr1 = allocate(64);
    void *ptr2 = allocate(512);
    deallocate(ptr1);
    deallocate(ptr2);
    removeBlock("Cyberdeck Memory");
    return 0;
}