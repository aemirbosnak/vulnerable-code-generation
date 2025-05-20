//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book structure
typedef struct Book {
    char *title;
    char *author;
    int pages;
    char *contents;
} Book;

// Function to create a new book
Book *create_book(char *title, char *author, int pages, char *contents) {
    Book *book = malloc(sizeof(Book));
    book->title = malloc(strlen(title) + 1);
    strcpy(book->title, title);
    book->author = malloc(strlen(author) + 1);
    strcpy(book->author, author);
    book->pages = pages;
    book->contents = malloc(strlen(contents) + 1);
    strcpy(book->contents, contents);
    return book;
}

// Function to read a book
void read_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    printf("Contents:\n%s\n", book->contents);
}

// Function to free the memory allocated for a book
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->contents);
    free(book);
}

// Main function
int main() {
    // Create a new book
    Book *book = create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 183, "All the questions, but no answers.");

    // Read the book
    read_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}