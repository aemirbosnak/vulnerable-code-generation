//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INDEX_ENTRIES 1024

typedef struct IndexEntry
{
    char key[256];
    struct IndexEntry* next;
} IndexEntry;

IndexEntry* insertIndexEntry(IndexEntry* head, char* key)
{
    IndexEntry* newEntry = malloc(sizeof(IndexEntry));
    strcpy(newEntry->key, key);
    newEntry->next = NULL;

    if (head == NULL)
    {
        head = newEntry;
    }
    else
    {
        IndexEntry* current = head;
        IndexEntry* previous = NULL;

        while (current)
        {
            if (strcmp(current->key, key) == 0)
            {
                return NULL;
            }

            previous = current;
            current = current->next;
        }

        previous->next = newEntry;
    }

    return head;
}

int main()
{
    IndexEntry* head = NULL;

    insertIndexEntry(head, "John Doe");
    insertIndexEntry(head, "Jane Doe");
    insertIndexEntry(head, "Jack Smith");

    IndexEntry* current = head;

    while (current)
    {
        printf("%s\n", current->key);
        current = current->next;
    }

    return 0;
}