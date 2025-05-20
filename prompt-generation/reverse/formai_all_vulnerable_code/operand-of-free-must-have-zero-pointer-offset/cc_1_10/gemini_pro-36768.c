//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOK_SIZE 1000000

// Book structure
typedef struct {
    char title[256];
    char author[256];
    char text[MAX_BOOK_SIZE];
    int num_pages;
} Book;

// Function to read a book from a file
Book* read_book(char* filename) {
    // Open the file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return NULL;
    }

    // Allocate memory for the book
    Book* book = malloc(sizeof(Book));
    if (book == NULL) {
        printf("Error: could not allocate memory for book\n");
        fclose(fp);
        return NULL;
    }

    // Read the title and author
    fscanf(fp, "%s %s", book->title, book->author);

    // Read the text
    char* text = malloc(MAX_BOOK_SIZE);
    if (text == NULL) {
        printf("Error: could not allocate memory for text\n");
        fclose(fp);
        free(book);
        return NULL;
    }
    int num_chars = fread(text, 1, MAX_BOOK_SIZE, fp);
    text[num_chars] = '\0';
    strcpy(book->text, text);
    free(text);

    // Read the number of pages
    fscanf(fp, "%d", &book->num_pages);

    // Close the file
    fclose(fp);

    // Return the book
    return book;
}

// Function to print a book
void print_book(Book* book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Text: %s\n", book->text);
    printf("Number of pages: %d\n", book->num_pages);
}

// Function to free the memory allocated for a book
void free_book(Book* book) {
    if (book == NULL) {
        return;
    }
    free(book->text);
    free(book);
}

// Main function
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Read the book
    Book* book = read_book(argv[1]);
    if (book == NULL) {
        return 1;
    }

    // Print the book
    print_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}