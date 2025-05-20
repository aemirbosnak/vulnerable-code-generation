//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: dynamic
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
    book *new_book = malloc(sizeof(book));
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
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the title of the book
    char *title = malloc(100);
    fgets(title, 100, fp);

    // Read the author of the book
    char *author = malloc(100);
    fgets(author, 100, fp);

    // Read the number of pages in the book
    int num_pages;
    fscanf(fp, "%d", &num_pages);

    // Read the content of the book
    char *content = malloc(num_pages);
    fread(content, num_pages, 1, fp);

    // Close the file
    fclose(fp);

    // Create a new book with the data from the file
    book *new_book = create_book(title, author, num_pages, content);

    // Free the memory allocated for the title, author, and content
    free(title);
    free(author);
    free(content);

    return new_book;
}

// Write a book to a file
void write_book(book *book, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Write the title of the book
    fprintf(fp, "%s\n", book->title);

    // Write the author of the book
    fprintf(fp, "%s\n", book->author);

    // Write the number of pages in the book
    fprintf(fp, "%d\n", book->num_pages);

    // Write the content of the book
    fwrite(book->content, book->num_pages, 1, fp);

    // Close the file
    fclose(fp);
}

// Main function
int main() {
    // Create a new book
    book *book = create_book("The Catcher in the Rye", "J.D. Salinger", 277, "In the beginning of the story the main character, Holden Caulfield, is kicked out of a boarding school because of his flunking out of four subjects. His parents send him to a psychiatrist.");

    // Print the details of the book
    print_book(book);

    // Write the book to a file
    write_book(book, "catcher_in_the_rye.txt");

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}