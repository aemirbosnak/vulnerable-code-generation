//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    char genre[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    scanf("Enter book title: ", newBook->title);
    scanf("Enter book author: ", newBook->author);
    scanf("Enter book genre: ", newBook->genre);
    scanf("Enter book quantity: ", &newBook->quantity);

    newBook->next = head;
    head = newBook;

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

void updateBookQuantity(Book* book, int quantity) {
    book->quantity = quantity;
}

void deleteBook(Book* head, char* title) {
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
            return;
        }
        previousBook = currentBook;
        currentBook = currentBook->next;
    }

    return;
}

int main() {
    Book* head = NULL;

    // Insert books
    insertBook(head);
    insertBook(head);
    insertBook(head);

    // Search books
    Book* book = searchBook(head, "Book 2");
    if (book) {
        printf("Book title: %s\n", book->title);
        printf("Book author: %s\n", book->author);
        printf("Book genre: %s\n", book->genre);
        printf("Book quantity: %d\n", book->quantity);
    }

    // Update book quantity
    updateBookQuantity(book, 10);

    // Delete book
    deleteBook(head, "Book 2");

    return 0;
}