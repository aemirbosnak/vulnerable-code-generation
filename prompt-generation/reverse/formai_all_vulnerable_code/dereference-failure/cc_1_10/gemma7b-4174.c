//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book
{
    char title[50];
    char author[50];
    char genre[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, Book* newBook);
Book* searchBook(Book* head, char* title);
void updateBookQuantity(Book* head, char* title, int quantity);
void deleteBook(Book* head, char* title);

int main()
{
    Book* head = NULL;

    // Insert some books
    Book* newBook1 = malloc(sizeof(Book));
    strcpy(newBook1->title, "Neuromancer");
    strcpy(newBook1->author, "William Gibson");
    strcpy(newBook1->genre, "Cyberpunk");
    newBook1->quantity = 5;
    insertBook(head, newBook1);

    Book* newBook2 = malloc(sizeof(Book));
    strcpy(newBook2->title, "The Matrix Reloaded");
    strcpy(newBook2->author, "The Wachowskis");
    strcpy(newBook2->genre, "Action");
    newBook2->quantity = 3;
    insertBook(head, newBook2);

    // Search for a book
    Book* foundBook = searchBook(head, "Neuromancer");
    if (foundBook)
    {
        printf("Found book: %s by %s\n", foundBook->title, foundBook->author);
    }

    // Update book quantity
    updateBookQuantity(head, "The Matrix Reloaded", 4);
    foundBook = searchBook(head, "The Matrix Reloaded");
    if (foundBook)
    {
        printf("Updated book quantity: %d\n", foundBook->quantity);
    }

    // Delete a book
    deleteBook(head, "Neuromancer");
    foundBook = searchBook(head, "Neuromancer");
    if (foundBook)
    {
        printf("Book deleted: %s by %s\n", foundBook->title, foundBook->author);
    }

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

void updateBookQuantity(Book* head, char* title, int quantity)
{
    Book* foundBook = searchBook(head, title);
    if (foundBook)
    {
        foundBook->quantity = quantity;
    }
}

void deleteBook(Book* head, char* title)
{
    Book* previousBook = NULL;
    Book* currentBook = head;

    while (currentBook)
    {
        if (strcmp(currentBook->title, title) == 0)
        {
            if (previousBook)
            {
                previousBook->next = currentBook->next;
            }
            else
            {
                head = currentBook->next;
            }

            free(currentBook);
            currentBook = NULL;
        }
        else
        {
            previousBook = currentBook;
            currentBook = currentBook->next;
        }
    }
}