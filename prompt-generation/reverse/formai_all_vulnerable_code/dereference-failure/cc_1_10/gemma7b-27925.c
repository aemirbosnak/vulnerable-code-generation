//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

struct PhoneBookEntry
{
    char name[20];
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

int main()
{
    struct PhoneBookEntry* head = NULL;

    insertEntry(head, "John Doe", "123-456-7890");
    insertEntry(head, "Jane Doe", "456-789-0123");
    insertEntry(head, "Bill Smith", "321-548-9642");

    struct PhoneBookEntry* currentEntry = head;
    while (currentEntry)
    {
        printf("%s - %s\n", currentEntry->name, currentEntry->number);
        currentEntry = currentEntry->next;
    }

    return 0;
}