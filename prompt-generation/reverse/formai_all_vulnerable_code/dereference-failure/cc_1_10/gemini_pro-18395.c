//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the supported file formats
#define FORMAT_TXT 1
#define FORMAT_EPUB 2
#define FORMAT_PDF 3

// Define the maximum line length
#define MAX_LINE_LENGTH 1024

// Define the maximum number of pages
#define MAX_PAGES 100

// Define the structure of a page
typedef struct {
    char *text;
    int length;
} Page;

// Define the structure of a book
typedef struct {
    int format;
    int num_pages;
    Page pages[MAX_PAGES];
} Book;

// Load a book from a file
Book *load_book(char *filename) {
    // Allocate memory for the book
    Book *book = malloc(sizeof(Book));

    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Determine the file format
    char *extension = strrchr(filename, '.');
    if (strcmp(extension, ".txt") == 0) {
        book->format = FORMAT_TXT;
    } else if (strcmp(extension, ".epub") == 0) {
        book->format = FORMAT_EPUB;
    } else if (strcmp(extension, ".pdf") == 0) {
        book->format = FORMAT_PDF;
    } else {
        fprintf(stderr, "Error: unsupported file format\n");
        return NULL;
    }

    // Read the book's contents
    char line[MAX_LINE_LENGTH];
    int page_index = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Allocate memory for the page
        book->pages[page_index].text = malloc(strlen(line) + 1);

        // Copy the line to the page
        strcpy(book->pages[page_index].text, line);

        // Increment the page index
        page_index++;
    }

    // Close the file
    fclose(file);

    // Return the book
    return book;
}

// Free the memory allocated for a book
void free_book(Book *book) {
    // Free the memory allocated for each page
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i].text);
    }

    // Free the memory allocated for the book
    free(book);
}

// Print a book to the console
void print_book(Book *book) {
    // Print each page of the book
    for (int i = 0; i < book->num_pages; i++) {
        printf("%s", book->pages[i].text);
    }
}

// The main function
int main(int argc, char *argv[]) {
    // Check if a filename was specified
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Load the book
    Book *book = load_book(argv[1]);
    if (book == NULL) {
        return EXIT_FAILURE;
    }

    // Print the book
    print_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return EXIT_SUCCESS;
}