//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define the book structure
typedef struct book {
    char *title;
    char *author;
    int num_pages;
} book;

// Create a new book
book *create_book(char *title, char *author, int num_pages) {
    book *new_book = malloc(sizeof(book));
    new_book->title = title;
    new_book->author = author;
    new_book->num_pages = num_pages;
    return new_book;
}

// Print the book information
void print_book(book *b) {
    printf("Title: %s\n", b->title);
    printf("Author: %s\n", b->author);
    printf("Number of pages: %d\n", b->num_pages);
}

// Read a book from a file
book *read_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the book title
    char *title = malloc(100);
    fscanf(fp, "%s", title);

    // Read the book author
    char *author = malloc(100);
    fscanf(fp, "%s", author);

    // Read the number of pages
    int num_pages;
    fscanf(fp, "%d", &num_pages);

    // Create the book
    book *new_book = create_book(title, author, num_pages);

    // Close the file
    fclose(fp);

    return new_book;
}

// Free the memory allocated for a book
void free_book(book *b) {
    free(b->title);
    free(b->author);
    free(b);
}

// The main function
int main() {
    // Read the book from a file
    book *b = read_book("book.txt");

    // Print the book information
    print_book(b);

    // Free the memory allocated for the book
    free_book(b);

    return 0;
}