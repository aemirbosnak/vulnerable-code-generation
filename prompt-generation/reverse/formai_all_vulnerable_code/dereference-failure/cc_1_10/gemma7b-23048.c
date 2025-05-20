//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

struct PhoneBookEntry
{
    char name[20];
    int number;
    struct PhoneBookEntry* next;
};

void insertEntry(struct PhoneBookEntry** head, char* name, int number)
{
    struct PhoneBookEntry* newEntry = malloc(sizeof(struct PhoneBookEntry));

    strcpy(newEntry->name, name);
    newEntry->number = number;

    if (*head == NULL)
    {
        *head = newEntry;
    }
    else
    {
        (*head)->next = newEntry;
    }
}

void searchEntry(struct PhoneBookEntry* head, char* name)
{
    while (head)
    {
        if (strcmp(head->name, name) == 0)
        {
            printf("Name: %s\n", head->name);
            printf("Number: %d\n", head->number);
            return;
        }
        head = head->next;
    }

    printf("Entry not found.\n");
}

int main()
{
    struct PhoneBookEntry* head = NULL;

    insertEntry(&head, "John Doe", 12345);
    insertEntry(&head, "Jane Doe", 67890);
    insertEntry(&head, "Jack Doe", 41236);

    searchEntry(head, "Jane Doe");

    return 0;
}