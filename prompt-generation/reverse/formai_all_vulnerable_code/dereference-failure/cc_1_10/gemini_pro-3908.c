//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book structure
typedef struct Book {
    char *title;
    char *author;
    int pages;
    char *content;
} Book;

// Function to create a new book
Book *createBook(char *title, char *author, int pages, char *content) {
    Book *book = (Book *)malloc(sizeof(Book));
    book->title = (char *)malloc(strlen(title) + 1);
    strcpy(book->title, title);
    book->author = (char *)malloc(strlen(author) + 1);
    strcpy(book->author, author);
    book->pages = pages;
    book->content = (char *)malloc(strlen(content) + 1);
    strcpy(book->content, content);
    return book;
}

// Function to read a book from a file
Book *readBookFromFile(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Read the title
    char title[256];
    fgets(title, 256, file);

    // Read the author
    char author[256];
    fgets(author, 256, file);

    // Read the number of pages
    int pages;
    fscanf(file, "%d\n", &pages);

    // Read the content
    char content[10240];
    while (!feof(file)) {
        fgets(content, 10240, file);
    }

    // Create the book
    Book *book = createBook(title, author, pages, content);

    // Close the file
    fclose(file);

    return book;
}

// Function to print a book
void printBook(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    printf("Content: %s\n", book->content);
}

// Function to free the memory allocated for a book
void freeBook(Book *book) {
    free(book->title);
    free(book->author);
    free(book->content);
    free(book);
}

int main() {
    // Read the book from a file
    Book *book = readBookFromFile("book.txt");

    // Print the book
    printBook(book);

    // Free the memory allocated for the book
    freeBook(book);

    return 0;
}