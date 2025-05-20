//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    int num_pages;
    char **pages;
} Book;

Book *new_book(char *title, char *author, int num_pages) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->pages = malloc(sizeof(char *) * num_pages);
    return book;
}

void free_book(Book *book) {
    free(book->title);
    free(book->author);
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i]);
    }
    free(book->pages);
    free(book);
}

int main() {
    Book *book = new_book("The Catcher in the Rye", "J.D. Salinger", 277);

    // Load the book's pages from a file
    FILE *fp = fopen("catcher.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < book->num_pages; i++) {
        char *page = malloc(1024);
        fgets(page, 1024, fp);
        book->pages[i] = page;
    }
    fclose(fp);

    // Print the book's information
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);

    // Print the first page of the book
    printf("\nFirst page:\n\n%s", book->pages[0]);

    // Free the book's memory
    free_book(book);

    return EXIT_SUCCESS;
}