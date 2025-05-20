//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
typedef struct Book {
    char *title;
    char *author;
    int pages;
    char *text;
} Book;

// Create a new book
Book *new_book(char *title, char *author, int pages, char *text) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->pages = pages;
    book->text = strdup(text);
    return book;
}

// Free the memory allocated for a book
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->text);
    free(book);
}

// Print the information about a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    printf("Text: %s\n", book->text);
}

// Read a book from a file
Book *read_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the title of the book
    char title[100];
    fgets(title, 100, fp);

    // Read the author of the book
    char author[100];
    fgets(author, 100, fp);

    // Read the number of pages in the book
    int pages;
    fscanf(fp, "%d", &pages);

    // Read the text of the book
    char *text = malloc(10000);
    fgets(text, 10000, fp);

    // Close the file
    fclose(fp);

    // Create a new book
    Book *book = new_book(title, author, pages, text);

    return book;
}

// Write a book to a file
void write_book(Book *book, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return;
    }

    // Write the title of the book
    fprintf(fp, "%s\n", book->title);

    // Write the author of the book
    fprintf(fp, "%s\n", book->author);

    // Write the number of pages in the book
    fprintf(fp, "%d\n", book->pages);

    // Write the text of the book
    fprintf(fp, "%s\n", book->text);

    // Close the file
    fclose(fp);
}

// Main function
int main() {
    // Create a new book
    Book *book = new_book("The Catcher in the Rye", "J.D. Salinger", 277, "In the early years of the 20th century, Holden Caulfield, a teenage boy from New York City, is expelled from Pencey Prep, an elite boarding school. Holden decides to run away from home and spend a few days in New York City.");

    // Print the information about the book
    print_book(book);

    // Write the book to a file
    write_book(book, "catcher_in_the_rye.txt");

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}