//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char name[20];
    struct node *next;
} Node;

typedef struct phonebook
{
    Node *head;
    int count;
} PhoneBook;

PhoneBook *createPhoneBook()
{
    PhoneBook *book = (PhoneBook*)malloc(sizeof(PhoneBook));
    book->head = NULL;
    book->count = 0;
    return book;
}

void addNameToPhoneBook(PhoneBook *book, char *name)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    
    if (book->head == NULL)
    {
        book->head = newNode;
        book->count++;
    }
    else
    {
        Node *current = book->head;
        while (current->next!= NULL)
            current = current->next;
        
        current->next = newNode;
        book->count++;
    }
}

void printPhoneBook(PhoneBook *book)
{
    if (book == NULL)
    {
        printf("Phone book is empty!\n");
        return;
    }
    
    Node *current = book->head;
    while (current!= NULL)
    {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main()
{
    PhoneBook *phoneBook = createPhoneBook();
    addNameToPhoneBook(phoneBook, "John");
    addNameToPhoneBook(phoneBook, "Jane");
    addNameToPhoneBook(phoneBook, "Mike");
    printPhoneBook(phoneBook);
    return 0;
}