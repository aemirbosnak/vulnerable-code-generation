//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct PhoneBookEntry
{
    char name[MAX_NAME_LENGTH];
    char number[MAX_NAME_LENGTH];
    struct PhoneBookEntry* next;
} PhoneBookEntry;

PhoneBookEntry* head = NULL;

void insertEntry(char* name, char* number)
{
    PhoneBookEntry* newEntry = malloc(sizeof(PhoneBookEntry));

    strcpy(newEntry->name, name);
    strcpy(newEntry->number, number);

    newEntry->next = NULL;

    if (head == NULL)
    {
        head = newEntry;
    }
    else
    {
        head->next = newEntry;
        head = newEntry;
    }
}

void searchEntry(char* name)
{
    PhoneBookEntry* currentEntry = head;

    while (currentEntry)
    {
        if (strcmp(currentEntry->name, name) == 0)
        {
            printf("Name: %s\n", currentEntry->name);
            printf("Number: %s\n", currentEntry->number);
            return;
        }
        currentEntry = currentEntry->next;
    }

    printf("No entry found for name: %s\n", name);
}

int main()
{
    insertEntry("John Doe", "555-123-4567");
    insertEntry("Jane Doe", "555-234-5678");
    insertEntry("Peter Pan", "555-345-6789");

    searchEntry("John Doe");

    return 0;
}