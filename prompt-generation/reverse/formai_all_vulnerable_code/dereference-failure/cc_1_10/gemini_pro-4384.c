//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    int num_pages;
    char **pages;
} Book;

Book *create_book(char *title, char *author, int num_pages) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->pages = malloc(sizeof(char *) * num_pages);
    return book;
}

void destroy_book(Book *book) {
    free(book->title);
    free(book->author);
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i]);
    }
    free(book->pages);
    free(book);
}

int main() {
    Book *book = create_book("The Catcher in the Rye", "J.D. Salinger", 277);

    // Add pages to the book
    for (int i = 0; i < book->num_pages; i++) {
        char *page = malloc(1024);
        sprintf(page, "Page %d", i + 1);
        book->pages[i] = page;
    }

    // Print the book's title and author
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);

    // Print the first page of the book
    printf("Page 1:\n%s\n", book->pages[0]);

    // Destroy the book
    destroy_book(book);

    return 0;
}