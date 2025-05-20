//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *data;
    struct node *next;
} node_t;

typedef struct book {
    char *title;
    char *author;
    int num_pages;
    node_t *pages;
} book_t;

book_t *create_book(char *title, char *author, int num_pages) {
    book_t *book = malloc(sizeof(book_t));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->pages = NULL;
    return book;
}

void add_page(book_t *book, char *page) {
    node_t *new_page = malloc(sizeof(node_t));
    new_page->data = strdup(page);
    new_page->next = book->pages;
    book->pages = new_page;
}

void print_book(book_t *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    node_t *current_page = book->pages;
    while (current_page != NULL) {
        printf("%s\n", current_page->data);
        current_page = current_page->next;
    }
}

void free_book(book_t *book) {
    free(book->title);
    free(book->author);
    node_t *current_page = book->pages;
    while (current_page != NULL) {
        node_t *next_page = current_page->next;
        free(current_page->data);
        free(current_page);
        current_page = next_page;
    }
    free(book);
}

int main() {
    book_t *book = create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 184);
    add_page(book, "Far out in the uncharted backwaters of the unfashionable end of the western spiral arm of the Galaxy lies a small, unregarded yellow sun.");
    add_page(book, "Orbiting this at a distance of roughly ninety-eight million miles is an utterly insignificant little blue-green planet whose ape-descended life forms are so amazingly primitive that they still think digital watches are a pretty neat idea.");
    print_book(book);
    free_book(book);
    return 0;
}