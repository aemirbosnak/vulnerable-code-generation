//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the structure of a Sherlock Holmes book
typedef struct {
    char *title;
    char *author;
    int year;
    int pages;
    char *text;
} Book;

// Read a Sherlock Holmes book from a file
Book *read_book(char *filename) {
    // Allocate memory for the book
    Book *book = malloc(sizeof(Book));

    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the title, author, year, and pages from the file
    char line[1024];
    fgets(line, sizeof(line), file);
    book->title = strdup(line);
    fgets(line, sizeof(line), file);
    book->author = strdup(line);
    fgets(line, sizeof(line), file);
    book->year = atoi(line);
    fgets(line, sizeof(line), file);
    book->pages = atoi(line);

    // Read the text of the book from the file
    book->text = malloc(book->pages * sizeof(char));
    fread(book->text, sizeof(char), book->pages, file);

    // Close the file
    fclose(file);

    // Return the book
    return book;
}

// Print a Sherlock Holmes book to the console
void print_book(Book *book) {
    // Print the title, author, year, and pages of the book
    printf("Title: %s", book->title);
    printf("Author: %s", book->author);
    printf("Year: %d", book->year);
    printf("Pages: %d", book->pages);

    // Print the text of the book
    printf("%s", book->text);
}

// Free the memory allocated for a Sherlock Holmes book
void free_book(Book *book) {
    // Free the memory allocated for the title, author, and text
    free(book->title);
    free(book->author);
    free(book->text);

    // Free the memory allocated for the book
    free(book);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has specified a book to read
    if (argc < 2) {
        printf("Usage: %s <book>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read the book from the file
    Book *book = read_book(argv[1]);
    if (book == NULL) {
        return EXIT_FAILURE;
    }

    // Print the book to the console
    print_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return EXIT_SUCCESS;
}