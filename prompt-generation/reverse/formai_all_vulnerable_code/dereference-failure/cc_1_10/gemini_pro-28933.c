//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    int num_pages;
    char **pages;
} Book;

void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    for (int i = 0; i < book->num_pages; i++) {
        printf("Page %d:\n%s\n", i + 1, book->pages[i]);
    }
}

int main() {
    // Create a new book.
    Book *book = malloc(sizeof(Book));
    book->title = "The Hitchhiker's Guide to the Galaxy";
    book->author = "Douglas Adams";
    book->num_pages = 184;
    book->pages = malloc(book->num_pages * sizeof(char *));

    // Load the pages of the book from a file.
    FILE *fp = fopen("hitchhikers_guide.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < book->num_pages; i++) {
        book->pages[i] = malloc(1024);
        fgets(book->pages[i], 1024, fp);
    }
    fclose(fp);

    // Print the book.
    print_book(book);

    // Free the memory allocated for the book.
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i]);
    }
    free(book->pages);
    free(book);

    return EXIT_SUCCESS;
}