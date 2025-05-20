//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Book structure
typedef struct {
    char *title;
    char *author;
    int num_pages;
    char **pages;
} Book;

// Function to create a new book
Book *create_book(char *title, char *author, int num_pages) {
    Book *book = (Book *)malloc(sizeof(Book));
    book->title = title;
    book->author = author;
    book->num_pages = num_pages;
    book->pages = (char **)malloc(num_pages * sizeof(char *));
    for (int i = 0; i < num_pages; i++) {
        book->pages[i] = (char *)malloc(100 * sizeof(char));
    }
    return book;
}

// Function to read a book from a file
Book *read_book(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return NULL;
    }

    // Read the title and author
    char title[100];
    char author[100];
    fscanf(file, "%s %s", title, author);

    // Read the number of pages
    int num_pages;
    fscanf(file, "%d", &num_pages);

    // Create the book
    Book *book = create_book(title, author, num_pages);

    // Read the pages
    for (int i = 0; i < num_pages; i++) {
        fscanf(file, "%s", book->pages[i]);
    }

    fclose(file);
    return book;
}

// Function to print a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    for (int i = 0; i < book->num_pages; i++) {
        printf("Page %d: %s\n", i + 1, book->pages[i]);
    }
}

// Function to free the memory allocated for a book
void free_book(Book *book) {
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i]);
    }
    free(book->pages);
    free(book);
}

int main() {
    // Read the book from a file
    Book *book = read_book("book.txt");

    // Print the book
    print_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}