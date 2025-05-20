//Gemma-7B DATASET v1.0 Category: RAM usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define RAM_SIZE 1024
#define CACHE_SIZE 64

typedef struct MemBlock {
    int used;
    struct MemBlock *next;
} MemBlock;

MemBlock *head = NULL;

void allocMemBlock(int size) {
    MemBlock *newBlock = (MemBlock *)malloc(sizeof(MemBlock) + size);
    newBlock->used = 0;
    newBlock->next = NULL;

    if (head == NULL) {
        head = newBlock;
    } else {
        head->next = newBlock;
        head = newBlock;
    }
}

void freeMemBlock(int size) {
    MemBlock *prev = NULL;
    MemBlock *curr = head;

    while (curr) {
        if (curr->used < size) {
            prev = curr;
            curr = curr->next;
        } else {
            break;
        }
    }

    if (prev) {
        prev->next = curr->next;
        free(curr);
    } else {
        head = curr->next;
        free(curr);
    }
}

int main() {
    allocMemBlock(CACHE_SIZE);
    allocMemBlock(RAM_SIZE - CACHE_SIZE);

    freeMemBlock(CACHE_SIZE);

    return 0;
}