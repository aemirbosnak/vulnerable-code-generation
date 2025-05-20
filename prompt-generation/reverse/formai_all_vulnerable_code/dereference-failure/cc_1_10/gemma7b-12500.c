//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define the library management system structure
typedef struct LibraryManagementSystem {
    char **books;
    int numBooks;
    int availableBooks;
} LibraryManagementSystem;

// Function to create a new library management system
LibraryManagementSystem *createLibraryManagementSystem(int numBooks) {
    LibraryManagementSystem *lms = malloc(sizeof(LibraryManagementSystem));
    lms->books = malloc(numBooks * sizeof(char *));
    lms->numBooks = numBooks;
    lms->availableBooks = numBooks;

    return lms;
}

// Function to add a book to the library
void addBook(LibraryManagementSystem *lms, char *bookName) {
    lms->books[lms->numBooks] = bookName;
    lms->numBooks++;
    lms->availableBooks++;
}

// Function to remove a book from the library
void removeBook(LibraryManagementSystem *lms, char *bookName) {
    int i = 0;
    for (i = 0; i < lms->numBooks; i++) {
        if (strcmp(lms->books[i], bookName) == 0) {
            free(lms->books[i]);
            lms->books[i] = NULL;
            lms->numBooks--;
            lms->availableBooks--;
            break;
        }
    }
}

// Function to list all books in the library
void listBooks(LibraryManagementSystem *lms) {
    int i = 0;
    for (i = 0; i < lms->numBooks; i++) {
        printf("%s\n", lms->books[i]);
    }
}

// Function to check if a book is available
int isBookAvailable(LibraryManagementSystem *lms, char *bookName) {
    int i = 0;
    for (i = 0; i < lms->numBooks; i++) {
        if (strcmp(lms->books[i], bookName) == 0) {
            return 1;
        }
    }

    return 0;
}

// Main function
int main() {
    // Create a new library management system
    LibraryManagementSystem *lms = createLibraryManagementSystem(10);

    // Add some books to the library
    addBook(lms, "Book 1");
    addBook(lms, "Book 2");
    addBook(lms, "Book 3");

    // List all books in the library
    listBooks(lms);

    // Check if a book is available
    if (isBookAvailable(lms, "Book 2")) {
        printf("Book 2 is available\n");
    }

    // Remove a book from the library
    removeBook(lms, "Book 2");

    // List all books in the library after removing book 2
    listBooks(lms);

    return 0;
}