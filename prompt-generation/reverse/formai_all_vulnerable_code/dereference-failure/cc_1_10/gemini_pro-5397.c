//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Surprise! It's an E-book reader! 😲

// Define the "book" struct to store the book's contents and metadata
typedef struct book {
    char title[100];
    char author[100];
    int num_pages;
    char *pages;
} book;

// Load a book from a file into memory
book *load_book(const char *filename) {
    // Surprise! We're using dynamic memory allocation! 😲
    book *new_book = malloc(sizeof(book));

    // Open the file
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Read the title and author
    fscanf(file, "%s %s\n", new_book->title, new_book->author);

    // Read the number of pages
    fscanf(file, "%d\n", &new_book->num_pages);

    // Surprise! We're using realloc to dynamically allocate memory for the pages! 😲
    new_book->pages = malloc(new_book->num_pages * sizeof(char *));

    // Read the pages
    for (int i = 0; i < new_book->num_pages; i++) {
        char *page = malloc(1000);
        fscanf(file, "%s\n", page);
        new_book->pages[i] = page;
    }

    // Close the file
    fclose(file);

    return new_book;
}

// Free the memory allocated for a book
void free_book(book *book) {
    // Surprise! We're using free to deallocate the dynamically allocated memory! 😲
    free(book->pages);
    free(book);
}

// Print the book's contents
void print_book(book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);

    // Surprise! We're using a loop to print each page! 😲
    for (int i = 0; i < book->num_pages; i++) {
        printf("Page %d:\n", i + 1);
        printf("%s\n", book->pages[i]);
    }
}

int main() {
    // Surprise! We're loading a book from a file! 😲
    book *book = load_book("book.txt");

    // Surprise! We're printing the book's contents! 😲
    print_book(book);

    // Surprise! We're freeing the memory allocated for the book! 😲
    free_book(book);

    return 0;
}