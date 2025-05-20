//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the book structure
typedef struct book {
    char *title;
    char *author;
    int num_pages;
    char *text;
} book;

// Read a book from a file
book *read_book(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the title
    char *title = malloc(100);
    fscanf(fp, "%s", title);

    // Read the author
    char *author = malloc(100);
    fscanf(fp, "%s", author);

    // Read the number of pages
    int num_pages;
    fscanf(fp, "%d", &num_pages);

    // Read the text
    char *text = malloc(10000);
    while (!feof(fp)) {
        char buffer[100];
        fscanf(fp, "%s", buffer);
        strcat(text, buffer);
    }

    // Close the file
    fclose(fp);

    // Create the book
    book *book = malloc(sizeof(book));
    book->title = title;
    book->author = author;
    book->num_pages = num_pages;
    book->text = text;

    // Return the book
    return book;
}

// Print the book
void print_book(book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Text: %s\n", book->text);
}

// Free the book
void free_book(book *book) {
    free(book->title);
    free(book->author);
    free(book->text);
    free(book);
}

// Main function
int main() {
    // Read the book from a file
    book *book = read_book("book.txt");

    // Print the book
    print_book(book);

    // Free the book
    free_book(book);

    return 0;
}