//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book
{
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, Book* newBook)
{
    if (head == NULL)
    {
        head = newBook;
    }
    else
    {
        head->next = insertBook(head->next, newBook);
    }
    return head;
}

Book* searchBook(Book* head, char* title)
{
    while (head)
    {
        if (strcmp(head->title, title) == 0)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

int main()
{
    Book* head = NULL;
    Book* newBook;

    // Insert some books
    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 5;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Great Gatsby");
    strcpy(newBook->author, "F. Scott Fitzgerald");
    newBook->quantity = 3;
    insertBook(head, newBook);

    // Search for a book
    newBook = searchBook(head, "The Lord of the Flies");
    if (newBook)
    {
        printf("Book found: %s by %s\n", newBook->title, newBook->author);
    }
    else
    {
        printf("Book not found.\n");
    }

    return 0;
}