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

struct Library {
    struct Book* head;
    struct Book* tail;
    int numBooks;
};

void insertBook(struct Library* lib, struct Book* book) {
    if (lib->head == NULL) {
        lib->head = book;
        lib->tail = book;
    } else {
        lib->tail->next = book;
        lib->tail = book;
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

    struct Book* book1 = malloc(sizeof(struct Book));
    strcpy(book1->title, "The Lord of the Flies");
    strcpy(book1->author, "William Golding");
    book1->quantity = 5;

    insertBook(&lib, book1);

    struct Book* book2 = malloc(sizeof(struct Book));
    strcpy(book2->title, "The Great Gatsby");
    strcpy(book2->author, "F. Scott Fitzgerald");
    book2->quantity = 3;

    insertBook(&lib, book2);

    searchBook(&lib, "The Lord of the Flies");
    searchBook(&lib, "The Great Gatsby");

    return 0;
}