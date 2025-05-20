//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20

typedef struct Entry
{
    char name[MAX_NAME_LENGTH];
    char message[500];
    struct Entry* next;
} Entry;

Entry* head = NULL;

void addEntry(char* name, char* message)
{
    Entry* newEntry = malloc(sizeof(Entry));

    strcpy(newEntry->name, name);
    strcpy(newEntry->message, message);

    newEntry->next = head;
    head = newEntry;
}

void displayEntries()
{
    Entry* currentEntry = head;

    while (currentEntry)
    {
        printf("Name: %s\n", currentEntry->name);
        printf("Message: %s\n", currentEntry->message);
        printf("\n");

        currentEntry = currentEntry->next;
    }
}

int main()
{
    addEntry("Johnny Chrome", "I'm the king of the road!");
    addEntry("Miss Scarlet", "A goddess of mystery.");
    addEntry("Mr. Big", "A mysterious figure with a dark past.");

    displayEntries();

    return 0;
}