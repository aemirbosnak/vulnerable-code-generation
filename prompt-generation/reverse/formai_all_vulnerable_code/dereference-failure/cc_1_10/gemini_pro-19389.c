//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book structure
typedef struct Book {
    char *title;
    char *author;
    int num_pages;
    char *content;
} Book;

// Function to create a new book
Book *create_book(char *title, char *author, int num_pages, char *content) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->content = strdup(content);
    return book;
}

// Function to open a book file and create a new book object
Book *open_book(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening book file: %s\n", filename);
        return NULL;
    }

    // Read the title
    char title[256];
    fgets(title, 256, file);

    // Read the author
    char author[256];
    fgets(author, 256, file);

    // Read the number of pages
    int num_pages;
    fscanf(file, "%d", &num_pages);

    // Read the content
    char *content = malloc(sizeof(char) * 65536);
    fread(content, sizeof(char), 65536, file);

    // Close the file
    fclose(file);

    // Create a new book object
    Book *book = create_book(title, author, num_pages, content);
    return book;
}

// Function to close a book and free its resources
void close_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->content);
    free(book);
}

// Function to print the contents of a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Content:\n%s", book->content);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <book_file>\n", argv[0]);
        return 1;
    }

    // Open the book file
    Book *book = open_book(argv[1]);
    if (book == NULL) {
        return 1;
    }

    // Print the contents of the book
    print_book(book);

    // Close the book and free its resources
    close_book(book);

    return 0;
}