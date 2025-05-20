//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, char* title, char* author, int quantity) {
    Book* newBook = malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        Book* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newBook;
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

Book* updateBookQuantity(Book* head, char* title, int newQuantity) {
    Book* book = searchBook(head, title);
    if (book) {
        book->quantity = newQuantity;
    }

    return head;
}

void printBooks(Book* head) {
    Book* currentBook = head;
    while (currentBook) {
        printf("%s by %s (Quantity: %d)\n", currentBook->title, currentBook->author, currentBook->quantity);
        currentBook = currentBook->next;
    }
}

int main() {
    Book* head = NULL;

    insertBook(head, "The Lord of the Flies", "William Golding", 5);
    insertBook(head, "To Kill a Mockingbird", "Harper Lee", 3);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 2);

    printBooks(head);

    updateBookQuantity(head, "The Lord of the Flies", 10);

    printBooks(head);

    return 0;
}