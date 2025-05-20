//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the book struct
typedef struct book {
    char *title;
    char *author;
    int num_pages;
    char *text;
} book;

// Create a new book
book *new_book(char *title, char *author, int num_pages, char *text) {
    book *b = malloc(sizeof(book));
    b->title = strdup(title);
    b->author = strdup(author);
    b->num_pages = num_pages;
    b->text = strdup(text);
    return b;
}

// Free the memory allocated for a book
void free_book(book *b) {
    free(b->title);
    free(b->author);
    free(b->text);
    free(b);
}

// Print the book to the console
void print_book(book *b) {
    printf("Title: %s\n", b->title);
    printf("Author: %s\n", b->author);
    printf("Number of pages: %d\n", b->num_pages);
    printf("Text: %s\n", b->text);
}

// Read a book from a file
book *read_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the title
    char *title = malloc(100);
    fscanf(fp, "%s\n", title);

    // Read the author
    char *author = malloc(100);
    fscanf(fp, "%s\n", author);

    // Read the number of pages
    int num_pages;
    fscanf(fp, "%d\n", &num_pages);

    // Read the text
    char *text = malloc(10000);
    while (!feof(fp)) {
        char *line = malloc(100);
        fscanf(fp, "%s\n", line);
        strcat(text, line);
    }

    // Close the file
    fclose(fp);

    // Create the book
    book *b = new_book(title, author, num_pages, text);

    // Free the memory allocated for the title, author, and text
    free(title);
    free(author);
    free(text);

    return b;
}

// Write a book to a file
void write_book(book *b, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return;
    }

    // Write the title
    fprintf(fp, "%s\n", b->title);

    // Write the author
    fprintf(fp, "%s\n", b->author);

    // Write the number of pages
    fprintf(fp, "%d\n", b->num_pages);

    // Write the text
    fprintf(fp, "%s\n", b->text);

    // Close the file
    fclose(fp);
}

// Main function
int main() {
    // Create a new book
    book *b = new_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 183, "The Hitchhiker's Guide to the Galaxy is a hilarious and thought-provoking novel that follows the adventures of Arthur Dent, a hapless Englishman who finds himself stranded on a foreign planet after the Earth is destroyed. The novel is full of wit, wisdom, and wonderful characters.");

    // Print the book to the console
    print_book(b);

    // Write the book to a file
    write_book(b, "book.txt");

    // Read the book from a file
    book *b2 = read_book("book.txt");

    // Print the book to the console
    print_book(b2);

    // Free the memory allocated for the books
    free_book(b);
    free_book(b2);

    return 0;
}