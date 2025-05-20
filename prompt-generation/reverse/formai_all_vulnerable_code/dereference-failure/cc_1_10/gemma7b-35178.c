//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PHONE_NUMBER_LENGTH 20
#define MAX_NAME_LENGTH 50

typedef struct PhoneBookEntry
{
    char name[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH];
    struct PhoneBookEntry* next;
} PhoneBookEntry;

PhoneBookEntry* insertEntry(PhoneBookEntry* head, char* name, char* phoneNumber)
{
    PhoneBookEntry* newEntry = malloc(sizeof(PhoneBookEntry));
    strcpy(newEntry->name, name);
    strcpy(newEntry->phoneNumber, phoneNumber);
    newEntry->next = NULL;

    if (head == NULL)
    {
        return newEntry;
    }

    head->next = insertEntry(head->next, name, phoneNumber);
    return newEntry;
}

void searchEntry(PhoneBookEntry* head, char* name)
{
    PhoneBookEntry* currentEntry = head;

    while (currentEntry)
    {
        if (strcmp(currentEntry->name, name) == 0)
        {
            printf("Name: %s\n", currentEntry->name);
            printf("Phone Number: %s\n", currentEntry->phoneNumber);
            return;
        }

        currentEntry = currentEntry->next;
    }

    printf("Entry not found.\n");
}

int main()
{
    PhoneBookEntry* head = NULL;

    insertEntry(head, "John Doe", "555-123-4567");
    insertEntry(head, "Jane Doe", "555-456-7890");
    insertEntry(head, "Bob Smith", "555-246-3219");

    searchEntry(head, "John Doe");
    searchEntry(head, "Jane Doe");
    searchEntry(head, "Bob Smith");
    searchEntry(head, "Not Found");

    return 0;
}