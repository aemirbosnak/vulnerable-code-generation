//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
};

struct Librarian {
    struct Book** books;
    int numBooks;
    struct Librarian* next;
};

void insertBook(struct Librarian* lib, struct Book* newBook) {
    newBook->next = lib->books[lib->numBooks];
    lib->books[lib->numBooks++] = newBook;
}

void searchBook(struct Librarian* lib, char* title) {
    for (int i = 0; i < lib->numBooks; i++) {
        if (strcmp(lib->books[i]->title, title) == 0) {
            printf("Book found: %s by %s, quantity: %d\n", lib->books[i]->title, lib->books[i]->author, lib->books[i]->quantity);
            return;
        }
    }

    printf("Book not found.\n");
}

int main() {
    struct Librarian* lib = malloc(sizeof(struct Librarian));
    lib->books = malloc(MAX_BOOKS * sizeof(struct Book));
    lib->numBooks = 0;

    struct Book* newBook = malloc(sizeof(struct Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 5;

    insertBook(lib, newBook);

    newBook = malloc(sizeof(struct Book));
    strcpy(newBook->title, "The Great Gatsby");
    strcpy(newBook->author, "F. Scott Fitzgerald");
    newBook->quantity = 3;

    insertBook(lib, newBook);

    searchBook(lib, "The Lord of the Flies");

    searchBook(lib, "The Great Gatsby");

    return 0;
}