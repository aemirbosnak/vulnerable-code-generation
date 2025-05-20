//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    char *content;
} Book;

typedef struct {
    int num_books;
    Book *books;
} Library;

Library *create_library(int num_books) {
    Library *library = malloc(sizeof(Library));
    library->num_books = num_books;
    library->books = malloc(sizeof(Book) * num_books);
    return library;
}

void add_book(Library *library, Book book) {
    library->books[library->num_books++] = book;
}

void print_book(Book book) {
    printf("\nTitle: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Content: %s\n", book.content);
}

void print_library(Library *library) {
    for (int i = 0; i < library->num_books; i++) {
        print_book(library->books[i]);
    }
}

void free_library(Library *library) {
    for (int i = 0; i < library->num_books; i++) {
        free(library->books[i].title);
        free(library->books[i].author);
        free(library->books[i].content);
    }
    free(library->books);
    free(library);
}

int main() {
    // Create a library with 3 books
    Library *library = create_library(3);

    // Add a book to the library
    Book book1 = {"The Catcher in the Rye", "J.D. Salinger", "The Catcher in the Rye is a novel by J.D. Salinger that was first published in 1951. The novel is narrated by Holden Caulfield, a teenage boy who has just been expelled from Pencey Prep, his third preparatory school in as many years."};
    add_book(library, book1);

    // Add another book to the library
    Book book2 = {"The Great Gatsby", "F. Scott Fitzgerald", "The Great Gatsby is a novel by F. Scott Fitzgerald that was first published in 1925. The novel tells the story of Jay Gatsby, a self-made millionaire who throws lavish parties in his West Egg mansion in the hopes of winning back his lost love, Daisy Buchanan."};
    add_book(library, book2);

    // Add another book to the library
    Book book3 = {"1984", "George Orwell", "1984 is a novel by George Orwell that was first published in 1949. The novel is set in a dystopian future where Oceania is ruled by the Party and its leader, Big Brother. The novel follows the life of Winston Smith, a Party member who works in the Ministry of Truth and who secretly rebels against the Party."};
    add_book(library, book3);

    // Print the library
    print_library(library);

    // Free the library
    free_library(library);

    return 0;
}