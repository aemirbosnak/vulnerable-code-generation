//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: complex
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

Book* insertBook(Book* head, char* title, char* author, char* genre, int quantity) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->genre, genre);
    newBook->quantity = quantity;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        head->next = newBook;
    }

    return head;
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

    insertBook(head, "The Lord of the Flies", "William Golding", "Fiction", 5);
    insertBook(head, "To Kill a Mockingbird", "Harper Lee", "Fiction", 10);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", "Fiction", 7);
    insertBook(head, "The Hobbit: An Unexpected Journey", "J.R.R. Tolkien", "Fantasy", 3);

    searchBook(head, "To Kill a Mockingbird");

    return 0;
}