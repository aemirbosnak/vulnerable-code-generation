//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct book {
    char *title;
    char *author;
    int pages;
    char *genre;
} book;

// Function to create a new book
book *new_book(char *title, char *author, int pages, char *genre) {
    book *b = malloc(sizeof(book));
    b->title = strdup(title);
    b->author = strdup(author);
    b->pages = pages;
    b->genre = strdup(genre);
    return b;
}

// Function to print a book
void print_book(book *b) {
    printf("Title: %s\n", b->title);
    printf("Author: %s\n", b->author);
    printf("Pages: %d\n", b->pages);
    printf("Genre: %s\n", b->genre);
}

// Function to free a book
void free_book(book *b) {
    free(b->title);
    free(b->author);
    free(b->genre);
    free(b);
}

// Main function
int main() {
    // Create a new book
    book *b = new_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 184, "Science Fiction");

    // Print the book
    print_book(b);

    // Free the book
    free_book(b);

    return 0;
}