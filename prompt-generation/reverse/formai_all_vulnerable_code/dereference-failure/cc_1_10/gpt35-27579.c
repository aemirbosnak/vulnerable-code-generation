//FormAI DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

/* Define the structure of the memory block */
typedef struct memblock {
    size_t size;
    struct memblock *next;
    int free;
    void *ptr;
} MemBlock;

/* Define the head of the memory list */
MemBlock *head = NULL;

void splitBlock(MemBlock *memoryBlock, size_t size) {
    MemBlock *newBlock = (void *)((char *)memoryBlock + size + sizeof(MemBlock));

    newBlock->size = memoryBlock->size - size - sizeof(MemBlock);
    newBlock->next = memoryBlock->next;
    newBlock->free = 1;
    newBlock->ptr = (void *)((char *)newBlock + sizeof(MemBlock));

    memoryBlock->size = size;
    memoryBlock->next = newBlock;
}

void *memalloc(size_t size) {
    MemBlock *memoryBlock = head;
    MemBlock *lastBlock = NULL;

    while (memoryBlock != NULL) {
        if (memoryBlock->free == 1 && memoryBlock->size >= size) {
            if (memoryBlock->size > size + sizeof(MemBlock)) {
                splitBlock(memoryBlock, size);
            }
            memoryBlock->free = 0;
            return memoryBlock->ptr;
        }
        lastBlock = memoryBlock;
        memoryBlock = memoryBlock->next;
    }

    /* If there is no memory block available, request more from the system */
    MemBlock *newBlock = (MemBlock *)sbrk(size + sizeof(MemBlock));
    newBlock->size = size;
    newBlock->next = NULL;
    newBlock->free = 0;
    newBlock->ptr = (void *)((char *)newBlock + sizeof(MemBlock));

    if (head == NULL) {
        head = newBlock;
    }

    if (lastBlock != NULL) {
        lastBlock->next = newBlock;
    }

    return newBlock->ptr;
}

void memfree(void *ptr) {
    if (ptr == NULL) {
        return;
    }

    MemBlock *memoryBlock = (MemBlock *)((char *)ptr - sizeof(MemBlock));
    if (memoryBlock->free == 1) {
        return;
    }

    memoryBlock->free = 1;

    if (memoryBlock->next != NULL && memoryBlock->next->free == 1) {
        memoryBlock->size += sizeof(MemBlock) + memoryBlock->next->size;
        memoryBlock->next = memoryBlock->next->next;
    }

    if (memoryBlock != head && memoryBlock->free == 1 && memoryBlock->next == NULL) {
        MemBlock *temp = head;
        while (temp->next != memoryBlock) {
            temp = temp->next;
        }

        temp->next = NULL;
        brk(memoryBlock);
    }
}

int main() {
    int *p = (int *)memalloc(sizeof(int));
    *p = 10;
    printf("*p = %d\n", *p);

    memfree(p);
    return 0;
}