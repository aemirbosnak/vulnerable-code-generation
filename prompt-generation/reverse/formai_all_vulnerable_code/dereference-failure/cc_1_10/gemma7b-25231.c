//Gemma-7B DATASET v1.0 Category: Memory management ; Style: energetic
#include <stdlib.h>

#define MAX_MEMORY 1024

typedef struct MemoryBlock
{
    struct MemoryBlock* next;
    void* data;
    int size;
} MemoryBlock;

MemoryBlock* head = NULL;

void* allocate(int size)
{
    MemoryBlock* newBlock = (MemoryBlock*)malloc(sizeof(MemoryBlock) + size);
    newBlock->size = size;

    if (head == NULL)
    {
        head = newBlock;
    }
    else
    {
        head->next = newBlock;
        head = newBlock;
    }

    return (void*)newBlock->data;
}

void free(void* ptr)
{
    MemoryBlock* block = head;

    while (block)
    {
        if (block->data == ptr)
        {
            free(block);
            block = NULL;
        }
        else
        {
            block = block->next;
        }
    }

    if (block == NULL)
    {
        printf("Error: pointer not found.\n");
    }
}

int main()
{
    allocate(10);
    allocate(20);
    allocate(30);

    free(allocate(40));
    free(allocate(50));

    return 0;
}