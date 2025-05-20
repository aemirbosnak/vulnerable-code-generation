//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    char genre[50];
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

void addBook(Book* head, char* title, char* author, char* genre, int quantity) {
    Book* newBook = createBook(title, author, genre, quantity);
    if (head == NULL) {
        head = newBook;
    } else {
        Book* currentBook = head;
        while (currentBook->next != NULL) {
            currentBook = currentBook->next;
        }
        currentBook->next = newBook;
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
    addBook(head, "The Lord of the Flies", "William Golding", "Coming-of-age", 50);
    addBook(head, "To Kill a Mockingbird", "Harper Lee", "Classic", 20);
    addBook(head, "The Great Gatsby", "F. Scott Fitzgerald", "Jazz", 30);

    searchBook(head, "To Kill a Mockingbird");

    return 0;
}