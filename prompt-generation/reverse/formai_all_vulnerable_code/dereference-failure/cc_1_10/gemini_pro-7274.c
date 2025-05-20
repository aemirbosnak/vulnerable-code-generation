//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
typedef struct book {
    char *title;
    char *author;
    int pages;
    float rating;
} book;

// Define the structure of a library
typedef struct library {
    book *books;
    int num_books;
} library;

// Create a new book
book *create_book(char *title, char *author, int pages, float rating) {
    book *new_book = malloc(sizeof(book));
    new_book->title = strdup(title);
    new_book->author = strdup(author);
    new_book->pages = pages;
    new_book->rating = rating;
    return new_book;
}

// Create a new library
library *create_library() {
    library *new_library = malloc(sizeof(library));
    new_library->books = NULL;
    new_library->num_books = 0;
    return new_library;
}

// Add a book to a library
void add_book(library *library, book *new_book) {
    library->books = realloc(library->books, (library->num_books + 1) * sizeof(book));
    library->books[library->num_books] = *new_book;
    library->num_books++;
}

// Print the books in a library
void print_library(library *library) {
    for (int i = 0; i < library->num_books; i++) {
        printf("%s by %s (%d pages, %.1f rating)\n", library->books[i].title, library->books[i].author, library->books[i].pages, library->books[i].rating);
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
    library *library = create_library();

    // Add some books to the library
    add_book(library, create_book("The Catcher in the Rye", "J.D. Salinger", 277, 3.8));
    add_book(library, create_book("The Great Gatsby", "F. Scott Fitzgerald", 180, 4.2));
    add_book(library, create_book("To Kill a Mockingbird", "Harper Lee", 324, 4.8));

    // Print the books in the library
    print_library(library);

    // Free the memory allocated for the library
    free_library(library);

    return 0;
}