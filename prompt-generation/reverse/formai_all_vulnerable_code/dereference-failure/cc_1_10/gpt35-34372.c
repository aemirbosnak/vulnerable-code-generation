//FormAI DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

/* A structure to hold information about a memory block */
typedef struct MemoryBlock {
    void* address;      // The starting address of the block
    size_t size;        // The size of the block in bytes
    struct MemoryBlock* next;    // A pointer to the next block in the list
} MemoryBlock;

/* A structure to hold information about all memory blocks */
typedef struct MemoryList {
    int count;                  // The number of memory blocks in the list
    MemoryBlock* firstBlock;    // A pointer to the first block in the list
} MemoryList;

/* A function to create a new memory block */
MemoryBlock* createMemoryBlock(void* address, size_t size) {
    MemoryBlock* block = malloc(sizeof(MemoryBlock)); // allocate memory for the new block
    if(block) {
        block->address = address;
        block->size = size;
        block->next = NULL;
    }
    return block;
}

/* A function to add a new memory block to the list */
void addMemoryBlock(MemoryList* list, MemoryBlock* block) {
    if(!list->firstBlock) {
        list->firstBlock = block;
    } else {
        block->next = list->firstBlock;
        list->firstBlock = block;
    }
    list->count++;
}

/* A function to remove a memory block from the list */
void removeMemoryBlock(MemoryList* list, MemoryBlock* block) {
    if(list->firstBlock == block) {
        list->firstBlock = block->next;
    } else {
        MemoryBlock* currBlock = list->firstBlock;
        while(currBlock && currBlock->next != block) {
            currBlock = currBlock->next;
        }
        if(currBlock) {
            currBlock->next = block->next;
        }
    }
    block->next = NULL;
    list->count--;
}

/* A function to get the first memory block from the list that can hold a given size */
MemoryBlock* getAvailableMemoryBlock(MemoryList* list, size_t size) {
    MemoryBlock* currBlock = list->firstBlock;
    while(currBlock) {
        if(currBlock->size >= size) {
            return currBlock;
        }
        currBlock = currBlock->next;
    }
    return NULL;
}

/* A function to allocate memory of a given size */
void* myAlloc(size_t size, MemoryList* list) {
    MemoryBlock* block = getAvailableMemoryBlock(list, size);
    if(!block) {
        void* newBlockAddress = malloc(size);
        if(newBlockAddress) {
            block = createMemoryBlock(newBlockAddress, size);
            addMemoryBlock(list, block);
        } else {
            return NULL;
        }
    }
    removeMemoryBlock(list, block);
    return block->address;
}

/* A function to free memory allocated using myAlloc */
void myFree(void* address, MemoryList* list) {
    MemoryBlock* block = createMemoryBlock(address, 0);    // Create a temporary block to search for the actual block with the given address
    MemoryBlock* currBlock = list->firstBlock;
    while(currBlock && currBlock->address != address) {
        currBlock = currBlock->next;
    }
    if(currBlock) {
        addMemoryBlock(list, currBlock);    // Add the block back to the list
    }
    free(block);    // Free the temporary block
}

int main() {
    MemoryList list = {0, NULL};

    int* ptr1 = myAlloc(sizeof(int), &list);
    if(ptr1) {
        *ptr1 = 123;
        printf("Allocated memory at address: %p, value: %d\n", ptr1, *ptr1);
    }

    int* ptr2 = myAlloc(sizeof(int) * 10, &list);
    if(ptr2) {
        for(int i = 0; i < 10; i++) {
            ptr2[i] = i * 2;
        }
        printf("Allocated memory at address: %p, values: ", ptr2);
        for(int i = 0; i < 10; i++) {
            printf("%d ", ptr2[i]);
        }
        printf("\n");
    }

    myFree(ptr1, &list);
    myFree(ptr2, &list);

    return 0;
}