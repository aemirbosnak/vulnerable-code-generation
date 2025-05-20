//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: curious
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
        Book* currentBook = head;
        while (currentBook->next) {
            currentBook = currentBook->next;
        }
        currentBook->next = newBook;
    }
    return head;
}

void searchBook(Book* head, char* title) {
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            printf("Book: %s, Author: %s, Quantity: %d\n", currentBook->title, currentBook->author, currentBook->quantity);
        }
        currentBook = currentBook->next;
    }
}

int main() {
    Book* head = NULL;
    Book* newBook = malloc(sizeof(Book));
    newBook->quantity = 5;
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    newBook->quantity = 3;
    strcpy(newBook->title, "The Great Gatsby");
    strcpy(newBook->author, "F. Scott Fitzgerald");
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    newBook->quantity = 2;
    strcpy(newBook->title, "The Catcher in the Rye");
    strcpy(newBook->author, "J.D. Salinger");
    insertBook(head, newBook);

    searchBook(head, "The Lord of the Flies");

    return 0;
}