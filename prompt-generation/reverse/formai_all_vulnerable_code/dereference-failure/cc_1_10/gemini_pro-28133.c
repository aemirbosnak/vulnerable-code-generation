//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to represent a book
struct Book {
    char *title;
    char *author;
    int num_pages;
};

// Function to create a new book
struct Book *create_book(char *title, char *author, int num_pages) {
    struct Book *book = malloc(sizeof(struct Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    return book;
}

// Function to free the memory allocated for a book
void free_book(struct Book *book) {
    free(book->title);
    free(book->author);
    free(book);
}

// Function to print the details of a book
void print_book(struct Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
}

// Function to read a book from a file
struct Book *read_book(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Read the title of the book
    read = getline(&line, &len, file);
    if (read == -1) {
        fclose(file);
        free(line);
        return NULL;
    }
    char *title = strdup(line);

    // Read the author of the book
    read = getline(&line, &len, file);
    if (read == -1) {
        fclose(file);
        free(line);
        free(title);
        return NULL;
    }
    char *author = strdup(line);

    // Read the number of pages in the book
    int num_pages;
    fscanf(file, "%d", &num_pages);

    // Create a new book with the data read from the file
    struct Book *book = create_book(title, author, num_pages);

    // Free the memory allocated for the line buffer
    free(line);

    // Close the file
    fclose(file);

    return book;
}

// Function to write a book to a file
void write_book(struct Book *book, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return;
    }

    // Write the title of the book to the file
    fprintf(file, "%s\n", book->title);

    // Write the author of the book to the file
    fprintf(file, "%s\n", book->author);

    // Write the number of pages in the book to the file
    fprintf(file, "%d\n", book->num_pages);

    // Close the file
    fclose(file);
}

int main() {
    // Create a new book
    struct Book *book = create_book("The Catcher in the Rye", "J. D. Salinger", 277);

    // Print the details of the book
    print_book(book);

    // Write the book to a file
    write_book(book, "catcher_in_the_rye.txt");

    // Read the book from the file
    struct Book *book2 = read_book("catcher_in_the_rye.txt");

    // Print the details of the book
    print_book(book2);

    // Free the memory allocated for the books
    free_book(book);
    free_book(book2);

    return 0;
}