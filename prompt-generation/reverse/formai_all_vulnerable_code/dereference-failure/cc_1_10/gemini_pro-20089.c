//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct page {
    char *text;
    struct page *next;
};

struct book {
    struct page *first;
    struct page *last;
};

struct book *create_book() {
    struct book *book = malloc(sizeof(struct book));
    book->first = NULL;
    book->last = NULL;
    return book;
}

void add_page(struct book *book, char *text) {
    struct page *page = malloc(sizeof(struct page));
    page->text = strdup(text);
    page->next = NULL;
    if (book->first == NULL) {
        book->first = page;
        book->last = page;
    } else {
        book->last->next = page;
        book->last = page;
    }
}

void print_book(struct book *book) {
    struct page *page = book->first;
    while (page != NULL) {
        printf("%s\n", page->text);
        page = page->next;
    }
}

void free_book(struct book *book) {
    struct page *page = book->first;
    while (page != NULL) {
        struct page *next = page->next;
        free(page->text);
        free(page);
        page = next;
    }
    free(book);
}

int main() {
    struct book *book = create_book();
    add_page(book, "Once upon a time...");
    add_page(book, "There was a little girl...");
    add_page(book, "Who lived in a shoe...");
    print_book(book);
    free_book(book);
    return 0;
}