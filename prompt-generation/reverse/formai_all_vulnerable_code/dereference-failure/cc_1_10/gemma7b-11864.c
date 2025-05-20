//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME_LENGTH 25
#define MAX_PHONE_NUMBER_LENGTH 20

typedef struct PhoneBookEntry
{
    char name[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH];
    struct PhoneBookEntry* nextEntry;
} PhoneBookEntry;

PhoneBookEntry* createEntry(char* name, char* phoneNumber)
{
    PhoneBookEntry* newEntry = malloc(sizeof(PhoneBookEntry));

    strcpy(newEntry->name, name);
    strcpy(newEntry->phoneNumber, phoneNumber);

    newEntry->nextEntry = NULL;

    return newEntry;
}

PhoneBookEntry* insertEntry(PhoneBookEntry* head, char* name, char* phoneNumber)
{
    PhoneBookEntry* newEntry = createEntry(name, phoneNumber);

    if (head == NULL)
    {
        head = newEntry;
    }
    else
    {
        PhoneBookEntry* currentEntry = head;

        while (currentEntry->nextEntry)
        {
            currentEntry = currentEntry->nextEntry;
        }

        currentEntry->nextEntry = newEntry;
    }

    return head;
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

        currentEntry = currentEntry->nextEntry;
    }

    printf("Entry not found.\n");
}

int main()
{
    PhoneBookEntry* head = NULL;

    insertEntry(head, "John Doe", "555-123-4567");
    insertEntry(head, "Jane Doe", "555-234-5678");
    insertEntry(head, "Bill Smith", "555-345-6789");

    searchEntry(head, "John Doe");

    return 0;
}