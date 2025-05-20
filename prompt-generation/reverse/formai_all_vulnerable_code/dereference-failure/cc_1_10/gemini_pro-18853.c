//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct Book {
    char title[50];
    char author[50];
    int year;
    int copies;
} Book;

// Structure to represent a library
typedef struct Library {
    Book *books;
    int num_books;
} Library;

// Function to create a new library
Library *create_library() {
    Library *library = (Library *)malloc(sizeof(Library));
    library->books = NULL;
    library->num_books = 0;
    return library;
}

// Function to add a new book to a library
void add_book(Library *library, Book book) {
    library->books = (Book *)realloc(library->books, (library->num_books + 1) * sizeof(Book));
    library->books[library->num_books] = book;
    library->num_books++;
}

// Function to find a book in a library by title
Book *find_book_by_title(Library *library, char *title) {
    for (int i = 0; i < library->num_books; i++) {
        if (strcmp(library->books[i].title, title) == 0) {
            return &library->books[i];
        }
    }
    return NULL;
}

// Function to find a book in a library by author
Book *find_book_by_author(Library *library, char *author) {
    for (int i = 0; i < library->num_books; i++) {
        if (strcmp(library->books[i].author, author) == 0) {
            return &library->books[i];
        }
    }
    return NULL;
}

// Function to find a book in a library by year
Book *find_book_by_year(Library *library, int year) {
    for (int i = 0; i < library->num_books; i++) {
        if (library->books[i].year == year) {
            return &library->books[i];
        }
    }
    return NULL;
}

// Function to print the details of a book
void print_book(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Year: %d\n", book.year);
    printf("Copies: %d\n\n", book.copies);
}

// Function to print the details of all books in a library
void print_library(Library *library) {
    for (int i = 0; i < library->num_books; i++) {
        print_book(library->books[i]);
    }
}

// Function to free the memory allocated to a library
void free_library(Library *library) {
    free(library->books);
    free(library);
}

// Main function
int main() {
    // Create a new library
    Library *library = create_library();

    // Add some books to the library
    Book book1 = {"The Catcher in the Rye", "J.D. Salinger", 1951, 5};
    add_book(library, book1);
    Book book2 = {"To Kill a Mockingbird", "Harper Lee", 1960, 10};
    add_book(library, book2);
    Book book3 = {"The Great Gatsby", "F. Scott Fitzgerald", 1925, 7};
    add_book(library, book3);

    // Print the details of all books in the library
    print_library(library);

    // Find a book in the library by title
    Book *book = find_book_by_title(library, "To Kill a Mockingbird");
    if (book != NULL) {
        printf("Book found:\n");
        print_book(*book);
    } else {
        printf("Book not found.\n");
    }

    // Free the memory allocated to the library
    free_library(library);

    return 0;
}