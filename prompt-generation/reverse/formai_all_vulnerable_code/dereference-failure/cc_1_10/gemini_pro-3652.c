//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: grateful
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
    Book *book = (Book *)malloc(sizeof(Book));
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
    printf("Rating: %.1f\n", book->rating);
}

// Function to read a book from a file
Book *readBook(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    char title[256];
    char author[256];
    int pages;
    float rating;

    fscanf(fp, "%s", title);
    fscanf(fp, "%s", author);
    fscanf(fp, "%d", &pages);
    fscanf(fp, "%f", &rating);

    fclose(fp);

    return createBook(title, author, pages, rating);
}

// Main function
int main() {
    Book *book = readBook("book.txt");
    if (book == NULL) {
        printf("Error reading book from file\n");
        return 1;
    }

    printBook(book);

    return 0;
}