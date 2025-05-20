//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: portable
#include <stdio.h>
#include <string.h>

struct PhoneBookEntry
{
    char name[50];
    char number[20];
    struct PhoneBookEntry* next;
};

void insertEntry(struct PhoneBookEntry** head, char* name, char* number)
{
    struct PhoneBookEntry* newEntry = (struct PhoneBookEntry*)malloc(sizeof(struct PhoneBookEntry));
    strcpy(newEntry->name, name);
    strcpy(newEntry->number, number);
    newEntry->next = NULL;

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
            printf("Number: %s\n", head->number);
            return;
        }
        head = head->next;
    }

    printf("Entry not found.\n");
}

int main()
{
    struct PhoneBookEntry* head = NULL;

    insertEntry(&head, "John Doe", "123-456-7890");
    insertEntry(&head, "Jane Doe", "456-789-0123");
    insertEntry(&head, "Bill Smith", "789-012-3456");

    searchEntry(head, "John Doe");

    return 0;
}