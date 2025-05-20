//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the book's metadata
typedef struct Book {
    char *title;
    char *author;
    int num_pages;
    int current_page;
} Book;

// Function to create a new book
Book *create_book(char *title, char *author, int num_pages) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->current_page = 1;
    return book;
}

// Function to destroy a book
void destroy_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book);
}

// Function to read a book
void read_book(Book *book) {
    while (book->current_page <= book->num_pages) {
        // Print the current page
        printf("Page %d:\n", book->current_page);
        printf("%s\n", book->title);
        printf("%s\n", book->author);
        for (int i = 0; i < 10; i++) {
            printf("%s\n", book->title);
        }
        // Increment the current page
        book->current_page++;
    }
}

// Main function
int main() {
    // Create a new book
    Book *book = create_book("The Catcher in the Rye", "J.D. Salinger", 277);

    // Read the book
    read_book(book);

    // Destroy the book
    destroy_book(book);

    return 0;
}