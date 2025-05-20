//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book struct
typedef struct Book {
    char *title;
    char *author;
    int pages;
    int current_page;
} Book;

// Create a new book
Book *create_book(char *title, char *author, int pages) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->pages = pages;
    book->current_page = 0;
    return book;
}

// Free a book
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book);
}

// Print a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    printf("Current page: %d\n", book->current_page);
}

// Turn a page
void turn_page(Book *book, int page) {
    if (page < 1 || page > book->pages) {
        printf("Invalid page number.\n");
        return;
    }
    book->current_page = page;
}

// Main function
int main() {
    // Create a new book
    Book *book = create_book("The Iliad", "Homer", 683);

    // Print the book
    print_book(book);

    // Turn a page
    turn_page(book, 100);

    // Print the book
    print_book(book);

    // Free the book
    free_book(book);

    return 0;
}