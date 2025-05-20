//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1024

typedef struct Entry {
    char name[256];
    struct Entry* next;
} Entry;

Entry* head = NULL;

void insert(char* name)
{
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    strcpy(newEntry->name, name);
    newEntry->next = head;
    head = newEntry;
}

int search(char* name)
{
    Entry* current = head;
    while (current)
    {
        if (strcmp(current->name, name) == 0)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main()
{
    insert("John Doe");
    insert("Jane Doe");
    insert("Bob Smith");

    if (search("John Doe"))
    {
        printf("John Doe is in the list.\n");
    }

    if (search("Bob Smith"))
    {
        printf("Bob Smith is in the list.\n");
    }

    return 0;
}