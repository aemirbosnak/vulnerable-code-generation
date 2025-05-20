//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BOOK_LENGTH 10000
#define MAX_CHAPTERS 10
#define MAX_PAGES 50

// Structure to hold book information
typedef struct {
    char title[50];
    char author[50];
    int pages;
    int chapters;
} book_t;

// Function to read a book from a file
book_t read_book(char *filename) {
    book_t book;
    FILE *file = fopen(filename, "r");
    char line[100];

    // Read book title
    fgets(line, 100, file);
    strcpy(book.title, line);

    // Read book author
    fgets(line, 100, file);
    strcpy(book.author, line);

    // Read book pages
    int pages = 0;
    while (fgets(line, 100, file)) {
        pages++;
    }
    book.pages = pages;

    // Read book chapters
    int chapters = 0;
    while (fgets(line, 100, file)) {
        chapters++;
    }
    book.chapters = chapters;

    fclose(file);
    return book;
}

// Function to display book information
void display_book(book_t book) {
    printf("Book: %s by %s\n", book.title, book.author);
    printf("Pages: %d Chapters: %d\n", book.pages, book.chapters);
}

// Function to read and display a book
int main() {
    char filename[50];
    printf("Enter the name of the book file: ");
    scanf("%49s", filename);

    book_t book = read_book(filename);
    display_book(book);

    return 0;
}