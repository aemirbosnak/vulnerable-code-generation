//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a struct to represent a book
typedef struct {
    char *title;
    char *author;
    int num_pages;
    char *text;
} Book;

// Declare a function to read a book from a file
Book *read_book(char *filename) {
    // Allocate memory for the book
    Book *book = malloc(sizeof(Book));

    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Read the title
    char line[1024];
    fgets(line, 1024, file);
    book->title = malloc(strlen(line) + 1);
    strcpy(book->title, line);

    // Read the author
    fgets(line, 1024, file);
    book->author = malloc(strlen(line) + 1);
    strcpy(book->author, line);

    // Read the number of pages
    fgets(line, 1024, file);
    book->num_pages = atoi(line);

    // Read the text
    book->text = malloc(1024 * book->num_pages);
    fread(book->text, 1024, book->num_pages, file);

    // Close the file
    fclose(file);

    // Return the book
    return book;
}

// Declare a function to print a book
void print_book(Book *book) {
    // Print the title
    printf("Title: %s\n", book->title);

    // Print the author
    printf("Author: %s\n", book->author);

    // Print the number of pages
    printf("Number of pages: %d\n", book->num_pages);

    // Print the text
    printf("Text:\n%s\n", book->text);
}

// Declare a function to free the memory allocated for a book
void free_book(Book *book) {
    // Free the title
    free(book->title);

    // Free the author
    free(book->author);

    // Free the text
    free(book->text);

    // Free the book
    free(book);
}

int main() {
    // Read a book from a file
    Book *book = read_book("book.txt");

    // Print the book
    print_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}