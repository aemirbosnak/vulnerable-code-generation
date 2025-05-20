//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book structure
typedef struct Book {
    char title[50];
    char author[50];
    int pages;
    char *content;
} Book;

// Function to create a new book
Book *createBook(char *title, char *author, int pages, char *content) {
    Book *book = (Book *)malloc(sizeof(Book));
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->pages = pages;
    book->content = (char *)malloc(strlen(content) + 1);
    strcpy(book->content, content);
    return book;
}

// Function to read a book from a file
Book *readBookFromFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the title, author, and pages
    char title[50];
    char author[50];
    int pages;
    fscanf(fp, "%s %s %d\n", title, author, &pages);

    // Read the content of the book
    char *content = (char *)malloc(sizeof(char) * 10000);
    while (!feof(fp)) {
        char line[1000];
        fgets(line, 1000, fp);
        strcat(content, line);
    }

    // Close the file
    fclose(fp);

    // Create a new book and return it
    Book *book = createBook(title, author, pages, content);
    return book;
}

// Function to print a book
void printBook(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    printf("Content:\n%s\n", book->content);
}

// Main function
int main() {
    // Read a book from a file
    Book *book = readBookFromFile("book.txt");

    // Print the book
    printBook(book);

    // Free the memory allocated for the book
    free(book->content);
    free(book);

    return 0;
}