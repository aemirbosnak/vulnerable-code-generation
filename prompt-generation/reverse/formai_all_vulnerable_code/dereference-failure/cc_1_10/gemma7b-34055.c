//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ENTRIES 10
#define MAX_STRING_LENGTH 255

typedef struct Entry
{
    char name[MAX_STRING_LENGTH];
    struct Entry* next;
} Entry;

Entry* createEntry(char* name)
{
    Entry* entry = malloc(sizeof(Entry));
    strcpy(entry->name, name);
    entry->next = NULL;
    return entry;
}

void addToEntries(Entry* head, char* name)
{
    Entry* newEntry = createEntry(name);
    if (head == NULL)
    {
        head = newEntry;
    }
    else
    {
        head->next = newEntry;
    }
    head = newEntry;
}

int main()
{
    Entry* head = NULL;

    // Generate a list of entries
    addToEntries(head, "Mr. Jones");
    addToEntries(head, "Ms. Smith");
    addToEntries(head, "Mr. Brown");
    addToEntries(head, "Ms. Johnson");

    // Print the entries
    Entry* currentEntry = head;
    while (currentEntry)
    {
        printf("%s\n", currentEntry->name);
        currentEntry = currentEntry->next;
    }

    return 0;
}