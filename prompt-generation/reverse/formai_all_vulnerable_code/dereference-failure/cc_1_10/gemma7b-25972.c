//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: mathematical
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

Book* insertBook(Book* head, char* title, char* author, int quantity) {
    Book* newNode = (Book*)malloc(sizeof(Book));
    strcpy(newNode->title, title);
    strcpy(newNode->author, author);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Book* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newNode;
    }

    return head;
}

Book* findBook(Book* head, char* title) {
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            return currentBook;
        }
        currentBook = currentBook->next;
    }

    return NULL;
}

void updateQuantity(Book* head, char* title, int newQuantity) {
    Book* book = findBook(head, title);
    if (book) {
        book->quantity = newQuantity;
    }
}

void deleteBook(Book* head, char* title) {
    Book* book = findBook(head, title);
    if (book) {
        Book* previousBook = NULL;
        Book* currentBook = head;
        while (currentBook) {
            if (book == currentBook) {
                if (previousBook) {
                    previousBook->next = currentBook->next;
                } else {
                    head = currentBook->next;
                }
                free(book);
                return;
            }
            previousBook = currentBook;
            currentBook = currentBook->next;
        }
    }
}

int main() {
    Book* head = NULL;

    insertBook(head, "The Lord of the Flies", "William Golding", 5);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 10);
    insertBook(head, "To Kill a Mockingbird", "Harper Lee", 7);

    updateQuantity(head, "The Lord of the Flies", 10);

    deleteBook(head, "The Great Gatsby");

    Book* book = findBook(head, "To Kill a Mockingbird");
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Quantity: %d\n", book->quantity);
    }

    return 0;
}