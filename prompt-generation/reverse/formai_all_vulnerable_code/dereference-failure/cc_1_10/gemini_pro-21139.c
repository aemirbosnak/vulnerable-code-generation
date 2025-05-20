//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char *title;
    char *author;
    int num_pages;
    float rating;
    struct book *next;
};

struct library {
    struct book *head;
    struct book *tail;
};

struct library *create_library() {
    struct library *library = malloc(sizeof(struct library));
    if (library == NULL) {
        perror("malloc");
        exit(1);
    }
    library->head = NULL;
    library->tail = NULL;
    return library;
}

void add_book(struct library *library, char *title, char *author, int num_pages, float rating) {
    struct book *book = malloc(sizeof(struct book));
    if (book == NULL) {
        perror("malloc");
        exit(1);
    }
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->rating = rating;
    book->next = NULL;
    if (library->head == NULL) {
        library->head = book;
        library->tail = book;
    } else {
        library->tail->next = book;
        library->tail = book;
    }
}

void print_library(struct library *library) {
    struct book *book;
    for (book = library->head; book != NULL; book = book->next) {
        printf("%s by %s (%d pages, %.1f rating)\n", book->title, book->author, book->num_pages, book->rating);
    }
}

void free_library(struct library *library) {
    struct book *book, *next;
    for (book = library->head; book != NULL; book = next) {
        next = book->next;
        free(book->title);
        free(book->author);
        free(book);
    }
    free(library);
}

int main() {
    struct library *library = create_library();
    add_book(library, "The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 184, 4.2);
    add_book(library, "The Lord of the Rings", "J.R.R. Tolkien", 1207, 4.9);
    add_book(library, "To Kill a Mockingbird", "Harper Lee", 324, 4.8);
    print_library(library);
    free_library(library);
    return 0;
}