//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct Book {
    char *title;
    char *author;
    int num_pages;
    char *content;
} Book;

// Function to create a new book
Book *create_book(char *title, char *author, int num_pages, char *content) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->content = strdup(content);
    return book;
}

// Function to free the memory allocated for a book
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->content);
    free(book);
}

// Function to print the details of a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Content:\n%s\n", book->content);
}

// Function to read a book from a file
Book *read_book_from_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the title of the book
    char title[100];
    if (fgets(title, 100, fp) == NULL) {
        perror("Error reading title");
        fclose(fp);
        return NULL;
    }

    // Read the author of the book
    char author[100];
    if (fgets(author, 100, fp) == NULL) {
        perror("Error reading author");
        fclose(fp);
        return NULL;
    }

    // Read the number of pages in the book
    int num_pages;
    if (fscanf(fp, "%d", &num_pages) != 1) {
        perror("Error reading number of pages");
        fclose(fp);
        return NULL;
    }

    // Read the content of the book
    char *content = malloc(sizeof(char) * 10000);
    if (fgets(content, 10000, fp) == NULL) {
        perror("Error reading content");
        fclose(fp);
        return NULL;
    }

    // Close the file
    fclose(fp);

    // Create a new book with the data read from the file
    Book *book = create_book(title, author, num_pages, content);

    // Free the memory allocated for the content
    free(content);

    return book;
}

// Function to write a book to a file
void write_book_to_file(Book *book, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Write the title of the book
    fprintf(fp, "%s\n", book->title);

    // Write the author of the book
    fprintf(fp, "%s\n", book->author);

    // Write the number of pages in the book
    fprintf(fp, "%d\n", book->num_pages);

    // Write the content of the book
    fprintf(fp, "%s\n", book->content);

    // Close the file
    fclose(fp);
}

// Function to main
int main() {
    // Create a new book
    Book *book = create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 184, "A hilarious and thought-provoking novel about a human who travels through space with his alien friend.");

    // Print the details of the book
    print_book(book);

    // Write the book to a file
    write_book_to_file(book, "book.txt");

    // Read the book from a file
    Book *book2 = read_book_from_file("book.txt");

    // Print the details of the book
    print_book(book2);

    // Free the memory allocated for the books
    free_book(book);
    free_book(book2);

    return 0;
}