//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct book {
    char title[256];
    char author[256];
    int quantity;
    struct book* next;
};

struct book* insertBook(struct book* head, char* title, char* author, int quantity) {
    struct book* newBook = malloc(sizeof(struct book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        head->next = newBook;
    }

    return head;
}

struct book* searchBook(struct book* head, char* title) {
    struct book* currentBook = head;

    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            return currentBook;
        }
        currentBook = currentBook->next;
    }

    return NULL;
}

void updateBookQuantity(struct book* book, int quantity) {
    book->quantity = quantity;
}

void deleteBook(struct book* head, char* title) {
    struct book* previousBook = NULL;
    struct book* currentBook = head;

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
    struct book* head = NULL;

    insertBook(head, "Neuromancer", "William Gibson", 5);
    insertBook(head, "The Matrix Reloaded", "The Wachowskis", 3);
    insertBook(head, "Dune", "Frank Herbert", 2);

    struct book* book = searchBook(head, "Neuromancer");
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Quantity: %d\n", book->quantity);
    }

    updateBookQuantity(book, 10);

    book = searchBook(head, "Neuromancer");
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Quantity: %d\n", book->quantity);
    }

    deleteBook(head, "Dune");

    book = searchBook(head, "Dune");
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Quantity: %d\n", book->quantity);
    }

    return 0;
}