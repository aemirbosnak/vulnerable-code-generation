//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_AUTHORS 50

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

typedef struct Author {
    char name[50];
    struct Author* next;
} Author;

Book* insertBook(Book* head, char* title, char* author, int quantity) {
    Book* newNode = (Book*)malloc(sizeof(Book));
    strcpy(newNode->title, title);
    strcpy(newNode->author, author);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Book* currentBook = head;
        while (currentBook->next) {
            currentBook = currentBook->next;
        }
        currentBook->next = newNode;
    }

    return head;
}

Author* insertAuthor(Author* head, char* name) {
    Author* newNode = (Author*)malloc(sizeof(Author));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Author* currentAuthor = head;
        while (currentAuthor->next) {
            currentAuthor = currentAuthor->next;
        }
        currentAuthor->next = newNode;
    }

    return head;
}

void searchBooks(Book* head, char* title) {
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

int main() {
    Book* bookHead = NULL;
    Author* authorHead = NULL;

    insertBook(bookHead, "The Lord of the Flies", "William Golding", 5);
    insertBook(bookHead, "To Kill a Mockingbird", "Harper Lee", 10);
    insertBook(bookHead, "The Great Gatsby", "F. Scott Fitzgerald", 7);
    insertAuthor(authorHead, "William Golding");
    insertAuthor(authorHead, "Harper Lee");

    searchBooks(bookHead, "To Kill a Mockingbird");

    return 0;
}