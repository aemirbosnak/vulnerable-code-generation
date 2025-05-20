//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to represent a page of a book.
typedef struct Page {
    char *text;
    int num_lines;
} Page;

// A struct to represent a book.
typedef struct Book {
    char *title;
    char *author;
    int num_pages;
    Page *pages;
} Book;

// A function to create a new book.
Book *create_book(char *title, char *author, int num_pages) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->pages = malloc(sizeof(Page) * num_pages);
    return book;
}

// A function to free the memory allocated for a book.
void free_book(Book *book) {
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i].text);
    }
    free(book->pages);
    free(book->title);
    free(book->author);
    free(book);
}

// A function to add a page to a book.
void add_page(Book *book, char *text) {
    int num_lines = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '\n') {
            num_lines++;
        }
    }

    Page page;
    page.text = strdup(text);
    page.num_lines = num_lines;
    book->pages[book->num_pages++] = page;
}

// A function to print a book.
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    for (int i = 0; i < book->num_pages; i++) {
        printf("Page %d:\n", i + 1);
        printf("%s", book->pages[i].text);
    }
}

int main() {
    // Create a new book.
    Book *book = create_book("Romeo and Juliet", "William Shakespeare", 5);

    // Add pages to the book.
    add_page(book, "Two households, both alike in dignity,\nIn fair Verona, where we lay our scene,\nFrom ancient grudge break to new mutiny,\nWhere civil blood makes civil hands unclean.");
    add_page(book, "From forth the fatal loins of these two foes\nA pair of star-cross'd lovers take their life;\nWhole misadventured piteous overthrows\nDoth with their death bury their parents' strife.");
    add_page(book, "The fearful passage of their death-mark'd love,\nAnd the continuance of their parents' rage,\nWhich, but their children's end, nought could remove,\nIs now the two hours' traffic of our stage.");
    add_page(book, "The which if you with patient ears attend,\nWhat here shall miss, our toil shall strive to mend.");
    add_page(book, "Two households, both alike in dignity,\nIn fair Verona, where we lay our scene,\nFrom ancient grudge break to new mutiny,\nWhere civil blood makes civil hands unclean.");

    // Print the book.
    print_book(book);

    // Free the memory allocated for the book.
    free_book(book);

    return 0;
}