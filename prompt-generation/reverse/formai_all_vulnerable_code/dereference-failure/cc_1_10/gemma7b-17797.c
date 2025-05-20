//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_ENTRIES 100
#define MAX_INDEX_SIZE 10

typedef struct Entry
{
    char name[20];
    int index;
    struct Entry* next;
} Entry;

Entry* head = NULL;

void insertEntry(char* name)
{
    Entry* newNode = malloc(sizeof(Entry));
    strcpy(newNode->name, name);
    newNode->index = head ? head->index + 1 : 0;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->next = newNode;
        head = newNode;
    }
}

int searchEntry(char* name)
{
    Entry* current = head;

    while (current)
    {
        if (strcmp(current->name, name) == 0)
        {
            return current->index;
        }
        current = current->next;
    }

    return -1;
}

int main()
{
    insertEntry("Bob");
    insertEntry("Alice");
    insertEntry("Tom");

    int index = searchEntry("Alice");

    if (index != -1)
    {
        printf("Index of Alice: %d\n", index);
    }

    return 0;
}