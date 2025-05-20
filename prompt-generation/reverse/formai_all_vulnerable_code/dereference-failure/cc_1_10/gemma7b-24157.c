//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY_SIZE 10

typedef struct MemoryCell
{
    int data;
    struct MemoryCell* next;
} MemoryCell;

void initializeMemory(MemoryCell** head)
{
    *head = NULL;
}

void insertMemory(MemoryCell** head, int data)
{
    MemoryCell* newNode = malloc(sizeof(MemoryCell));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

void searchMemory(MemoryCell* head, int data)
{
    while (head)
    {
        if (head->data == data)
        {
            printf("Data found!\n");
            return;
        }
        head = head->next;
    }

    printf("Data not found.\n");
}

int main()
{
    MemoryCell* head = NULL;
    initializeMemory(&head);

    insertMemory(&head, 10);
    insertMemory(&head, 20);
    insertMemory(&head, 30);

    searchMemory(head, 20);

    return 0;
}