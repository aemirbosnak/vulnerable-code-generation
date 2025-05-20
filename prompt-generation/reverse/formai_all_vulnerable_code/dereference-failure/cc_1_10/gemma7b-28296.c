//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of books in the library
#define MAX_BOOKS 100

// Define the book structure
typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

// Define the library structure
typedef struct Library {
    Book* head;
    Book* tail;
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

// Function to update the quantity of a book in the library
void updateBookQuantity(Library* lib, char* title, int newQuantity) {
    Book* book = searchBook(lib, title);
    if (book) {
        book->quantity = newQuantity;
    }
}

// Function to remove a book from the library
void removeBook(Library* lib, char* title) {
    Book* book = searchBook(lib, title);
    if (book) {
        Book* previousBook = NULL;
        Book* currentBook = lib->head;
        while (currentBook) {
            if (strcmp(currentBook->title, title) == 0) {
                if (previousBook) {
                    previousBook->next = currentBook->next;
                } else {
                    lib->head = currentBook->next;
                }
                free(book);
                return;
            }
            previousBook = currentBook;
            currentBook = currentBook->next;
        }
    }
    return;
}

int main() {
    // Create a library
    Library* lib = malloc(sizeof(Library));
    lib->head = NULL;
    lib->tail = NULL;

    // Insert some books into the library
    Book* newBook1 = malloc(sizeof(Book));
    strcpy(newBook1->title, "The Lord of the Flies");
    strcpy(newBook1->author, "William Golding");
    newBook1->quantity = 10;
    insertBook(lib, newBook1);

    Book* newBook2 = malloc(sizeof(Book));
    strcpy(newBook2->title, "To Kill a Mockingbird");
    strcpy(newBook2->author, "Harper Lee");
    newBook2->quantity = 5;
    insertBook(lib, newBook2);

    Book* newBook3 = malloc(sizeof(Book));
    strcpy(newBook3->title, "The Great Gatsby");
    strcpy(newBook3->author, "F. Scott Fitzgerald");
    newBook3->quantity = 7;
    insertBook(lib, newBook3);

    // Search for a book in the library
    Book* book = searchBook(lib, "The Lord of the Flies");
    if (book) {
        printf("Book title: %s\n", book->title);
        printf("Book author: %s\n", book->author);
        printf("Book quantity: %d\n", book->quantity);
    }

    // Update the quantity of a book in the library
    updateBookQuantity(lib, "To Kill a Mockingbird", 12);
    book = searchBook(lib, "To Kill a Mockingbird");
    if (book) {
        printf("Updated book quantity: %d\n", book->quantity);
    }

    // Remove a book from the library
    removeBook(lib, "The Great Gatsby");
    book = searchBook(lib, "The Great Gatsby");
    if (book) {
        printf("Book has been removed.\n");
    }

    return 0;
}