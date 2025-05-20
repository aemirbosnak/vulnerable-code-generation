//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    int num_pages;
    char **pages;
} Book;

Book *book_new(char *title, char *author, int num_pages) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->pages = malloc(sizeof(char *) * num_pages);
    for (int i = 0; i < num_pages; i++) {
        book->pages[i] = NULL;
    }
    return book;
}

void book_free(Book *book) {
    free(book->title);
    free(book->author);
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i]);
    }
    free(book->pages);
    free(book);
}

int main() {
    Book *book = book_new("The Catcher in the Rye", "J.D. Salinger", 277);

    // Load the book's pages from a file
    FILE *fp = fopen("catcher.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    char line[1024];
    int page = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        book->pages[page] = strdup(line);
        page++;
    }
    fclose(fp);

    // Print the book's title and author
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);

    // Print the first page of the book
    printf("Page 1:\n%s", book->pages[0]);

    // Free the book's memory
    book_free(book);

    return EXIT_SUCCESS;
}