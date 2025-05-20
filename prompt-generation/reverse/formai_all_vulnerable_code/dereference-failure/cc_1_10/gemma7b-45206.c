//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct PhoneBookEntry
{
    char name[MAX_NAME_LENGTH];
    int phone_number;
    struct PhoneBookEntry* next;
} PhoneBookEntry;

PhoneBookEntry* createEntry(char* name, int phone_number)
{
    PhoneBookEntry* newEntry = malloc(sizeof(PhoneBookEntry));

    strcpy(newEntry->name, name);
    newEntry->phone_number = phone_number;
    newEntry->next = NULL;

    return newEntry;
}

void addEntry(PhoneBookEntry* head, char* name, int phone_number)
{
    PhoneBookEntry* newEntry = createEntry(name, phone_number);

    if (head == NULL)
    {
        head = newEntry;
    }
    else
    {
        head->next = newEntry;
    }
}

void searchEntry(PhoneBookEntry* head, char* name)
{
    PhoneBookEntry* currentEntry = head;

    while (currentEntry)
    {
        if (strcmp(currentEntry->name, name) == 0)
        {
            printf("Name: %s, Phone Number: %d\n", currentEntry->name, currentEntry->phone_number);
            return;
        }
        currentEntry = currentEntry->next;
    }

    printf("No entry found for name: %s\n", name);
}

int main()
{
    PhoneBookEntry* head = NULL;

    addEntry(head, "John Doe", 12345);
    addEntry(head, "Jane Doe", 67890);
    addEntry(head, "Bill Smith", 32146);

    searchEntry(head, "Jane Doe");
    searchEntry(head, "Bob Smith");

    return 0;
}