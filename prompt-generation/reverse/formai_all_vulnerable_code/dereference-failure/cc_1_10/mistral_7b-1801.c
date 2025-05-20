//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Medieval library for string manipulation
typedef struct book {
    char title[100];
    char author[50];
    struct book* next;
} Book;

void print_book(Book* b) {
    printf("Title: %s\n", b->title);
    printf("Author: %s\n", b->author);
}

Book* create_book(char* title, char* author) {
    Book* new_book = (Book*) malloc(sizeof(Book));
    strcpy(new_book->title, title);
    strcpy(new_book->author, author);
    new_book->next = NULL;
    return new_book;
}

void add_book_to_library(Book** library, Book* new_book) {
    if (*library == NULL) {
        *library = new_book;
    } else {
        Book* current = *library;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_book;
    }
}

void search_book_by_author(Book* library, char* author) {
    Book* current = library;
    while (current != NULL) {
        if (strcmp(current->author, author) == 0) {
            print_book(current);
            return;
        }
        current = current->next;
    }
    printf("No book found with author: %s\n", author);
}

int main() {
    // Initialize medieval library
    Book* library = NULL;

    // Add some books to the library
    add_book_to_library(&library, create_book("The Canterbury Tales", "Geoffrey Chaucer"));
    add_book_to_library(&library, create_book("Sir Gawain and the Green Knight", "Anonymous"));
    add_book_to_library(&library, create_book("Le Morte d'Arthur", "Sir Thomas Malory"));

    // Search for a book by author
    search_book_by_author(library, "Anonymous");

    // Free memory
    Book* current = library;
    while (current != NULL) {
        Book* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}