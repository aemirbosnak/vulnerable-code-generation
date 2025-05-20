//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple structure to represent a book.
typedef struct {
    char *title;
    char *author;
    int pages;
} Book;

// A function to read a book from a file.
Book *read_book(char *filename) {
    // Open the file.
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Allocate memory for the book.
    Book *book = malloc(sizeof(Book));
    if (book == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return NULL;
    }

    // Read the title.
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, fp);
    book->title = strdup(line);

    // Read the author.
    getline(&line, &len, fp);
    book->author = strdup(line);

    // Read the number of pages.
    int pages;
    fscanf(fp, "%d", &pages);
    book->pages = pages;

    // Close the file.
    fclose(fp);

    return book;
}

// A function to print a book.
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
}

// A function to free the memory allocated for a book.
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book);
}

int main(int argc, char *argv[]) {
    // Check if the user provided a filename.
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read the book from the file.
    Book *book = read_book(argv[1]);
    if (book == NULL) {
        return EXIT_FAILURE;
    }

    // Print the book.
    print_book(book);

    // Free the memory allocated for the book.
    free_book(book);

    return EXIT_SUCCESS;
}