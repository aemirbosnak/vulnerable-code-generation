//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Book
{
    char title[20];
    char author[20];
    int quantity;
    struct Book* next;
};

struct Book* insertBook(struct Book* head, char* title, char* author, int quantity)
{
    struct Book* newNode = (struct Book*)malloc(sizeof(struct Book));
    strcpy(newNode->title, title);
    strcpy(newNode->author, author);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Book* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

struct Book* searchBook(struct Book* head, char* title)
{
    struct Book* temp = head;
    while (temp)
    {
        if (strcmp(temp->title, title) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

void displayBooks(struct Book* head)
{
    struct Book* temp = head;
    while (temp)
    {
        printf("%s by %s, quantity: %d\n", temp->title, temp->author, temp->quantity);
        temp = temp->next;
    }
}

int main()
{
    struct Book* head = NULL;

    insertBook(head, "Book 1", "Author 1", 10);
    insertBook(head, "Book 2", "Author 2", 20);
    insertBook(head, "Book 3", "Author 3", 30);

    displayBooks(head);

    struct Book* book = searchBook(head, "Book 2");

    if (book)
    {
        printf("Book found: %s by %s, quantity: %d\n", book->title, book->author, book->quantity);
    }
    else
    {
        printf("Book not found.\n");
    }

    return 0;
}