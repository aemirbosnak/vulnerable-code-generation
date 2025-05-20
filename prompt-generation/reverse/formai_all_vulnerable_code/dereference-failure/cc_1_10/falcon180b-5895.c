//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
typedef struct {
    char title[100];
    char author[100];
    int pages;
    char *content;
} Book;

// Function to read a book from a file
Book read_book(FILE *file) {
    Book book;
    char line[256];

    // Read the title
    fgets(line, 256, file);
    strcpy(book.title, line);

    // Read the author
    fgets(line, 256, file);
    strcpy(book.author, line);

    // Read the number of pages
    fscanf(file, "%d", &book.pages);

    // Allocate memory for the content
    book.content = malloc(book.pages * 1024);

    // Read the content
    int i = 0;
    while (fgets(line, 256, file)) {
        strcat(book.content, line);
        i++;
        if (i == book.pages) {
            break;
        }
    }

    return book;
}

// Function to display a book
void display_book(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Pages: %d\n", book.pages);
    printf("Content:\n%s", book.content);
}

// Function to free memory allocated for a book
void free_book(Book book) {
    free(book.content);
}

int main() {
    // Open the book file
    FILE *file = fopen("book.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the book
    Book book = read_book(file);

    // Display the book
    display_book(book);

    // Free memory allocated for the book
    free_book(book);

    // Close the book file
    fclose(file);

    return 0;
}