//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book.
typedef struct {
    char *title;
    char *author;
    int num_pages;
    char *content;
} Book;

// Function to create a new book.
Book *new_book(char *title, char *author, int num_pages, char *content) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->content = strdup(content);
    return book;
}

// Function to free a book.
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->content);
    free(book);
}

// Function to print a book.
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of Pages: %d\n", book->num_pages);
    printf("Content:\n%s\n", book->content);
}

// Function to read a book from a file.
Book *read_book_from_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char *title = NULL;
    char *author = NULL;
    int num_pages = 0;
    char *content = NULL;

    // Read the title.
    size_t len = 0;
    getline(&title, &len, fp);

    // Read the author.
    getline(&author, &len, fp);

    // Read the number of pages.
    fscanf(fp, "%d", &num_pages);

    // Read the content.
    content = malloc(num_pages + 1);
    fread(content, num_pages, 1, fp);
    content[num_pages] = '\0';

    // Close the file.
    fclose(fp);

    // Create a new book.
    Book *book = new_book(title, author, num_pages, content);

    // Free the temporary variables.
    free(title);
    free(author);
    free(content);

    return book;
}

// Function to write a book to a file.
void write_book_to_file(Book *book, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return;
    }

    // Write the title.
    fprintf(fp, "%s\n", book->title);

    // Write the author.
    fprintf(fp, "%s\n", book->author);

    // Write the number of pages.
    fprintf(fp, "%d\n", book->num_pages);

    // Write the content.
    fwrite(book->content, book->num_pages, 1, fp);

    // Close the file.
    fclose(fp);
}

int main() {
    // Create a new book.
    Book *book = new_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 160, "Far out in the uncharted backwaters of the unfashionable end of the western spiral arm of the Galaxy lies a small, unassuming planet called Earth...");

    // Print the book.
    print_book(book);

    // Write the book to a file.
    write_book_to_file(book, "book.txt");

    // Free the book.
    free_book(book);

    return 0;
}