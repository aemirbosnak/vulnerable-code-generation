//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct book {
    char *title;
    char *author;
    int num_pages;
    char *content;
} book;

// Function to read a book from a file
book *read_book(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Allocate memory for the book
    book *b = malloc(sizeof(book));
    if (b == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return NULL;
    }

    // Read the book's title
    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        perror("Error reading title");
        fclose(fp);
        free(b);
        return NULL;
    }
    b->title = strdup(buffer);

    // Read the book's author
    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        perror("Error reading author");
        fclose(fp);
        free(b);
        return NULL;
    }
    b->author = strdup(buffer);

    // Read the book's number of pages
    if (fscanf(fp, "%d", &b->num_pages) != 1) {
        perror("Error reading number of pages");
        fclose(fp);
        free(b);
        return NULL;
    }

    // Read the book's content
    b->content = malloc(b->num_pages * sizeof(char));
    if (b->content == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        free(b);
        return NULL;
    }
    if (fread(b->content, sizeof(char), b->num_pages, fp) != b->num_pages) {
        perror("Error reading content");
        fclose(fp);
        free(b);
        return NULL;
    }

    // Close the file
    fclose(fp);

    // Return the book
    return b;
}

// Function to print a book
void print_book(book *b) {
    // Print the book's title
    printf("Title: %s", b->title);

    // Print the book's author
    printf("Author: %s", b->author);

    // Print the book's number of pages
    printf("Number of pages: %d", b->num_pages);

    // Print the book's content
    printf("Content: %s", b->content);
}

// Function to free the memory allocated for a book
void free_book(book *b) {
    // Free the book's title
    free(b->title);

    // Free the book's author
    free(b->author);

    // Free the book's content
    free(b->content);

    // Free the book itself
    free(b);
}

int main(int argc, char *argv[]) {
    // Check if a filename was provided
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read the book from the file
    book *b = read_book(argv[1]);
    if (b == NULL) {
        return EXIT_FAILURE;
    }

    // Print the book
    print_book(b);

    // Free the memory allocated for the book
    free_book(b);

    return EXIT_SUCCESS;
}