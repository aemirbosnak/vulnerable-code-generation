//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: energetic
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

Book* insertBook(Book* head, Book* newBook);
void displayBooks(Book* head);
void updateQuantity(Book* book, int quantity);

int main()
{
    Book* head = NULL;
    Book* newBook;

    // Inserting books
    newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 5;
    head = insertBook(head, newBook);

    newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, "To Kill a Mockingbird");
    strcpy(newBook->author, "Harper Lee");
    newBook->quantity = 10;
    insertBook(head, newBook);

    // Displaying books
    displayBooks(head);

    // Updating quantity of a book
    updateQuantity(head->next, 15);

    // Displaying books after quantity update
    displayBooks(head);

    return 0;
}

Book* insertBook(Book* head, Book* newBook)
{
    if (head == NULL)
    {
        head = newBook;
    }
    else
    {
        newBook->next = head;
        head = newBook;
    }

    return head;
}

void displayBooks(Book* head)
{
    Book* currentBook = head;

    while (currentBook)
    {
        printf("%s by %s, quantity: %d\n", currentBook->title, currentBook->author, currentBook->quantity);
        currentBook = currentBook->next;
    }
}

void updateQuantity(Book* book, int quantity)
{
    book->quantity = quantity;
}