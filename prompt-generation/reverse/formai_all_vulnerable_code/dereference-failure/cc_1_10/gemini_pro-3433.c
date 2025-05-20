//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
typedef struct {
    char *title;
    char *author;
    int num_pages;
    char *text;
} Book;

// Function to create a new book
Book *create_book(char *title, char *author, int num_pages, char *text) {
    Book *book = malloc(sizeof(Book));
    book->title = malloc(strlen(title) + 1);
    strcpy(book->title, title);
    book->author = malloc(strlen(author) + 1);
    strcpy(book->author, author);
    book->num_pages = num_pages;
    book->text = malloc(strlen(text) + 1);
    strcpy(book->text, text);
    return book;
}

// Function to free the memory allocated for a book
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->text);
    free(book);
}

// Function to print the details of a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Text: %s\n", book->text);
}

int main() {
    // Create a new book
    Book *book = create_book("The Catcher in the Rye", "J.D. Salinger", 277, "In the beginning, I was all set to tell you my whole lousy autobiography. I mean, you were asking me where I was born, and what my lousy childhood was like, and how my parents were occupied and all before they had me, and all that David Copperfield kind of crap, but I don't feel like it. I really don't. That stuff bores me, and I'm sure as hell it would bore you.");

    // Print the details of the book
    print_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}