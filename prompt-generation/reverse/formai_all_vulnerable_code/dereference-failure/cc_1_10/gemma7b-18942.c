//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    int quantity;
    double price;
    struct Book* next;
};

struct Library {
    struct Book* head;
    struct Book* tail;
    int numBooks;
    struct Library* next;
};

void insertBook(struct Library* lib, char* title, char* author, int quantity, double price) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->price = price;
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
            printf("Title: %s\n", currentBook->title);
            printf("Author: %s\n", currentBook->author);
            printf("Quantity: %d\n", currentBook->quantity);
            printf("Price: %.2lf\n", currentBook->price);
            return;
        }
        currentBook = currentBook->next;
    }

    printf("Book not found.\n");
}

int main() {
    struct Library* library = (struct Library*)malloc(sizeof(struct Library));
    library->head = NULL;
    library->tail = NULL;
    library->numBooks = 0;
    library->next = NULL;

    insertBook(library, "The Lord of the Flies", "William Golding", 50, 10.0);
    insertBook(library, "To Kill a Mockingbird", "Harper Lee", 20, 12.0);
    insertBook(library, "The Great Gatsby", "F. Scott Fitzgerald", 30, 15.0);

    searchBook(library, "The Lord of the Flies");

    return 0;
}