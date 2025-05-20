//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BOOK_LENGTH 100000
#define MAX_PAGES 50

typedef struct {
    char *title;
    char *author;
    int pages;
    int words;
} Book;

typedef struct {
    Book book;
    int page;
} Page;

// Function to read a book from a file and store it in memory
Book *read_book(char *filename) {
    Book *book = malloc(sizeof(Book));
    char line[100];
    int words = 0;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: unable to open file %s\n", filename);
        return NULL;
    }

    // Read the book title and author
    fgets(line, 100, file);
    book->title = strtok(line, " ");
    fgets(line, 100, file);
    book->author = strtok(line, " ");

    // Read the number of pages
    fscanf(file, "%d", &book->pages);

    // Read the number of words in each page
    for (int i = 0; i < book->pages; i++) {
        fscanf(file, "%d", &words);
        book->words += words;
    }

    // Close the file
    fclose(file);

    return book;
}

// Function to display the book's statistics
void display_stats(Book *book) {
    printf("Book Statistics:\n");
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    printf("Words: %d\n", book->words);
}

// Function to display the book's text
void display_text(Book *book, int page) {
    char line[100];
    int words = 0;

    FILE *file = fopen(book->title, "r");
    if (file == NULL) {
        printf("Error: unable to open file %s\n", book->title);
        return;
    }

    // Read the text for the specified page
    fgets(line, 100, file);
    words = strcspn(line, "\n");

    // Display the text
    printf("Page %d: %s\n", page, line);

    // Close the file
    fclose(file);
}

int main() {
    Book *book = read_book("book.txt");
    if (book == NULL) {
        return 1;
    }

    display_stats(book);

    for (int i = 1; i <= book->pages; i++) {
        display_text(book, i);
    }

    return 0;
}