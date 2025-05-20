//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// A curious struct to hold our book
struct Book {
    char *title;
    char *author;
    char *pages;
    int num_pages;
};

// A curious function to create a new book
struct Book *create_book(char *title, char *author, char *pages, int num_pages) {
    struct Book *book = malloc(sizeof(struct Book));
    if (book == NULL) {
        return NULL;
    }

    book->title = title;
    book->author = author;
    book->pages = pages;
    book->num_pages = num_pages;

    return book;
}

// A curious function to read a book
void read_book(struct Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %s\n", book->pages);
    printf("Number of pages: %d\n", book->num_pages);

    // Curious! We're going to flip through the pages
    for (int i = 0; i < book->num_pages; i++) {
        printf("%s\n", book->pages[i]);
    }
}

int main() {
    // Let's create a curious book
    struct Book *book = create_book("The Curious Case of Benjamin Button", "F. Scott Fitzgerald", "The curious case of Benjamin Button is a short story by F. Scott Fitzgerald. It was first published in Collier's Weekly on May 27, 1922. The story is about a man who is born old and ages backwards.", 12);

    // Let's read our curious book
    read_book(book);

    // Curious! We're done reading the book
    free(book);

    return 0;
}