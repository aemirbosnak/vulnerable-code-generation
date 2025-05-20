//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
typedef struct book {
    char *title;
    char *author;
    int num_pages;
    char *content;
} book;

// Create a new book
book *create_book(char *title, char *author, int num_pages, char *content) {
    book *new_book = (book *)malloc(sizeof(book));
    new_book->title = strdup(title);
    new_book->author = strdup(author);
    new_book->num_pages = num_pages;
    new_book->content = strdup(content);
    return new_book;
}

// Free the memory allocated for a book
void free_book(book *book) {
    free(book->title);
    free(book->author);
    free(book->content);
    free(book);
}

// Print the details of a book
void print_book(book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Content:\n%s\n", book->content);
}

// Read a book from a file
book *read_book(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Read the title of the book
    char *title = NULL;
    size_t title_len = 0;
    getline(&title, &title_len, file);

    // Read the author of the book
    char *author = NULL;
    size_t author_len = 0;
    getline(&author, &author_len, file);

    // Read the number of pages in the book
    int num_pages;
    fscanf(file, "%d\n", &num_pages);

    // Read the content of the book
    char *content = NULL;
    size_t content_len = 0;
    getline(&content, &content_len, file);

    // Close the file
    fclose(file);

    // Create a new book
    book *new_book = create_book(title, author, num_pages, content);

    // Free the memory allocated for the title, author, and content
    free(title);
    free(author);
    free(content);

    return new_book;
}

// Write a book to a file
void write_book(book *book, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return;
    }

    // Write the title of the book
    fprintf(file, "%s\n", book->title);

    // Write the author of the book
    fprintf(file, "%s\n", book->author);

    // Write the number of pages in the book
    fprintf(file, "%d\n", book->num_pages);

    // Write the content of the book
    fprintf(file, "%s\n", book->content);

    // Close the file
    fclose(file);
}

// Main function
int main() {
    // Create a new book
    book *book = create_book("The Catcher in the Rye", "J.D. Salinger", 277, "In the rye grass on the other side of the road from where I was standing, somebody was holding a football, but he wasn't doing anything with it.");

    // Print the details of the book
    print_book(book);

    // Write the book to a file
    write_book(book, "catcher_in_the_rye.txt");

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}