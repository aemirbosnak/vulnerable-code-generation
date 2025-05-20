//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct book {
    char *title;
    char *author;
    int num_pages;
    char *content;
    int pgNo;
} Book;

// Function to create a new book
Book *create_book(char *title, char *author, int num_pages, char *content) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->content = strdup(content);
    book->pgNo = 0;
    return book;
}

// Function to read turn a page back in a book
void prev_page(Book *book) {
    if (book->pgNo > 0) {
        book->pgNo--;
    }
}

// Function to read turn a page forward in a book
void next_page(Book *book) {
    if (book->pgNo < book->num_pages - 1) {
        book->pgNo++;
    }
}

// Function to print the current page of a book
void print_page(Book *book) {
    printf("%s\n", book->content + book->pgNo * 1000);
}

// Function to free the memory allocated for a book
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->content);
    free(book);
}

// Main function
int main() {
    // Create a new book
    Book *book = create_book("The Lord of the Rings", "J.R.R. Tolkien", 1200, "In a hole in the ground there lived a hobbit. Not a nasty, dirty, wet hole, filled with the ends of worms and an oozy smell, nor yet a dry, bare, sandy hole with nothing in it to sit down on or to eat: it was a hobbit-hole, and that means comfort.");

    // Read the first page of the book
    print_page(book);

    // Turn to the next page
    next_page(book);

    // Read the second page of the book
    print_page(book);

    // Turn to the previous page
    prev_page(book);

    // Read the first page of the book again
    print_page(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}