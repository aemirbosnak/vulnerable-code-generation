//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book structure
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

// Function to free a book
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book);
}

// Function to turn a page in a book
void turn_page(Book *book) {
    if (book->current_page < book->num_pages) {
        book->current_page++;
    }
}

// Function to print a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Current page: %d\n", book->current_page);
}

// Main function
int main() {
    // Create a new book
    Book *book = create_book("The Catcher in the Rye", "J.D. Salinger", 277);

    // Print the book
    print_book(book);

    // Turn a page in the book
    turn_page(book);

    // Print the book again
    print_book(book);

    // Free the book
    free_book(book);

    return 0;
}