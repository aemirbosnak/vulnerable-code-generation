//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: artistic
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
    Book* book = (Book*)malloc(sizeof(Book));
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->quantity = quantity;
    book->next = NULL;
    return book;
}

void insertBook(Book* head, Book* newBook) {
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
    while (currentBook != NULL) {
        if (strcmp(currentBook->title, title) == 0) {
            printf("%s by %s, quantity: %d\n", currentBook->title, currentBook->author, currentBook->quantity);
        }
        currentBook = currentBook->next;
    }
}

int main() {
    Book* head = NULL;
    insertBook(head, createBook("The Lord of the Flies", "William Golding", 5));
    insertBook(head, createBook("The Great Gatsby", "F. Scott Fitzgerald", 3));
    insertBook(head, createBook("To Kill a Mockingbird", "Harper Lee", 2));
    searchBook(head, "The Great Gatsby");
    return 0;
}