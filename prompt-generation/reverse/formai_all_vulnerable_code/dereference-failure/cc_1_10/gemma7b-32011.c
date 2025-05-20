//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_ENTRIES 1024
#define MAX_INDEX_KEY_LENGTH 255

typedef struct IndexEntry
{
    char key[MAX_INDEX_KEY_LENGTH];
    int index;
    struct IndexEntry* next;
} IndexEntry;

IndexEntry* CreateIndexEntry(char* key, int index)
{
    IndexEntry* newEntry = malloc(sizeof(IndexEntry));
    strcpy(newEntry->key, key);
    newEntry->index = index;
    newEntry->next = NULL;

    return newEntry;
}

void InsertIndexEntry(IndexEntry* head, char* key, int index)
{
    IndexEntry* newEntry = CreateIndexEntry(key, index);

    if (head == NULL)
    {
        head = newEntry;
    }
    else
    {
        IndexEntry* currentEntry = head;
        IndexEntry* previousEntry = NULL;

        while (currentEntry)
        {
            if (strcmp(currentEntry->key, key) == 0)
            {
                currentEntry->index = index;
                return;
            }

            previousEntry = currentEntry;
            currentEntry = currentEntry->next;
        }

        previousEntry->next = newEntry;
    }
}

int SearchIndexEntry(IndexEntry* head, char* key)
{
    IndexEntry* currentEntry = head;

    while (currentEntry)
    {
        if (strcmp(currentEntry->key, key) == 0)
        {
            return currentEntry->index;
        }

        currentEntry = currentEntry->next;
    }

    return -1;
}

int main()
{
    IndexEntry* head = NULL;

    InsertIndexEntry(head, "John Doe", 1);
    InsertIndexEntry(head, "Jane Doe", 2);
    InsertIndexEntry(head, "Bob Smith", 3);

    int index = SearchIndexEntry(head, "John Doe");

    if (index != -1)
    {
        printf("Index of John Doe: %d", index);
    }

    return 0;
}