//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct Book {
    char *title;
    char *author;
    int pages;
    char *genre;
} Book;

// Function to create a new book
Book *createBook(char *title, char *author, int pages, char *genre) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->pages = pages;
    book->genre = strdup(genre);
    return book;
}

// Function to print a book
void printBook(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    printf("Genre: %s\n", book->genre);
}

// Function to free a book
void freeBook(Book *book) {
    free(book->title);
    free(book->author);
    free(book->genre);
    free(book);
}

// Function to read a book from a file
Book *readBookFromFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char line[1024];
    char *title = NULL;
    char *author = NULL;
    int pages = 0;
    char *genre = NULL;

    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "Title:", 6) == 0) {
            title = strdup(line + 6);
        } else if (strncmp(line, "Author:", 7) == 0) {
            author = strdup(line + 7);
        } else if (strncmp(line, "Pages:", 6) == 0) {
            pages = atoi(line + 6);
        } else if (strncmp(line, "Genre:", 6) == 0) {
            genre = strdup(line + 6);
        }
    }

    fclose(fp);

    Book *book = createBook(title, author, pages, genre);

    free(title);
    free(author);
    free(genre);

    return book;
}

// Function to write a book to a file
void writeBookToFile(char *filename, Book *book) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return;
    }

    fprintf(fp, "Title: %s\n", book->title);
    fprintf(fp, "Author: %s\n", book->author);
    fprintf(fp, "Pages: %d\n", book->pages);
    fprintf(fp, "Genre: %s\n", book->genre);

    fclose(fp);
}

// Main function
int main() {
    // Create a new book
    Book *book = createBook("The Catcher in the Rye", "J.D. Salinger", 277, "Fiction");

    // Print the book
    printBook(book);

    // Write the book to a file
    writeBookToFile("catcher.txt", book);

    // Read the book from the file
    Book *book2 = readBookFromFile("catcher.txt");

    // Print the book
    printBook(book2);

    // Free the books
    freeBook(book);
    freeBook(book2);

    return 0;
}