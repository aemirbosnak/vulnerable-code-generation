//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    char genre[20];
    int quantity;
    struct Book* next;
} Book;

Book* createBook(char* title, char* author, char* genre, int quantity) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->genre, genre);
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
            printf("Genre: %s\n", currentBook->genre);
            printf("Quantity: %d\n", currentBook->quantity);
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

    insertBook(head, createBook("The Lord of the Flies", "William Golding", "Classic", 5));
    insertBook(head, createBook("To Kill a Mockingbird", "Harper Lee", "Classic", 10));
    insertBook(head, createBook("The Great Gatsby", "F. Scott Fitzgerald", "Classic", 7));

    searchBook(head, "To Kill a Mockingbird");

    return 0;
}