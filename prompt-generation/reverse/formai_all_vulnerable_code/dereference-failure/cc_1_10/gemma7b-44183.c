//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_SEARCH_RESULTS 10

struct Book {
    char title[50];
    char author[50];
    char genre[50];
    int quantity;
    struct Book* next;
};

struct Library {
    struct Book* head;
    struct Book* tail;
    int numBooks;
};

void insertBook(struct Library* library, char* title, char* author, char* genre, int quantity) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->genre, genre);
    newBook->quantity = quantity;
    newBook->next = NULL;

    if (library->head == NULL) {
        library->head = newBook;
        library->tail = newBook;
    } else {
        library->tail->next = newBook;
        library->tail = newBook;
    }

    library->numBooks++;
}

void searchBooks(struct Library* library, char* title) {
    struct Book* currentBook = library->head;
    int i = 0;

    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            printf("Title: %s\n", currentBook->title);
            printf("Author: %s\n", currentBook->author);
            printf("Genre: %s\n", currentBook->genre);
            printf("Quantity: %d\n", currentBook->quantity);
            i++;
        }
        currentBook = currentBook->next;
    }

    if (i == 0) {
        printf("No results found.\n");
    }
}

int main() {
    struct Library library;
    library.head = NULL;
    library.tail = NULL;
    library.numBooks = 0;

    insertBook(&library, "The Lord of the Flies", "William Golding", "Classic Fiction", 5);
    insertBook(&library, "To Kill a Mockingbird", "Harper Lee", "Classic Fiction", 10);
    insertBook(&library, "The Great Gatsby", "F. Scott Fitzgerald", "Classic Fiction", 7);
    insertBook(&library, "The Catcher in the Rye", "J.D. Salinger", "Young Adult Fiction", 8);

    searchBooks(&library, "The Lord of the Flies");

    return 0;
}