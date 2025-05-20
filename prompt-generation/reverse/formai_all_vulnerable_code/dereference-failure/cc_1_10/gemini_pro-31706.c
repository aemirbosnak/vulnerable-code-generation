//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *title;
    char *author;
    char *text;
    size_t num_pages;
} Book;

typedef struct {
    Book *books;
    size_t capacity;
    size_t count;
} Library;

Library *create_library(void) {
    Library *library = malloc(sizeof(Library));
    library->capacity = 10;
    library->count = 0;
    library->books = malloc(sizeof(Book) * library->capacity);
    return library;
}

void destroy_library(Library *library) {
    for (size_t i = 0; i < library->count; i++) {
        free(library->books[i].title);
        free(library->books[i].author);
        free(library->books[i].text);
    }
    free(library->books);
    free(library);
}

bool add_book_to_library(Library *library, Book *book) {
    if (library->count == library->capacity) {
        library->capacity *= 2;
        library->books = realloc(library->books, sizeof(Book) * library->capacity);
    }
    library->books[library->count++] = *book;
    return true;
}

Book *find_book_by_title(Library *library, const char *title) {
    for (size_t i = 0; i < library->count; i++) {
        if (strcmp(library->books[i].title, title) == 0) {
            return &library->books[i];
        }
    }
    return NULL;
}

void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Text: %s\n", book->text);
    printf("Num pages: %zu\n", book->num_pages);
}

int main(void) {
    Library *library = create_library();

    Book book1 = {
        .title = "The Catcher in the Rye",
        .author = "J.D. Salinger",
        .text = "The Catcher in the Rye is a novel by J.D. Salinger that was first published in 1951. The novel's protagonist is Holden Caulfield, a teenage boy who has just been expelled from Pencey Prep, an elite boarding school. Holden is intelligent and perceptive, but he is also deeply cynical and alienated. He sees the world as a phony and corrupt place, and he is disgusted by the superficiality and hypocrisy of adults. Holden's journey through New York City is a search for authenticity and meaning in a world that he finds increasingly meaningless.",
        .num_pages = 277
    };
    add_book_to_library(library, &book1);

    Book book2 = {
        .title = "The Great Gatsby",
        .author = "F. Scott Fitzgerald",
        .text = "The Great Gatsby is a novel by F. Scott Fitzgerald that was first published in 1925. The novel tells the story of Jay Gatsby, a self-made millionaire who throws lavish parties in West Egg, Long Island, in the hopes of winning back the love of his life, Daisy Buchanan.",
        .num_pages = 180
    };
    add_book_to_library(library, &book2);

    Book *book = find_book_by_title(library, "The Catcher in the Rye");
    if (book != NULL) {
        print_book(book);
    } else {
        printf("Book not found.\n");
    }

    destroy_library(library);

    return EXIT_SUCCESS;
}