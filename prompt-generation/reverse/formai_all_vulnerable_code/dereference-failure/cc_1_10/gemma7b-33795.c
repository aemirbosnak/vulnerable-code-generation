//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
};

struct Library {
    struct Book* head;
    struct Book* tail;
    int numBooks;
    int capacity;
};

void insertBook(struct Library* lib, char* title, char* author, int quantity) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->next = NULL;

    if (lib->head == NULL) {
        lib->head = newBook;
        lib->tail = newBook;
    } else {
        lib->tail->next = newBook;
        lib->tail = newBook;
    }

    lib->numBooks++;
}

void displayBooks(struct Library* lib) {
    struct Book* currentBook = lib->head;
    while (currentBook) {
        printf("%s by %s, quantity: %d\n", currentBook->title, currentBook->author, currentBook->quantity);
        currentBook = currentBook->next;
    }
}

int main() {
    struct Library* lib = (struct Library*)malloc(sizeof(struct Library));
    lib->head = NULL;
    lib->tail = NULL;
    lib->numBooks = 0;
    lib->capacity = MAX_BOOKS;

    insertBook(lib, "The Lord of the Flies", "William Golding", 5);
    insertBook(lib, "The Hobbit", "J.R.R. Tolkien", 3);
    insertBook(lib, "The Catcher in the Rye", "J.D. Salinger", 2);

    displayBooks(lib);

    return 0;
}