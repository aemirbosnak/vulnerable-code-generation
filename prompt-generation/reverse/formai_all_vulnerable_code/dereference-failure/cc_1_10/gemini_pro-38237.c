//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a page
typedef struct {
    char *text;
    int numLines;
} Page;

// Define the structure of a book
typedef struct {
    char *title;
    int numPages;
    Page *pages;
} Book;

// Create a new book
Book *newBook(char *title, int numPages) {
    Book *book = malloc(sizeof(Book));
    book->title = title;
    book->numPages = numPages;
    book->pages = malloc(sizeof(Page) * numPages);
    return book;
}

// Add a page to a book
void addPage(Book *book, char *text) {
    int numLines = 0;
    char *line = strtok(text, "\n");
    while (line != NULL) {
        numLines++;
        line = strtok(NULL, "\n");
    }

    Page page = {text, numLines};
    book->pages[book->numPages++] = page;
}

// Read a book
void readBook(Book *book) {
    printf("Title: %s\n", book->title);
    for (int i = 0; i < book->numPages; i++) {
        Page page = book->pages[i];
        printf("Page %d:\n", i + 1);
        for (int j = 0; j < page.numLines; j++) {
            printf("%s\n", page.text[j]);
        }
    }
}

// Free the memory allocated for a book
void freeBook(Book *book) {
    for (int i = 0; i < book->numPages; i++) {
        free(book->pages[i].text);
    }
    free(book->pages);
    free(book->title);
    free(book);
}

// Main function
int main() {
    // Create a new book
    Book *book = newBook("The Canterbury Tales", 24);

    // Add pages to the book
    addPage(book, "Whan that Aprille with his shoures soote");
    addPage(book, "The droghte of March hath perced to the roote");
    addPage(book, "And bathed every veyne in swich licour");
    addPage(book, "Of which vertu engendred is the flour");

    // Read the book
    readBook(book);

    // Free the memory allocated for the book
    freeBook(book);

    return 0;
}