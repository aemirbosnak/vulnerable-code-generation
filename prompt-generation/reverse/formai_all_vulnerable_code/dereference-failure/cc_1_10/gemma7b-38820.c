//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

typedef struct Book
{
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head)
{
    Book* newBook = (Book*)malloc(sizeof(Book));
    scanf("%s", newBook->title);
    scanf("%s", newBook->author);
    scanf("%d", &newBook->quantity);
    newBook->next = NULL;

    if (head == NULL)
    {
        head = newBook;
    }
    else
    {
        head->next = newBook;
    }

    return head;
}

Book* searchBook(Book* head, char* title)
{
    Book* currentBook = head;

    while (currentBook)
    {
        if (strcmp(currentBook->title, title) == 0)
        {
            return currentBook;
        }

        currentBook = currentBook->next;
    }

    return NULL;
}

int main()
{
    Book* head = NULL;

    // Insert books into the library
    insertBook(head);
    insertBook(head);
    insertBook(head);

    // Search for a book
    Book* foundBook = searchBook(head, "Book 2");

    // Print the book information
    if (foundBook)
    {
        printf("Title: %s\n", foundBook->title);
        printf("Author: %s\n", foundBook->author);
        printf("Quantity: %d\n", foundBook->quantity);
    }
    else
    {
        printf("Book not found.\n");
    }

    return 0;
}