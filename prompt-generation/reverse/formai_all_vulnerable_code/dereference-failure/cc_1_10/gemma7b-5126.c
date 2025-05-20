//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Book
{
    char title[MAX_SIZE];
    char author[MAX_SIZE];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, Book* newBook);

void displayBooks(Book* head);

int main()
{
    Book* head = NULL;
    Book* newBook;

    // Inserting books
    newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 10;
    head = insertBook(head, newBook);

    newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, "To Kill a Mockingbird");
    strcpy(newBook->author, "Harper Lee");
    newBook->quantity = 8;
    head = insertBook(head, newBook);

    newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, "The Great Gatsby");
    strcpy(newBook->author, "F. Scott Fitzgerald");
    newBook->quantity = 6;
    head = insertBook(head, newBook);

    // Displaying books
    displayBooks(head);

    return 0;
}

Book* insertBook(Book* head, Book* newBook)
{
    if (head == NULL)
    {
        return newBook;
    }

    Book* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newBook;
    return head;
}

void displayBooks(Book* head)
{
    Book* temp = head;
    while (temp)
    {
        printf("Title: %s\n", temp->title);
        printf("Author: %s\n", temp->author);
        printf("Quantity: %d\n", temp->quantity);
        printf("\n");
        temp = temp->next;
    }
}