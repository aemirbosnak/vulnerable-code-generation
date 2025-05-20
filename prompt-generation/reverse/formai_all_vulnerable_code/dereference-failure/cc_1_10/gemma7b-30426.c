//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store phone book entries
struct phoneBookEntry
{
    char name[20];
    char number[20];
    struct phoneBookEntry* next;
};

// Create a function to insert a new entry into the phone book
void insertEntry(struct phoneBookEntry** head, char* name, char* number)
{
    struct phoneBookEntry* newEntry = (struct phoneBookEntry*)malloc(sizeof(struct phoneBookEntry));
    strcpy(newEntry->name, name);
    strcpy(newEntry->number, number);
    newEntry->next = NULL;

    if (*head == NULL)
    {
        *head = newEntry;
    }
    else
    {
        (*head)->next = newEntry;
    }
}

// Create a function to search for a phone book entry
struct phoneBookEntry* searchEntry(struct phoneBookEntry* head, char* name)
{
    struct phoneBookEntry* currentEntry = head;

    while (currentEntry)
    {
        if (strcmp(currentEntry->name, name) == 0)
        {
            return currentEntry;
        }
        currentEntry = currentEntry->next;
    }

    return NULL;
}

int main()
{
    struct phoneBookEntry* head = NULL;

    // Insert some entries into the phone book
    insertEntry(&head, "John Doe", "555-123-4567");
    insertEntry(&head, "Jane Doe", "555-234-5678");
    insertEntry(&head, "Bill Smith", "555-345-6789");

    // Search for an entry in the phone book
    struct phoneBookEntry* entry = searchEntry(head, "Jane Doe");

    // Print the entry information
    if (entry)
    {
        printf("Name: %s\n", entry->name);
        printf("Number: %s\n", entry->number);
    }
    else
    {
        printf("Entry not found.\n");
    }

    return 0;
}