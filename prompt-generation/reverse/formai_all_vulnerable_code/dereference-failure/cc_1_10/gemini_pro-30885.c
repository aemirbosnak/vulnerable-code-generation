//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book structure
typedef struct book {
    char *title;
    char *author;
    int num_pages;
    char **pages;
} book;

// Create a new book
book *create_book(char *title, char *author, int num_pages) {
    book *new_book = malloc(sizeof(book));
    new_book->title = strdup(title);
    new_book->author = strdup(author);
    new_book->num_pages = num_pages;
    new_book->pages = malloc(sizeof(char *) * num_pages);
    for (int i = 0; i < num_pages; i++) {
        new_book->pages[i] = malloc(sizeof(char) * 100);
    }
    return new_book;
}

// Free the memory allocated for a book
void free_book(book *book) {
    free(book->title);
    free(book->author);
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i]);
    }
    free(book->pages);
    free(book);
}

// Print the book
void print_book(book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    for (int i = 0; i < book->num_pages; i++) {
        printf("Page %d:\n%s\n", i + 1, book->pages[i]);
    }
}

// Load a book from a file
book *load_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the title, author, and number of pages
    char title[100];
    char author[100];
    int num_pages;
    fscanf(fp, "%s %s %d", title, author, &num_pages);

    // Create the book
    book *new_book = create_book(title, author, num_pages);

    // Read the pages
    for (int i = 0; i < num_pages; i++) {
        char page[100];
        fscanf(fp, "%s", page);
        strcpy(new_book->pages[i], page);
    }

    fclose(fp);
    return new_book;
}

// Save a book to a file
void save_book(book *book, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return;
    }

    // Write the title, author, and number of pages
    fprintf(fp, "%s %s %d\n", book->title, book->author, book->num_pages);

    // Write the pages
    for (int i = 0; i < book->num_pages; i++) {
        fprintf(fp, "%s\n", book->pages[i]);
    }

    fclose(fp);
}

// Main function
int main() {
    // Create a book
    book *my_book = create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 100);

    // Print the book
    print_book(my_book);

    // Load a book from a file
    book *loaded_book = load_book("book.txt");

    // Print the loaded book
    print_book(loaded_book);

    // Save the book to a file
    save_book(my_book, "book.txt");

    // Free the memory allocated for the books
    free_book(my_book);
    free_book(loaded_book);

    return 0;
}