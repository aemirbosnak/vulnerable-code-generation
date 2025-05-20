//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, Book* newBook) {
    if (head == NULL) {
        head = newBook;
    } else {
        head->next = insertBook(head->next, newBook);
    }

    return head;
}

Book* searchBook(Book* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        } else {
            head = head->next;
        }
    }

    return NULL;
}

void updateBookQuantity(Book* head, char* title, int quantity) {
    Book* book = searchBook(head, title);

    if (book) {
        book->quantity = quantity;
    }
}

void printBooks(Book* head) {
    while (head) {
        printf("%s by %s, quantity: %d\n", head->title, head->author, head->quantity);
        head = head->next;
    }
}

int main() {
    Book* head = NULL;

    // Insert books
    Book* newBook1 = malloc(sizeof(Book));
    strcpy(newBook1->title, "Neuromancer");
    strcpy(newBook1->author, "William Gibson");
    newBook1->quantity = 5;
    insertBook(head, newBook1);

    Book* newBook2 = malloc(sizeof(Book));
    strcpy(newBook2->title, "The Matrix Reloaded");
    strcpy(newBook2->author, "The Wachowskis");
    newBook2->quantity = 2;
    insertBook(head, newBook2);

    // Search book
    Book* book = searchBook(head, "Neuromancer");
    if (book) {
        printf("Book found: %s by %s, quantity: %d\n", book->title, book->author, book->quantity);
    }

    // Update book quantity
    updateBookQuantity(head, "The Matrix Reloaded", 3);

    // Print books
    printBooks(head);

    return 0;
}