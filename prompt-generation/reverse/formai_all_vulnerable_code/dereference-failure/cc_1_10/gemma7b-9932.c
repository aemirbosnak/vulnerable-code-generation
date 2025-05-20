//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct PhoneBookEntry
{
    char name[20];
    int number;
    struct PhoneBookEntry* nextEntry;
};

void insertEntry(struct PhoneBookEntry** head, char* name, int number)
{
    struct PhoneBookEntry* newNode = (struct PhoneBookEntry*)malloc(sizeof(struct PhoneBookEntry));
    strcpy(newNode->name, name);
    newNode->number = number;
    newNode->nextEntry = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        insertEntry(head, name, number);
    }
}

void searchEntry(struct PhoneBookEntry* head, char* name)
{
    if (head == NULL)
    {
        return;
    }

    if (strcmp(head->name, name) == 0)
    {
        printf("Name: %s, Number: %d\n", head->name, head->number);
        return;
    }

    searchEntry(head->nextEntry, name);
}

int main()
{
    struct PhoneBookEntry* phoneBook = NULL;

    insertEntry(&phoneBook, "John Doe", 12345);
    insertEntry(&phoneBook, "Jane Doe", 67890);
    insertEntry(&phoneBook, "Peter Pan", 24680);

    searchEntry(phoneBook, "Jane Doe");

    return 0;
}