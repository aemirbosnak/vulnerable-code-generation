//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the book structure
typedef struct book {
    char *title;
    char *author;
    int num_pages;
    char *genre;
} Book;

// Create a new book
Book *create_book(char *title, char *author, int num_pages, char *genre) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->genre = strdup(genre);
    return book;
}

// Print the book information
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Genre: %s\n", book->genre);
}

// Read the book from a file
Book *read_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char line[1024];
    char *title = NULL;
    char *author = NULL;
    int num_pages = 0;
    char *genre = NULL;

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "Title:")) {
            title = strdup(line + 7);
        } else if (strstr(line, "Author:")) {
            author = strdup(line + 8);
        } else if (strstr(line, "Number of pages:")) {
            num_pages = atoi(line + 17);
        } else if (strstr(line, "Genre:")) {
            genre = strdup(line + 7);
        }
    }

    fclose(fp);

    Book *book = create_book(title, author, num_pages, genre);
    free(title);
    free(author);
    free(genre);
    return book;
}

// Write the book to a file
void write_book(char *filename, Book *book) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return;
    }

    fprintf(fp, "Title: %s\n", book->title);
    fprintf(fp, "Author: %s\n", book->author);
    fprintf(fp, "Number of pages: %d\n", book->num_pages);
    fprintf(fp, "Genre: %s\n", book->genre);

    fclose(fp);
}

// Free the book
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->genre);
    free(book);
}

// Main function
int main() {
    // Create a new book
    Book *book = create_book("The Catcher in the Rye", "J.D. Salinger", 277, "Fiction");

    // Print the book information
    print_book(book);

    // Write the book to a file
    write_book("catcher.txt", book);

    // Read the book from a file
    Book *book2 = read_book("catcher.txt");

    // Print the book information
    print_book(book2);

    // Free the books
    free_book(book);
    free_book(book2);

    return 0;
}