//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: relaxed
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

// Open a book file and read its contents into a book struct
book *open_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the title, author, and number of pages from the file
    char title[256];
    char author[256];
    int num_pages;
    fscanf(fp, "%s %s %d", title, author, &num_pages);

    // Allocate memory for the book text
    char *text = malloc(num_pages * 256);

    // Read the book text from the file
    int i;
    for (i = 0; i < num_pages; i++) {
        fgets(text + i * 256, 256, fp);
    }

    // Close the file
    fclose(fp);

    // Create a new book struct and populate it with the data from the file
    book *new_book = create_book(title, author, num_pages, text);

    // Return the new book struct
    return new_book;
}

// Print a book to the console
void print_book(book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Text:\n%s\n", book->text);
}

// Close a book and free its memory
void close_book(book *book) {
    free(book->title);
    free(book->author);
    free(book->text);
    free(book);
}

// Main function
int main() {
    // Open a book file
    book *book = open_book("book.txt");

    // Print the book to the console
    print_book(book);

    // Close the book and free its memory
    close_book(book);

    return 0;
}