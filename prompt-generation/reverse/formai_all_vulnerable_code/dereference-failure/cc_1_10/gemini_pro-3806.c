//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the page structure
typedef struct page {
    int num;
    char *text;
} page_t;

// Define the book structure
typedef struct book {
    char *title;
    int num_pages;
    page_t *pages;
} book_t;

// Create a new book
book_t *new_book(char *title, int num_pages) {
    book_t *book = malloc(sizeof(book_t));
    book->title = strdup(title);
    book->num_pages = num_pages;
    book->pages = malloc(sizeof(page_t) * num_pages);
    return book;
}

// Free a book
void free_book(book_t *book) {
    free(book->title);
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i].text);
    }
    free(book->pages);
    free(book);
}

// Load a book from a file
book_t *load_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the title
    char title[256];
    fgets(title, 256, fp);

    // Read the number of pages
    int num_pages;
    fscanf(fp, "%d\n", &num_pages);

    // Create a new book
    book_t *book = new_book(title, num_pages);

    // Read the pages
    for (int i = 0; i < num_pages; i++) {
        // Read the page number
        int num;
        fscanf(fp, "%d\n", &num);

        // Read the page text
        char text[1024];
        fgets(text, 1024, fp);

        // Store the page in the book
        book->pages[i].num = num;
        book->pages[i].text = strdup(text);
    }

    fclose(fp);

    return book;
}

// Save a book to a file
void save_book(book_t *book, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return;
    }

    // Write the title
    fprintf(fp, "%s\n", book->title);

    // Write the number of pages
    fprintf(fp, "%d\n", book->num_pages);

    // Write the pages
    for (int i = 0; i < book->num_pages; i++) {
        // Write the page number
        fprintf(fp, "%d\n", book->pages[i].num);

        // Write the page text
        fprintf(fp, "%s\n", book->pages[i].text);
    }

    fclose(fp);
}

// Print a book
void print_book(book_t *book) {
    printf("Title: %s\n", book->title);
    printf("Number of pages: %d\n", book->num_pages);
    for (int i = 0; i < book->num_pages; i++) {
        printf("Page %d:\n", book->pages[i].num);
        printf("%s\n", book->pages[i].text);
    }
}

// Main function
int main() {
    // Load a book from a file
    book_t *book = load_book("book.txt");
    if (book == NULL) {
        printf("Error loading book.\n");
        return 1;
    }

    // Print the book
    print_book(book);

    // Save the book to a file
    save_book(book, "book.txt");

    // Free the book
    free_book(book);

    return 0;
}