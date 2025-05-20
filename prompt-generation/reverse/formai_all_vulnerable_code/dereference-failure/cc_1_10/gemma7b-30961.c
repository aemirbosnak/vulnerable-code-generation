//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of books in the library
#define MAX_BOOKS 100

// Define the book structure
typedef struct Book {
    char title[20];
    char author[20];
    int quantity;
    struct Book* next;
} Book;

// Define the library structure
typedef struct Library {
    Book* head;
    Book* tail;
    int numBooks;
} Library;

// Function to insert a book into the library
void insertBook(Library* lib, Book* newBook) {
    if (lib->head == NULL) {
        lib->head = newBook;
        lib->tail = newBook;
    } else {
        lib->tail->next = newBook;
        lib->tail = newBook;
    }
    lib->numBooks++;
}

// Function to search for a book in the library
Book* searchBook(Library* lib, char* title) {
    Book* currentBook = lib->head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            return currentBook;
        }
        currentBook = currentBook->next;
    }
    return NULL;
}

int main() {
    // Create a library
    Library* lib = malloc(sizeof(Library));
    lib->head = NULL;
    lib->tail = NULL;
    lib->numBooks = 0;

    // Insert some books into the library
    Book* newBook1 = malloc(sizeof(Book));
    strcpy(newBook1->title, "The Road");
    strcpy(newBook1->author, "Cormac McCarthy");
    newBook1->quantity = 10;
    insertBook(lib, newBook1);

    Book* newBook2 = malloc(sizeof(Book));
    strcpy(newBook2->title, "The Book of Joy");
    strcpy(newBook2->author, "David Brooks");
    newBook2->quantity = 5;
    insertBook(lib, newBook2);

    Book* newBook3 = malloc(sizeof(Book));
    strcpy(newBook3->title, "The Lord of the Flies");
    strcpy(newBook3->author, "William Golding");
    newBook3->quantity = 7;
    insertBook(lib, newBook3);

    // Search for a book in the library
    Book* foundBook = searchBook(lib, "The Road");
    if (foundBook) {
        printf("Found book: %s by %s\n", foundBook->title, foundBook->author);
    } else {
        printf("Book not found.\n");
    }

    // Free the library
    free(lib);

    return 0;
}