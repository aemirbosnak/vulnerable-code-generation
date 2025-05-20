//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct Book {
    char title[50];
    char author[50];
    int pages;
    char *text;
} Book;

// Function to create a new book
Book *createBook(char *title, char *author, int pages, char *text) {
    Book *book = malloc(sizeof(Book));
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->pages = pages;
    book->text = malloc(strlen(text) + 1);
    strcpy(book->text, text);
    return book;
}

// Function to read a book from a file
Book *readBookFromFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    char title[50], author[50];
    int pages;
    char *text;

    fscanf(fp, "%s %s %d\n", title, author, &pages);

    // Read the text of the book
    text = malloc(10000);
    while (!feof(fp)) {
        char line[1000];
        fgets(line, 1000, fp);
        strcat(text, line);
    }

    fclose(fp);

    return createBook(title, author, pages, text);
}

// Function to print a book
void printBook(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    printf("Text:\n%s\n", book->text);
}

// Function to free the memory allocated for a book
void freeBook(Book *book) {
    free(book->text);
    free(book);
}

// Main function
int main() {
    // Read the book from a file
    Book *book = readBookFromFile("book.txt");
    if (book == NULL) {
        printf("Error reading book from file\n");
        return 1;
    }

    // Print the book
    printBook(book);

    // Free the memory allocated for the book
    freeBook(book);

    return 0;
}