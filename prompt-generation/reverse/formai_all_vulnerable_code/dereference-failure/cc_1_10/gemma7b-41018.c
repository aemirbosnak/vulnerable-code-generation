//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    char genre[50];
    int quantity;
    struct Book* next;
};

struct Book* insertBook(struct Book* head, char* title, char* author, char* genre, int quantity);
struct Book* searchBook(struct Book* head, char* title);
struct Book* deleteBook(struct Book* head, char* title);
struct Book* updateQuantity(struct Book* head, char* title, int quantity);

int main()
{
    struct Book* head = NULL;

    // Insert some books
    insertBook(&head, "The Lord of the Flies", "William Golding", "Fiction", 10);
    insertBook(&head, "The Great Gatsby", "F. Scott Fitzgerald", "Fiction", 15);
    insertBook(&head, "The Hobbit", "J.R.R. Tolkien", "Fantasy", 20);

    // Search for a book
    struct Book* book = searchBook(head, "The Lord of the Flies");
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Genre: %s\n", book->genre);
        printf("Quantity: %d\n", book->quantity);
    } else {
        printf("Book not found.\n");
    }

    // Delete a book
    deleteBook(head, "The Great Gatsby");

    // Update quantity of a book
    updateQuantity(head, "The Hobbit", 25);

    return 0;
}

struct Book* insertBook(struct Book* head, char* title, char* author, char* genre, int quantity)
{
    struct Book* newBook = malloc(sizeof(struct Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->genre, genre);
    newBook->quantity = quantity;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        struct Book* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newBook;
    }

    return head;
}

struct Book* searchBook(struct Book* head, char* title)
{
    struct Book* temp = head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

struct Book* deleteBook(struct Book* head, char* title)
{
    struct Book* temp = head;
    struct Book* prev = NULL;

    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
    }

    return NULL;
}

struct Book* updateQuantity(struct Book* head, char* title, int quantity)
{
    struct Book* book = searchBook(head, title);
    if (book) {
        book->quantity = quantity;
    }

    return head;
}