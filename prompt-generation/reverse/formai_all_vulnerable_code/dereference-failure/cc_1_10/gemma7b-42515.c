//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_AUTHOR 20

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, Book* newBook);
Book* searchBook(Book* head, char* title);
Book* searchAuthor(Book* head, char* author);

int main() {
    Book* head = NULL;
    Book* newBook = NULL;

    // Insert a few books
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
    if (newBook) {
        printf("Book: %s, Author: %s, Quantity: %d\n", newBook->title, newBook->author, newBook->quantity);
    } else {
        printf("Book not found.\n");
    }

    // Search for an author
    newBook = searchAuthor(head, "William Golding");
    if (newBook) {
        printf("Book: %s, Author: %s, Quantity: %d\n", newBook->title, newBook->author, newBook->quantity);
    } else {
        printf("Author not found.\n");
    }

    return 0;
}

Book* insertBook(Book* head, Book* newBook) {
    if (head == NULL) {
        head = newBook;
    } else {
        newBook->next = head;
        head = newBook;
    }

    return head;
}

Book* searchBook(Book* head, char* title) {
    Book* currentBook = head;

    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            return currentBook;
        }
        currentBook = currentBook->next;
    }

    return NULL;
}

Book* searchAuthor(Book* head, char* author) {
    Book* currentBook = head;

    while (currentBook) {
        if (strcmp(currentBook->author, author) == 0) {
            return currentBook;
        }
        currentBook = currentBook->next;
    }

    return NULL;
}