//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store book data
typedef struct Book {
    char *title;
    char *author;
    char *genre;
    int pages;
    char *content;
} Book;

// Function to create a new book
Book *createBook(char *title, char *author, char *genre, int pages, char *content) {
    Book *book = malloc(sizeof(Book));
    if (book == NULL) {
        return NULL;
    }

    book->title = strdup(title);
    book->author = strdup(author);
    book->genre = strdup(genre);
    book->pages = pages;
    book->content = strdup(content);

    return book;
}

// Function to read a book from a file
Book *readBookFromFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char *title = NULL;
    char *author = NULL;
    char *genre = NULL;
    int pages = 0;
    char *content = NULL;

    // Read the title
    size_t titleLen;
    getline(&title, &titleLen, fp);

    // Read the author
    size_t authorLen;
    getline(&author, &authorLen, fp);

    // Read the genre
    size_t genreLen;
    getline(&genre, &genreLen, fp);

    // Read the number of pages
    fscanf(fp, "%d", &pages);

    // Read the content
    size_t contentLen;
    getline(&content, &contentLen, fp);

    // Close the file
    fclose(fp);

    // Create the book
    Book *book = createBook(title, author, genre, pages, content);

    return book;
}

// Function to print a book to the console
void printBook(Book *book) {
    printf("%s\n", book->title);
    printf("%s\n", book->author);
    printf("%s\n", book->genre);
    printf("%d\n", book->pages);
    printf("%s\n", book->content);
}

// Function to free the memory allocated for a book
void freeBook(Book *book) {
    free(book->title);
    free(book->author);
    free(book->genre);
    free(book->content);
    free(book);
}

int main() {
    // Create a book
    Book *book = createBook("The Great Gatsby", "F. Scott Fitzgerald", "Novel", 180, "Once upon a time...");

    // Print the book to the console
    printBook(book);

    // Free the memory allocated for the book
    freeBook(book);

    return 0;
}