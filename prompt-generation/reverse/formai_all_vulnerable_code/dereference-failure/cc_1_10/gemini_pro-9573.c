//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
typedef struct book {
    char *title;
    char *author;
    int num_pages;
} book;

// Define the structure of a library
typedef struct library {
    book *books;
    int num_books;
} library;

// Create a new book
book *create_book(char *title, char *author, int num_pages) {
    book *new_book = malloc(sizeof(book));
    new_book->title = malloc(strlen(title) + 1);
    strcpy(new_book->title, title);
    new_book->author = malloc(strlen(author) + 1);
    strcpy(new_book->author, author);
    new_book->num_pages = num_pages;
    return new_book;
}

// Create a new library
library *create_library() {
    library *new_library = malloc(sizeof(library));
    new_library->books = malloc(0);
    new_library->num_books = 0;
    return new_library;
}

// Add a book to a library
void add_book_to_library(library *library, book *book) {
    library->books = realloc(library->books, (library->num_books + 1) * sizeof(book));
    library->books[library->num_books++] = *book;
}

// Print the books in a library
void print_library(library *library) {
    for (int i = 0; i < library->num_books; i++) {
        printf("%s by %s (%d pages)\n", library->books[i].title, library->books[i].author, library->books[i].num_pages);
    }
}

// Free the memory allocated for a book
void free_book(book *book) {
    free(book->title);
    free(book->author);
    free(book);
}

// Free the memory allocated for a library
void free_library(library *library) {
    for (int i = 0; i < library->num_books; i++) {
        free_book(&library->books[i]);
    }
    free(library->books);
    free(library);
}

// Main function
int main() {
    // Create a new library
    library *my_library = create_library();

    // Add some books to the library
    add_book_to_library(my_library, create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 184));
    add_book_to_library(my_library, create_book("The Lord of the Rings", "J.R.R. Tolkien", 1207));
    add_book_to_library(my_library, create_book("1984", "George Orwell", 328));

    // Print the books in the library
    print_library(my_library);

    // Free the memory allocated for the library
    free_library(my_library);

    return 0;
}