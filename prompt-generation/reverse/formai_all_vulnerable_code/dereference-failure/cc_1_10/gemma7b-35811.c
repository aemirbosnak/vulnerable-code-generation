//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: portable
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
        newBook->next = head;
        head = newBook;
    }
    return head;
}

void displayBooks(Book* head) {
    Book* currentBook = head;
    while (currentBook) {
        printf("%s by %s, Quantity: %d\n", currentBook->title, currentBook->author, currentBook->quantity);
        currentBook = currentBook->next;
    }
}

int main() {
    Book* head = NULL;
    Book* newBook;

    // Inserting books
    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 10;
    head = insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "To Kill a Mockingbird");
    strcpy(newBook->author, "Harper Lee");
    newBook->quantity = 8;
    head = insertBook(head, newBook);

    // Displaying books
    displayBooks(head);

    return 0;
}