//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: rigorous
#include <stdio.h>
#include <string.h>
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
        }
        head = head->next;
    }
    return NULL;
}

void updateBookQuantity(Book* head, char* title, int quantity) {
    Book* book = searchBook(head, title);
    if (book) {
        book->quantity = quantity;
    }
}

void deleteBook(Book* head, char* title) {
    Book* book = searchBook(head, title);
    if (book) {
        Book* prevBook = NULL;
        Book* currentBook = head;
        while (currentBook) {
            if (strcmp(currentBook->title, title) == 0) {
                if (prevBook) {
                    prevBook->next = currentBook->next;
                } else {
                    head = currentBook->next;
                }
                free(book);
                book = NULL;
            } else {
                prevBook = currentBook;
                currentBook = currentBook->next;
            }
        }
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

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Great Gatsby");
    strcpy(newBook->author, "F. Scott Fitzgerald");
    newBook->quantity = 7;
    insertBook(head, newBook);

    updateBookQuantity(head, "To Kill a Mockingbird", 12);

    deleteBook(head, "The Lord of the Flies");

    Book* book = searchBook(head, "To Kill a Mockingbird");
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Quantity: %d\n", book->quantity);
    }

    return 0;
}