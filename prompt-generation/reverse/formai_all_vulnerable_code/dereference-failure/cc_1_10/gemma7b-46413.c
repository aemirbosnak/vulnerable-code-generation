//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: scalable
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

void searchBook(Book* head, char* title) {
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            printf("Title: %s\n", currentBook->title);
            printf("Author: %s\n", currentBook->author);
            printf("Quantity: %d\n", currentBook->quantity);
            break;
        }
        currentBook = currentBook->next;
    }
    if (currentBook == NULL) {
        printf("Book not found.\n");
    }
}

void updateBookQuantity(Book* head, char* title, int quantity) {
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            currentBook->quantity = quantity;
            break;
        }
        currentBook = currentBook->next;
    }
    if (currentBook == NULL) {
        printf("Book not found.\n");
    }
}

int main() {
    Book* head = NULL;
    Book* newBook = NULL;

    // Insert some books
    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 5;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "To Kill a Mockingbird");
    strcpy(newBook->author, "Harper Lee");
    newBook->quantity = 10;
    insertBook(head, newBook);

    // Search for a book
    searchBook(head, "To Kill a Mockingbird");

    // Update book quantity
    updateBookQuantity(head, "The Lord of the Flies", 10);

    // Search for the updated book quantity
    searchBook(head, "The Lord of the Flies");

    return 0;
}