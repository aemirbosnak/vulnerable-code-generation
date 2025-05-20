//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *text;
    int len;
} Page;

typedef struct {
    int num_pages;
    Page *pages;
} Book;

Book *new_book(int num_pages) {
    Book *book = malloc(sizeof(Book));
    book->num_pages = num_pages;
    book->pages = malloc(sizeof(Page) * num_pages);
    return book;
}

void free_book(Book *book) {
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i].text);
    }
    free(book->pages);
    free(book);
}

Page *new_page(char *text, int len) {
    Page *page = malloc(sizeof(Page));
    page->text = malloc(len + 1);
    strcpy(page->text, text);
    page->len = len;
    return page;
}

void free_page(Page *page) {
    free(page->text);
    free(page);
}

void add_page(Book *book, Page *page) {
    book->pages[book->num_pages++] = *page;
}

void print_book(Book *book) {
    for (int i = 0; i < book->num_pages; i++) {
        printf("%s", book->pages[i].text);
    }
}

int main() {
    Book *book = new_book(3);
    add_page(book, new_page("Once upon a time...", 18));
    add_page(book, new_page("there was a little girl...", 25));
    add_page(book, new_page("who lived in a small village.", 27));
    print_book(book);
    free_book(book);
    return 0;
}