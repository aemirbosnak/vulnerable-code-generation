//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
typedef struct book {
    char *title;
    char *author;
    char *content;
    int num_pages;
} book;

// Function to create a new book
book *create_book(char *title, char *author, char *content, int num_pages) {
    // Allocate memory for the book
    book *new_book = malloc(sizeof(book));

    // Copy the title, author, and content into the book
    new_book->title = strdup(title);
    new_book->author = strdup(author);
    new_book->content = strdup(content);
    new_book->num_pages = num_pages;

    // Return the new book
    return new_book;
}

// Function to free the memory allocated for a book
void free_book(book *book) {
    // Free the memory allocated for the title, author, and content
    free(book->title);
    free(book->author);
    free(book->content);

    // Free the memory allocated for the book
    free(book);
}

// Function to print the contents of a book
void print_book(book *book) {
    // Print the title and author of the book
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);

    // Print the content of the book
    printf("Content:\n%s\n", book->content);

    // Print the number of pages in the book
    printf("Number of pages: %d\n", book->num_pages);
}

// Main function
int main() {
    // Create a new book
    book *my_book = create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "Far out in the uncharted backwaters of the unfashionable end of the western spiral arm of the Galaxy lies a small, unregarded yellow sun.", 152);

    // Print the contents of the book
    print_book(my_book);

    // Free the memory allocated for the book
    free_book(my_book);

    return 0;
}