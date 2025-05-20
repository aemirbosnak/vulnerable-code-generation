//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold a book with its title, author, and pages
typedef struct {
    char *title;
    char *author;
    int pages;
} book_t;

// Function to allocate memory for a book
book_t *alloc_book(void) {
    book_t *book = malloc(sizeof(book_t));
    book->title = malloc(20 * sizeof(char));
    book->author = malloc(20 * sizeof(char));
    book->pages = 0;
    return book;
}

// Function to deallocate memory for a book
void free_book(book_t *book) {
    free(book->title);
    free(book->author);
    free(book);
}

// Function to print a book's details
void print_book(book_t *book) {
    printf("Book: %s by %s, %d pages\n", book->title, book->author, book->pages);
}

// Function to create a list of books
book_t **create_book_list(int size) {
    book_t **books = malloc(size * sizeof(book_t *));
    for (int i = 0; i < size; i++) {
        books[i] = alloc_book();
    }
    return books;
}

// Function to print the list of books
void print_book_list(book_t **books, int size) {
    for (int i = 0; i < size; i++) {
        print_book(books[i]);
    }
}

int main() {
    // Create a list of 5 books
    book_t **books = create_book_list(5);

    // Allocate memory for each book in the list
    for (int i = 0; i < 5; i++) {
        books[i] = alloc_book();
    }

    // Print the list of books
    print_book_list(books, 5);

    // Deallocate memory for each book in the list
    for (int i = 0; i < 5; i++) {
        free_book(books[i]);
    }

    // Free the memory allocated for the list of books
    free(books);

    return 0;
}