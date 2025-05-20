//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Ken Thompson
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

Book* findBook(Book* head, char* title) {
    for (Book* currentBook = head; currentBook; currentBook = currentBook->next) {
        if (strcmp(currentBook->title, title) == 0) {
            return currentBook;
        }
    }
    return NULL;
}

void updateBookQuantity(Book* book, int newQuantity) {
    book->quantity = newQuantity;
}

void printBookList(Book* head) {
    for (Book* currentBook = head; currentBook; currentBook = currentBook->next) {
        printf("%s by %s (quantity: %d)\n", currentBook->title, currentBook->author, currentBook->quantity);
    }
}

int main() {
    Book* head = NULL;

    Book* newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 5;

    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "To Kill a Mockingbird");
    strcpy(newBook->author, "Harper Lee");
    newBook->quantity = 10;

    insertBook(head, newBook);

    printBookList(head);

    Book* foundBook = findBook(head, "The Lord of the Flies");

    if (foundBook) {
        updateBookQuantity(foundBook, 10);
        printBookList(head);
    }

    return 0;
}