//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_ENTRIES 100

typedef struct IndexEntry
{
    char key[20];
    int data_index;
    struct IndexEntry* next;
} IndexEntry;

IndexEntry* insert_index_entry(IndexEntry* head, char* key, int data_index)
{
    IndexEntry* new_entry = malloc(sizeof(IndexEntry));
    strcpy(new_entry->key, key);
    new_entry->data_index = data_index;
    new_entry->next = NULL;

    if (head == NULL)
    {
        head = new_entry;
    }
    else
    {
        IndexEntry* current = head;
        IndexEntry* previous = NULL;

        while (current)
        {
            if (strcmp(current->key, key) < 0)
            {
                previous = current;
                current = current->next;
            }
            else if (strcmp(current->key, key) == 0)
            {
                return NULL;
            }
        }

        previous->next = new_entry;
    }

    return head;
}

int main()
{
    IndexEntry* head = NULL;

    insert_index_entry(head, "abc", 10);
    insert_index_entry(head, "def", 20);
    insert_index_entry(head, "ghi", 30);
    insert_index_entry(head, "jkl", 40);

    IndexEntry* current = head;

    while (current)
    {
        printf("%s - %d\n", current->key, current->data_index);
        current = current->next;
    }

    return 0;
}