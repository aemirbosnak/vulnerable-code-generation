//Gemma-7B DATASET v1.0 Category: Memory management ; Style: portable
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY 1024

typedef struct MemoryBlock {
    struct MemoryBlock* next;
    char* data;
    int size;
} MemoryBlock;

MemoryBlock* head = NULL;

void* allocate(int size)
{
    if (size < 1)
    {
        return NULL;
    }

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

    return newBlock->data;
}

void free(void* ptr)
{
    MemoryBlock* current = head;
    MemoryBlock* previous = NULL;

    while (current)
    {
        if (current->data == ptr)
        {
            if (previous)
            {
                previous->next = current->next;
            }
            else
            {
                head = current->next;
            }

            free(current);
            return;
        }

        previous = current;
        current = current->next;
    }

    return;
}

int main()
{
    allocate(50);
    allocate(20);
    allocate(30);
    free(allocate(10));
    free(allocate(20));

    return 0;
}