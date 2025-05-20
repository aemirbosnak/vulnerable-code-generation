//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a book
typedef struct Book {
    char *title;
    char *author;
    int pages;
    float rating;
} Book;

// Function to create a new book
Book *createBook(char *title, char *author, int pages, float rating) {
    Book *book = malloc(sizeof(Book));
    book->title = title;
    book->author = author;
    book->pages = pages;
    book->rating = rating;
    return book;
}

// Function to print a book
void printBook(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    printf("Rating: %.1f\n\n", book->rating);
}

// Function to read a book from a file
Book *readBook(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Read the title, author, pages, and rating from the file
    char title[100];
    char author[100];
    int pages;
    float rating;
    fscanf(file, "%s %s %d %f", title, author, &pages, &rating);

    // Create a new book with the data from the file
    Book *book = createBook(title, author, pages, rating);

    // Close the file
    fclose(file);

    return book;
}

// Main function
int main() {
    // Read a book from a file
    Book *book = readBook("book.txt");

    // Print the book
    printBook(book);

    // Free the memory allocated for the book
    free(book->title);
    free(book->author);
    free(book);

    return 0;
}