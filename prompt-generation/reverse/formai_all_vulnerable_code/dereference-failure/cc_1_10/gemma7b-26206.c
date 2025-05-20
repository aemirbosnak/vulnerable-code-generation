//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Claude Shannon
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

Book* insertBook(Book* head, char* title, char* author, int quantity)
{
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
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

void updateBookQuantity(Book* book, int newQuantity)
{
    book->quantity = newQuantity;
}

void deleteBook(Book* head, Book* bookToDelete)
{
    Book* previousBook = NULL;

    if (bookToDelete == head)
    {
        head = bookToDelete->next;
    }
    else
    {
        previousBook = bookToDelete->next;
        previousBook->next = bookToDelete->next;
    }

    free(bookToDelete);
}

int main()
{
    Book* head = NULL;

    insertBook(head, "The Lord of the Flies", "William Golding", 5);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 3);
    insertBook(head, "The Catcher in the Rye", "J.D. Salinger", 4);

    Book* book = searchBook(head, "The Lord of the Flies");
    updateBookQuantity(book, 10);

    deleteBook(head, book);

    return 0;
}