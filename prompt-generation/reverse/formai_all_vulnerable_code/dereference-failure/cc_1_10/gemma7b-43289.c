//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the Indexing System Structure
typedef struct IndexingSystem
{
    int key;
    struct IndexingSystem* next;
} IndexingSystem;

// Function to insert a key into the indexing system
void insertKey(IndexingSystem** head, int key)
{
    IndexingSystem* newNode = malloc(sizeof(IndexingSystem));
    newNode->key = key;
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

// Function to search for a key in the indexing system
int searchKey(IndexingSystem* head, int key)
{
    while (head)
    {
        if (head->key == key)
        {
            return 1;
        }
        else
        {
            head = head->next;
        }
    }

    return 0;
}

int main()
{
    IndexingSystem* head = NULL;

    // Insert keys into the indexing system
    insertKey(&head, 10);
    insertKey(&head, 20);
    insertKey(&head, 30);
    insertKey(&head, 40);

    // Search for a key in the indexing system
    if (searchKey(head, 30) == 1)
    {
        printf("Key found.\n");
    }
    else
    {
        printf("Key not found.\n");
    }

    return 0;
}