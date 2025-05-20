//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10

struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
};

struct Book* insertBook(struct Book* head, char* title, char* author, int quantity)
{
    struct Book* newNode = malloc(sizeof(struct Book));
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
        head->next = newNode;
    }

    return head;
}

void searchBook(struct Book* head, char* title)
{
    struct Book* currentBook = head;

    while (currentBook)
    {
        if (strcmp(currentBook->title, title) == 0)
        {
            printf("Title: %s\n", currentBook->title);
            printf("Author: %s\n", currentBook->author);
            printf("Quantity: %d\n", currentBook->quantity);
            break;
        }
        currentBook = currentBook->next;
    }

    if (currentBook == NULL)
    {
        printf("Book not found.\n");
    }
}

int main()
{
    struct Book* head = NULL;

    insertBook(head, "The Lord of the Flies", "William Golding", 5);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 10);
    insertBook(head, "To Kill a Mockingbird", "Harper Lee", 7);

    searchBook(head, "The Lord of the Flies");

    return 0;
}