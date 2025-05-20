//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: modular
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

Book* createBook(char* title, char* author, int quantity) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->next = NULL;
    return newBook;
}

void insertBook(Book* head, Book* newBook) {
    if (head == NULL) {
        head = newBook;
    } else {
        newBook->next = head;
        head = newBook;
    }
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

void deleteBook(Book* head, char* title) {
    Book* currentBook = head;
    Book* previousBook = NULL;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            if (previousBook != NULL) {
                previousBook->next = currentBook->next;
            } else {
                head = currentBook->next;
            }
            free(currentBook);
            break;
        }
        previousBook = currentBook;
        currentBook = currentBook->next;
    }
    if (currentBook == NULL) {
        printf("Book not found.\n");
    }
}

int main() {
    Book* head = NULL;
    insertBook(head, createBook("The Lord of the Flies", "William Golding", 5));
    insertBook(head, createBook("The Great Gatsby", "F. Scott Fitzgerald", 10));
    insertBook(head, createBook("To Kill a Mockingbird", "Harper Lee", 7));
    insertBook(head, createBook("The Hobbit", "J.R.R. Tolkien", 3));

    searchBook(head, "The Lord of the Flies");
    updateBookQuantity(head, "The Great Gatsby", 15);
    deleteBook(head, "To Kill a Mockingbird");

    searchBook(head, "The Lord of the Flies");
    searchBook(head, "The Great Gatsby");
    searchBook(head, "To Kill a Mockingbird");

    return 0;
}