//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct book {
    char *title;
    char *author;
    int num_pages;
    float rating;
} book;

// Function to create a new book
book *create_book(char *title, char *author, int num_pages, float rating) {
    book *new_book = malloc(sizeof(book));
    new_book->title = strdup(title);
    new_book->author = strdup(author);
    new_book->num_pages = num_pages;
    new_book->rating = rating;
    return new_book;
}

// Function to print the details of a book
void print_book(book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Rating: %.1f\n", book->rating);
}

// Function to compare two books by their ratings
int compare_books(const void *a, const void *b) {
    book *book1 = (book *)a;
    book *book2 = (book *)b;
    return book1->rating - book2->rating;
}

// Main function
int main() {
    // Create an array of books
    book *books[] = {
        create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 184, 4.2),
        create_book("The Lord of the Rings", "J.R.R. Tolkien", 1207, 4.9),
        create_book("To Kill a Mockingbird", "Harper Lee", 324, 4.8),
        create_book("The Great Gatsby", "F. Scott Fitzgerald", 180, 4.2),
        create_book("1984", "George Orwell", 328, 4.7),
    };

    // Sort the books by their ratings
    qsort(books, sizeof(books) / sizeof(book *), sizeof(book *), compare_books);

    // Print the details of the sorted books
    for (int i = 0; i < sizeof(books) / sizeof(book *); i++) {
        print_book(books[i]);
        printf("\n");
    }

    // Free the memory allocated for the books
    for (int i = 0; i < sizeof(books) / sizeof(book *); i++) {
        free(books[i]->title);
        free(books[i]->author);
        free(books[i]);
    }

    return 0;
}