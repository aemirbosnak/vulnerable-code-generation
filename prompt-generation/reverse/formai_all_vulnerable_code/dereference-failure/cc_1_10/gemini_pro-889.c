//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
struct Book {
    char *title;
    char *author;
    int num_pages;
    char *text;
};

// Function to create a new book
struct Book *create_book(char *title, char *author, int num_pages, char *text) {
    struct Book *book = malloc(sizeof(struct Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->text = strdup(text);
    return book;
}

// Function to print a book
void print_book(struct Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Text: %s\n", book->text);
}

// Function to free the memory allocated for a book
void free_book(struct Book *book) {
    free(book->title);
    free(book->author);
    free(book->text);
    free(book);
}

// Main function
int main() {
    // Create a new book
    struct Book *book = create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 184, "In the beginning, the Universe was created. This has made a lot of people very angry and been widely regarded as a bad move.");

    // Print the book
    print_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}