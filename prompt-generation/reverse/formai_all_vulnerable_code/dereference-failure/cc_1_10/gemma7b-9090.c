//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <string.h>

struct PhoneBook
{
    char name[50];
    char number[20];
    struct PhoneBook* next;
};

void insertPhoneBook(struct PhoneBook** head, char* name, char* number)
{
    struct PhoneBook* newNode = malloc(sizeof(struct PhoneBook));

    strcpy(newNode->name, name);
    strcpy(newNode->number, number);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
        *head = newNode;
    }
}

void searchPhoneBook(struct PhoneBook* head, char* name)
{
    struct PhoneBook* current = head;

    while (current)
    {
        if (strcmp(current->name, name) == 0)
        {
            printf("Number: %s\n", current->number);
            return;
        }
        current = current->next;
    }

    printf("Name not found.\n");
}

int main()
{
    struct PhoneBook* phoneBook = NULL;

    insertPhoneBook(&phoneBook, "John Doe", "123-456-7890");
    insertPhoneBook(&phoneBook, "Jane Doe", "456-789-0123");
    insertPhoneBook(&phoneBook, "Peter Pan", "555-123-4567");

    searchPhoneBook(phoneBook, "John Doe");
    searchPhoneBook(phoneBook, "Jane Doe");
    searchPhoneBook(phoneBook, "Peter Pan");

    return 0;
}