//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BOOK_NAME_LENGTH 50
#define MAX_AUTHOR_NAME_LENGTH 20
#define MAX_PAGE_COUNT 100

// Structure to store book information
typedef struct {
    char name[MAX_BOOK_NAME_LENGTH];
    char author[MAX_AUTHOR_NAME_LENGTH];
    int pageCount;
} book_t;

// Function to read book information from a file
book_t readBookInfo(FILE *file) {
    book_t book;

    // Read book name
    fscanf(file, "%s", book.name);

    // Read author name
    fscanf(file, "%s", book.author);

    // Read page count
    int pageCount;
    fscanf(file, "%d", &pageCount);
    book.pageCount = pageCount;

    return book;
}

// Function to display book information
void displayBookInfo(book_t book) {
    printf("Book: %s\n", book.name);
    printf("Author: %s\n", book.author);
    printf("Page Count: %d\n", book.pageCount);
}

// Function to read and display book information from a file
int main() {
    FILE *file = fopen("books.txt", "r");

    // Read book information from file
    book_t book = readBookInfo(file);

    // Display book information
    displayBookInfo(book);

    return 0;
}