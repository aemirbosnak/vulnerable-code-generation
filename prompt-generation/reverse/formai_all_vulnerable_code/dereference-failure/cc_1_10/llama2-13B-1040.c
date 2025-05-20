//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct to represent a "book"
struct book {
    char title[50];
    char author[50];
    int pages;
};

// Define a function to allocate memory for a book
struct book *alloc_book(void) {
    struct book *book = malloc(sizeof(struct book));
    book->title[0] = '\0';
    book->author[0] = '\0';
    book->pages = 0;
    return book;
}

// Define a function to deallocate memory for a book
void free_book(struct book *book) {
    free(book);
}

// Define a function to print a book's information
void print_book(struct book *book) {
    printf("Title: %s\nAuthor: %s\nPages: %d\n", book->title, book->author, book->pages);
}

int main() {
    // Allocate memory for 5 books
    struct book *books[5];
    for (int i = 0; i < 5; i++) {
        books[i] = alloc_book();
    }

    // Print the information of each book
    for (int i = 0; i < 5; i++) {
        print_book(books[i]);
    }

    // Deallocate memory for each book
    for (int i = 0; i < 5; i++) {
        free_book(books[i]);
    }

    // Print a message after all books are deallocated
    printf("All books have been deallocated!\n");

    return 0;
}