//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a book.
typedef struct {
    char *title;
    char *author;
    int num_pages;
    char *text;
} Book;

// Create a new book.
Book *new_book(char *title, char *author, int num_pages, char *text) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->text = strdup(text);
    return book;
}

// Free the memory allocated for a book.
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->text);
    free(book);
}

// Open a book file.
FILE *open_book(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return file;
}

// Read a book from a file.
Book *read_book(FILE *file) {
    char title[256];
    char author[256];
    int num_pages;
    char text[65536];

    // Read the title of the book.
    fgets(title, 256, file);

    // Read the author of the book.
    fgets(author, 256, file);

    // Read the number of pages in the book.
    fscanf(file, "%d\n", &num_pages);

    // Read the text of the book.
    while (!feof(file)) {
        fgets(text, 65536, file);
    }

    // Create a new book.
    Book *book = new_book(title, author, num_pages, text);

    // Close the file.
    fclose(file);

    return book;
}

// Print a book to the console.
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Text: %s\n", book->text);
}

// Main function.
int main(int argc, char **argv) {
    // Check if the user has provided a filename.
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the book file.
    FILE *file = open_book(argv[1]);

    // Read the book from the file.
    Book *book = read_book(file);

    // Print the book to the console.
    print_book(book);

    // Free the memory allocated for the book.
    free_book(book);

    return EXIT_SUCCESS;
}