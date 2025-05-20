//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: visionary
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

struct Library {
    struct Book* head;
    struct Book* tail;
    int numBooks;
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

void searchBook(struct Library* lib, char* title) {
    struct Book* currentBook = lib->head;

    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            printf("Book found: %s by %s, quantity: %d\n", currentBook->title, currentBook->author, currentBook->quantity);
            return;
        }
        currentBook = currentBook->next;
    }

    printf("Book not found.\n");
}

int main() {
    struct Library lib;
    lib.head = NULL;
    lib.tail = NULL;
    lib.numBooks = 0;

    insertBook(&lib, "The Lord of the Flies", "William Golding", 5);
    insertBook(&lib, "To Kill a Mockingbird", "Harper Lee", 10);
    insertBook(&lib, "The Great Gatsby", "F. Scott Fitzgerald", 7);

    searchBook(&lib, "To Kill a Mockingbird");

    return 0;
}