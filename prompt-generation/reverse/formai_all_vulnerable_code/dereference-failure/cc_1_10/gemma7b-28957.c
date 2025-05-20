//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* InsertBook(Book* head, Book* newBook) {
    if (head == NULL) {
        head = newBook;
    } else {
        newBook->next = head;
        head = newBook;
    }
    return head;
}

Book* SearchBook(Book* head, char* title) {
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            return currentBook;
        }
        currentBook = currentBook->next;
    }
    return NULL;
}

Book* UpdateBookQuantity(Book* head, char* title, int quantity) {
    Book* currentBook = SearchBook(head, title);
    if (currentBook) {
        currentBook->quantity = quantity;
    }
    return head;
}

Book* DeleteBook(Book* head, char* title) {
    Book* currentBook = head;
    Book* previousBook = NULL;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            if (previousBook) {
                previousBook->next = currentBook->next;
            } else {
                head = currentBook->next;
            }
            free(currentBook);
            return head;
        }
        previousBook = currentBook;
        currentBook = currentBook->next;
    }
    return NULL;
}

int main() {
    Book* head = NULL;

    // Insert books
    Book* newBook1 = malloc(sizeof(Book));
    strcpy(newBook1->title, "The Lord of the Flies");
    strcpy(newBook1->author, "William Golding");
    newBook1->quantity = 5;
    head = InsertBook(head, newBook1);

    Book* newBook2 = malloc(sizeof(Book));
    strcpy(newBook2->title, "To Kill a Mockingbird");
    strcpy(newBook2->author, "Harper Lee");
    newBook2->quantity = 3;
    head = InsertBook(head, newBook2);

    // Search books
    Book* foundBook = SearchBook(head, "The Lord of the Flies");
    if (foundBook) {
        printf("Title: %s\n", foundBook->title);
        printf("Author: %s\n", foundBook->author);
        printf("Quantity: %d\n", foundBook->quantity);
    }

    // Update book quantity
    UpdateBookQuantity(head, "To Kill a Mockingbird", 4);

    // Search books after update
    foundBook = SearchBook(head, "To Kill a Mockingbird");
    if (foundBook) {
        printf("Title: %s\n", foundBook->title);
        printf("Author: %s\n", foundBook->author);
        printf("Quantity: %d\n", foundBook->quantity);
    }

    // Delete book
    DeleteBook(head, "The Lord of the Flies");

    // Search books after deletion
    foundBook = SearchBook(head, "The Lord of the Flies");
    if (foundBook) {
        printf("Error: book not found\n");
    }

    return 0;
}