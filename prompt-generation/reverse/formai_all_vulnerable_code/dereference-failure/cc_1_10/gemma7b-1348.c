//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: innovative
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct PhoneBookEntry
{
    char name[MAX_NAME_LENGTH];
    char number[20];
    struct PhoneBookEntry* next;
} PhoneBookEntry;

PhoneBookEntry* InsertEntry(PhoneBookEntry* head, char* name, char* number)
{
    PhoneBookEntry* newEntry = (PhoneBookEntry*)malloc(sizeof(PhoneBookEntry));
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
    }

    return head;
}

void PrintEntries(PhoneBookEntry* head)
{
    PhoneBookEntry* currentEntry = head;
    while (currentEntry)
    {
        printf("%s: %s\n", currentEntry->name, currentEntry->number);
        currentEntry = currentEntry->next;
    }
}

int main()
{
    PhoneBookEntry* phoneBook = NULL;

    InsertEntry(phoneBook, "John Doe", "123-456-7890");
    InsertEntry(phoneBook, "Jane Doe", "456-789-0123");
    InsertEntry(phoneBook, "Bill Smith", "987-654-3210");

    PrintEntries(phoneBook);

    return 0;
}