//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
typedef struct book
{
    char *title;
    char *author;
    int num_pages;
} book;

// Create a new book
book *create_book(char *title, char *author, int num_pages)
{
    // Allocate memory for the book
    book *new_book = malloc(sizeof(book));

    // Copy the title, author, and number of pages into the book
    new_book->title = strdup(title);
    new_book->author = strdup(author);
    new_book->num_pages = num_pages;

    // Return the new book
    return new_book;
}

// Free the memory allocated for a book
void free_book(book *book)
{
    // Free the memory allocated for the title and author
    free(book->title);
    free(book->author);

    // Free the memory allocated for the book
    free(book);
}

// Print the information about a book
void print_book(book *book)
{
    // Print the title, author, and number of pages of the book
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
}

// Main function
int main()
{
    // Create a new book
    book *book = create_book("The Catcher in the Rye", "J.D. Salinger", 277);

    // Print the information about the book
    print_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}