//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book structure
typedef struct Book {
    char title[100];
    char author[100];
    int num_pages;
    char *text;
} Book;

// Function to create a new book
Book *create_book(char *title, char *author, int num_pages, char *text) {
    Book *book = (Book *)malloc(sizeof(Book));
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->num_pages = num_pages;
    book->text = (char *)malloc(strlen(text) + 1);
    strcpy(book->text, text);
    return book;
}

// Function to read a book
void read_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Text:\n%s\n", book->text);
}

// Function to free the memory allocated for a book
void free_book(Book *book) {
    free(book->text);
    free(book);
}

// Main function
int main() {
    // Create a new book
    Book *book = create_book("The Catcher in the Rye", "J.D. Salinger", 277, "Holden Caulfield, a teenage boy from New York City, is expelled from Pencey Prep, an elite boarding school. He decides to run away from home and spend a few days in New York City before returning home. Over the course of three days, Holden wanders around the city, meeting a variety of people and having a series of adventures. He reflects on his life and relationships, and comes to a new understanding of himself and the world around him.");

    // Read the book
    read_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}