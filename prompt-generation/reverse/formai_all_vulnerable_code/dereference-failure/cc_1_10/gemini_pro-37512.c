//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom data type for a book
typedef struct {
    char *title;
    char *author;
    int year;
    int pages;
} Book;

// Create a new book
Book *create_book(char *title, char *author, int year, int pages) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->year = year;
    book->pages = pages;
    return book;
}

// Print the details of a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Year: %d\n", book->year);
    printf("Pages: %d\n", book->pages);
}

// Free the memory allocated for a book
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book);
}

// Main function
int main() {
    // Create a library of books
    Book *library[] = {
        create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 1979, 180),
        create_book("The Lord of the Rings", "J.R.R. Tolkien", 1954, 1207),
        create_book("1984", "George Orwell", 1949, 328),
        create_book("Brave New World", "Aldous Huxley", 1932, 268),
        create_book("The Catcher in the Rye", "J.D. Salinger", 1951, 277),
    };

    // Iterate over the library and print the details of each book
    for (int i = 0; i < 5; i++) {
        print_book(library[i]);
        printf("\n");
    }

    // Free the memory allocated for each book
    for (int i = 0; i < 5; i++) {
        free_book(library[i]);
    }

    return 0;
}