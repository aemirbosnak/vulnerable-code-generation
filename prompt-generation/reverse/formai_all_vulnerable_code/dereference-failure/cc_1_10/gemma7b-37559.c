//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    int quantity;
    float price;
};

struct BookBookshelf {
    struct Book books[MAX_BOOKS];
    int size;
    int nextIndex;
};

void initializeBookShelf(struct BookBookshelf *shelf) {
    shelf->size = 0;
    shelf->nextIndex = 0;
}

void addBookToShelf(struct BookBookshelf *shelf, struct Book book) {
    shelf->books[shelf->nextIndex] = book;
    shelf->size++;
    shelf->nextIndex++;
}

void searchBookByTitle(struct BookBookshelf *shelf, char *title) {
    for (int i = 0; i < shelf->size; i++) {
        if (strcmp(shelf->books[i].title, title) == 0) {
            printf("Book: %s, Author: %s, Quantity: %d, Price: %.2f\n", shelf->books[i].title, shelf->books[i].author, shelf->books[i].quantity, shelf->books[i].price);
        }
    }
}

int main() {
    struct BookBookshelf *shelf = (struct BookBookshelf *)malloc(sizeof(struct BookBookshelf));
    initializeBookShelf(shelf);

    struct Book book1 = {"The Lord of the Flies", "William Golding", 50, 10.0};
    struct Book book2 = {"The Great Gatsby", "F. Scott Fitzgerald", 20, 12.0};
    struct Book book3 = {"To Kill a Mockingbird", "Harper Lee", 30, 15.0};

    addBookToShelf(shelf, book1);
    addBookToShelf(shelf, book2);
    addBookToShelf(shelf, book3);

    searchBookByTitle(shelf, "The Lord of the Flies");

    return 0;
}