//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EPS 0.000001

typedef struct {
    char title[50];
    char author[50];
    int pages;
    float price;
} Book;

typedef struct {
    int num_books;
    Book books[10];
} Library;

void init_library(Library *lib) {
    lib->num_books = 0;
    memset(lib->books, 0, sizeof(lib->books));
}

void add_book(Library *lib, const char *title, const char *author, int pages, float price) {
    Book *book = &lib->books[lib->num_books];
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->pages = pages;
    book->price = price;
    lib->num_books++;
}

void list_books(Library *lib) {
    printf("Books in the library:\n");
    for (int i = 0; i < lib->num_books; i++) {
        Book *book = &lib->books[i];
        printf("  %s by %s (%d pages, %f dollars)\n", book->title, book->author, book->pages, book->price);
    }
}

int main() {
    Library lib;

    // Add some books to the library
    add_book(&lib, "The Great Gatsby", "F. Scott Fitzgerald", 224, 12.99);
    add_book(&lib, "To Kill a Mockingbird", "Harper Lee", 304, 14.99);
    add_book(&lib, "Pride and Prejudice", "Jane Austen", 384, 19.99);

    // List the books in the library
    list_books(&lib);

    return 0;
}