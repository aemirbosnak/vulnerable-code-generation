//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: complex
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

Book* insertBook(Book* head, Book* newBook) {
    if (head == NULL) {
        head = newBook;
    } else {
        head->next = insertBook(head->next, newBook);
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

void updateQuantity(Book* book, int quantity) {
    book->quantity = quantity;
}

int main() {
    Book* head = NULL;
    Book* newBook = NULL;

    // Insert some books
    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 10;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "To Kill a Mockingbird");
    strcpy(newBook->author, "Harper Lee");
    newBook->quantity = 5;
    insertBook(head, newBook);

    // Search for a book
    newBook = searchBook(head, "The Lord of the Flies");
    if (newBook) {
        printf("Book found: %s by %s, quantity: %d\n", newBook->title, newBook->author, newBook->quantity);
    } else {
        printf("Book not found\n");
    }

    // Update book quantity
    updateQuantity(newBook, 15);

    // Search for the book again
    newBook = searchBook(head, "The Lord of the Flies");
    if (newBook) {
        printf("Book found: %s by %s, quantity: %d\n", newBook->title, newBook->author, newBook->quantity);
    } else {
        printf("Book not found\n");
    }

    return 0;
}