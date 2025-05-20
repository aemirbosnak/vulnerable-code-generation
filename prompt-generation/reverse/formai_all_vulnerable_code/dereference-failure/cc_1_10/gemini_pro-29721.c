//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
typedef struct book {
    char *title;
    char *author;
    int num_pages;
    char *text;
} book;

// Define the structure of a library
typedef struct library {
    char *name;
    int num_books;
    book *books;
} library;

// Create a new book
book *create_book(char *title, char *author, int num_pages, char *text) {
    book *new_book = malloc(sizeof(book));
    new_book->title = strdup(title);
    new_book->author = strdup(author);
    new_book->num_pages = num_pages;
    new_book->text = strdup(text);
    return new_book;
}

// Create a new library
library *create_library(char *name, int num_books, book *books) {
    library *new_library = malloc(sizeof(library));
    new_library->name = strdup(name);
    new_library->num_books = num_books;
    new_library->books = books;
    return new_library;
}

// Print the information about a book
void print_book(book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Text: %s\n", book->text);
}

// Print the information about a library
void print_library(library *library) {
    printf("Name: %s\n", library->name);
    printf("Number of books: %d\n", library->num_books);
    for (int i = 0; i < library->num_books; i++) {
        print_book(&library->books[i]);
    }
}

// Main function
int main() {
    // Create a new book
    book *book1 = create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 184, "In the beginning, the Universe was created. This has made a lot of people very angry and been widely regarded as a bad move.");

    // Create a new library
    library *library1 = create_library("My Library", 1, &book1);

    // Print the information about the library
    print_library(library1);

    return 0;
}