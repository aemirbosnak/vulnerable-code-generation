//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
typedef struct Book {
    char *title;
    char *author;
    int num_pages;
    char **pages;
} Book;

// Create a new book
Book *create_book(char *title, char *author, int num_pages) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->pages = malloc(sizeof(char *) * num_pages);
    return book;
}

// Free the memory allocated for a book
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i]);
    }
    free(book->pages);
    free(book);
}

// Read a book from a file
Book *read_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char line[1024];
    int num_lines = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        num_lines++;
    }
    fclose(fp);

    Book *book = create_book("Unknown", "Unknown", num_lines);

    fp = fopen(filename, "r");
    for (int i = 0; i < num_lines; i++) {
        fgets(line, sizeof(line), fp);
        line[strlen(line) - 1] = '\0';  // Remove the newline character
        book->pages[i] = strdup(line);
    }
    fclose(fp);

    return book;
}

// Print a book to the console
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    for (int i = 0; i < book->num_pages; i++) {
        printf("Page %d: %s\n", i + 1, book->pages[i]);
    }
}

// Main function
int main() {
    // Read the book from the file
    Book *book = read_book("book.txt");

    // Print the book to the console
    print_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}