//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

struct PhoneBookEntry
{
    char name[50];
    char number[20];
    struct PhoneBookEntry* next;
};

struct PhoneBookEntry* insertEntry(struct PhoneBookEntry* head, char* name, char* number)
{
    struct PhoneBookEntry* newEntry = (struct PhoneBookEntry*)malloc(sizeof(struct PhoneBookEntry));
    strcpy(newEntry->name, name);
    strcpy(newEntry->number, number);
    newEntry->next = NULL;

    if (head == NULL)
    {
        head = newEntry;
    }
    else
    {
        struct PhoneBookEntry* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newEntry;
    }

    return head;
}

void printEntries(struct PhoneBookEntry* head)
{
    struct PhoneBookEntry* temp = head;
    while (temp)
    {
        printf("%s - %s\n", temp->name, temp->number);
        temp = temp->next;
    }
}

int main()
{
    struct PhoneBookEntry* phoneBook = NULL;

    phoneBook = insertEntry(phoneBook, "John Doe", "123-456-7890");
    phoneBook = insertEntry(phoneBook, "Jane Doe", "456-789-0123");
    phoneBook = insertEntry(phoneBook, "Bill Smith", "321-456-7890");

    printEntries(phoneBook);

    return 0;
}