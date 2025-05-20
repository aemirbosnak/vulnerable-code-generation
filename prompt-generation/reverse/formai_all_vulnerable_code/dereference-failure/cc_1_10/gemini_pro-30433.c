//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
typedef struct book {
    char *title;
    char *author;
    int num_pages;
    char *text;
} book;

// Create a new book
book *create_book(char *title, char *author, int num_pages, char *text) {
    book *new_book = malloc(sizeof(book));
    new_book->title = malloc(strlen(title) + 1);
    strcpy(new_book->title, title);
    new_book->author = malloc(strlen(author) + 1);
    strcpy(new_book->author, author);
    new_book->num_pages = num_pages;
    new_book->text = malloc(strlen(text) + 1);
    strcpy(new_book->text, text);
    return new_book;
}

// Open a book from a file
book *open_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char *title = malloc(100);
    char *author = malloc(100);
    int num_pages;
    char *text = malloc(10000);

    fscanf(fp, "%s %s %d %s", title, author, &num_pages, text);

    fclose(fp);

    return create_book(title, author, num_pages, text);
}

// Close a book
void close_book(book *book) {
    free(book->title);
    free(book->author);
    free(book->text);
    free(book);
}

// Print a book
void print_book(book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Text: %s\n", book->text);
}

// Main function
int main() {
    // Create a new book
    book *book = create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 184, "In the beginning, the Universe was created. This has made a lot of people very angry and been widely regarded as a bad move.");

    // Print the book
    print_book(book);

    // Close the book
    close_book(book);

    return 0;
}