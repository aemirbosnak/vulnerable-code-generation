//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Struct for the books in the library
typedef struct {
    char title[100];
    int pages;
    char author[50];
} Book;

// Struct for the library itself
typedef struct {
    int num_books;
    Book* books;
} Library;

void add_book(Library* library, char* title, int pages, char* author) {
    library->num_books++;
    library->books = realloc(library->books, library->num_books * sizeof(Book));
    strcpy(library->books[library->num_books - 1].title, title);
    library->books[library->num_books - 1].pages = pages;
    strcpy(library->books[library->num_books - 1].author, author);
}

void display_library(Library* library) {
    printf("The library contains %d books:\n", library->num_books);
    for (int i = 0; i < library->num_books; i++) {
        printf("Book %d: %s, %d pages, by %s\n", i + 1, library->books[i].title, library->books[i].pages, library->books[i].author);
    }
}

int main() {
    // Create a new library
    Library library;
    library.num_books = 0;
    library.books = NULL;

    // Add some books to the library
    add_book(&library, "A Study in Scarlet", 200, "Arthur Conan Doyle");
    add_book(&library, "The Sign of Four", 250, "Arthur Conan Doyle");
    add_book(&library, "A Case of Identity", 150, "Arthur Conan Doyle");

    // Display the library contents
    display_library(&library);

    // Free the memory used by the books
    free(library.books);

    return 0;
}