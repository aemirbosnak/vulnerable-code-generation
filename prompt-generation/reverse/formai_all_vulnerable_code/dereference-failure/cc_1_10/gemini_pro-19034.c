//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a book
typedef struct Book {
    char *title;
    char *author;
    int num_pages;
} Book;

// Read a book from a file
Book *read_book(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Allocate memory for the book
    Book *book = malloc(sizeof(Book));
    if (book == NULL) {
        fclose(file);
        return NULL;
    }

    // Read the title
    char line[1024];
    fgets(line, sizeof(line), file);
    book->title = malloc(strlen(line) + 1);
    strcpy(book->title, line);

    // Read the author
    fgets(line, sizeof(line), file);
    book->author = malloc(strlen(line) + 1);
    strcpy(book->author, line);

    // Read the number of pages
    fscanf(file, "%d", &book->num_pages);

    // Close the file
    fclose(file);

    // Return the book
    return book;
}

// Print a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
}

// Free a book
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book);
}

// Main function
int main() {
    // Read a book from a file
    Book *book = read_book("book.txt");
    if (book == NULL) {
        printf("Error reading book.\n");
        return 1;
    }

    // Print the book
    print_book(book);

    // Free the book
    free_book(book);

    return 0;
}