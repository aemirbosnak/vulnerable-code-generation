//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    int num_pages;
} Book;

typedef struct {
    Book *books;
    int num_books;
} Library;

void add_book(Library *library, Book *book) {
    library->books = realloc(library->books, (library->num_books + 1) * sizeof(Book));
    library->books[library->num_books++] = *book;
}

void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
}

void print_library(Library *library) {
    for (int i = 0; i < library->num_books; i++) {
        print_book(&library->books[i]);
        printf("\n");
    }
}

int main() {
    Library library;
    library.books = NULL;
    library.num_books = 0;

    Book book1;
    book1.title = "The Lord of the Rings";
    book1.author = "J.R.R. Tolkien";
    book1.num_pages = 1207;

    Book book2;
    book2.title = "The Hitchhiker's Guide to the Galaxy";
    book2.author = "Douglas Adams";
    book2.num_pages = 184;

    Book book3;
    book3.title = "1984";
    book3.author = "George Orwell";
    book3.num_pages = 328;

    add_book(&library, &book1);
    add_book(&library, &book2);
    add_book(&library, &book3);

    print_library(&library);

    return 0;
}