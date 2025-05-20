//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: mathematical
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
    int numBooks;
} Library;

// Function to insert a book into the library
void insertBook(Library* lib, Book* book) {
    if (lib->head == NULL) {
        lib->head = book;
    } else {
        book->next = lib->head;
        lib->head = book;
    }
    lib->numBooks++;
}

// Function to search for a book in the library
Book* searchBook(Library* lib, char* title) {
    Book* book = lib->head;
    while (book) {
        if (strcmp(book->title, title) == 0) {
            return book;
        }
        book = book->next;
    }
    return NULL;
}

// Function to update the quantity of a book in the library
void updateQuantity(Library* lib, char* title, int quantity) {
    Book* book = searchBook(lib, title);
    if (book) {
        book->quantity = quantity;
    }
}

// Function to delete a book from the library
void deleteBook(Library* lib, char* title) {
    Book* book = searchBook(lib, title);
    if (book) {
        Book* prevBook = NULL;
        Book* currentBook = lib->head;
        while (currentBook) {
            if (strcmp(currentBook->title, title) == 0) {
                if (prevBook) {
                    prevBook->next = currentBook->next;
                } else {
                    lib->head = currentBook->next;
                }
                free(book);
                lib->numBooks--;
                return;
            }
            prevBook = currentBook;
            currentBook = currentBook->next;
        }
    }
    return;
}

int main() {
    // Create a library
    Library* lib = malloc(sizeof(Library));
    lib->head = NULL;
    lib->numBooks = 0;

    // Insert some books into the library
    Book* book1 = malloc(sizeof(Book));
    strcpy(book1->title, "The Lord of the Flies");
    strcpy(book1->author, "William Golding");
    book1->quantity = 10;
    insertBook(lib, book1);

    Book* book2 = malloc(sizeof(Book));
    strcpy(book2->title, "To Kill a Mockingbird");
    strcpy(book2->author, "Harper Lee");
    book2->quantity = 8;
    insertBook(lib, book2);

    Book* book3 = malloc(sizeof(Book));
    strcpy(book3->title, "The Great Gatsby");
    strcpy(book3->author, "F. Scott Fitzgerald");
    book3->quantity = 6;
    insertBook(lib, book3);

    // Search for a book in the library
    book2 = searchBook(lib, "To Kill a Mockingbird");
    if (book2) {
        printf("Book found: %s by %s\n", book2->title, book2->author);
        printf("Quantity: %d\n", book2->quantity);
    }

    // Update the quantity of a book in the library
    updateQuantity(lib, "The Lord of the Flies", 12);
    book1 = searchBook(lib, "The Lord of the Flies");
    if (book1) {
        printf("Book found: %s by %s\n", book1->title, book1->author);
        printf("Quantity: %d\n", book1->quantity);
    }

    // Delete a book from the library
    deleteBook(lib, "The Great Gatsby");
    book3 = searchBook(lib, "The Great Gatsby");
    if (book3) {
        printf("Book found: %s by %s\n", book3->title, book3->author);
        printf("Quantity: %d\n", book3->quantity);
    }

    return 0;
}