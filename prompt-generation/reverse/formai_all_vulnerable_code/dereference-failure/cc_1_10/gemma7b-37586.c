//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 1024

typedef struct Book {
    char **pages;
    int pages_count;
    int current_page;
} Book;

Book *book_create(int pages_count) {
    Book *book = malloc(sizeof(Book));
    book->pages = malloc(sizeof(char *) * pages_count);
    book->pages_count = pages_count;
    book->current_page = 0;

    for (int i = 0; i < pages_count; i++) {
        book->pages[i] = malloc(PAGE_SIZE);
    }

    return book;
}

void book_add_page(Book *book, char *page_content) {
    book->pages[book->pages_count] = malloc(PAGE_SIZE);
    strcpy(book->pages[book->pages_count], page_content);
    book->pages_count++;
}

void book_turn_page(Book *book) {
    book->current_page++;
    if (book->current_page >= book->pages_count - 1) {
        book->current_page = book->pages_count - 1;
    }
}

void book_read_page(Book *book) {
    printf("%s", book->pages[book->current_page]);
}

int main() {
    Book *book = book_create(10);

    book_add_page(book, "This is the first page.");
    book_add_page(book, "This is the second page.");
    book_add_page(book, "This is the third page.");

    book_turn_page(book);
    book_read_page(book);

    free(book->pages);
    free(book);

    return 0;
}