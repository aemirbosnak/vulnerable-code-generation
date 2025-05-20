//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BOOK_SIZE 1024
#define MAX_PAGE_SIZE 64
#define MAX_CHAPTERS 10

// Structure to store book information
typedef struct {
    char title[50];
    char author[50];
    int chapterCount;
    int pageCount;
    char *pages;
} Book;

// Function to initialize book data
void initBook(Book *book) {
    book->title[0] = '\0';
    book->author[0] = '\0';
    book->chapterCount = 0;
    book->pageCount = 0;
    book->pages = NULL;
}

// Function to add a chapter to the book
void addChapter(Book *book, char *chapterName) {
    // Calculate the number of pages in the chapter
    int chapterPageCount = (strlen(chapterName) + 3) / 4;

    // Allocate memory for the chapter pages
    char *chapterPages = (char *)malloc(chapterPageCount * MAX_PAGE_SIZE);

    // Fill the chapter pages with random text
    for (int i = 0; i < chapterPageCount; i++) {
        chapterPages[i] = 'A' + (rand() % 26);
    }

    // Add the chapter to the book
    book->chapterCount++;
    book->pages = realloc(book->pages, book->pageCount + chapterPageCount * MAX_PAGE_SIZE);
    memcpy(book->pages + book->pageCount, chapterPages, chapterPageCount * MAX_PAGE_SIZE);
    book->pageCount += chapterPageCount;

    free(chapterPages);
}

// Function to display the book
void displayBook(Book *book) {
    printf("Book Title: %s\n", book->title);
    printf("Book Author: %s\n", book->author);
    printf("Chapters:\n");

    for (int i = 0; i < book->chapterCount; i++) {
        printf("Chapter %d: %s\n", i + 1, book->pages + (i * MAX_PAGE_SIZE));
    }

    printf("\n");
}

int main() {
    Book book;

    // Initialize the book data
    initBook(&book);

    // Add some chapters to the book
    addChapter(&book, "Chapter 1");
    addChapter(&book, "Chapter 2");
    addChapter(&book, "Chapter 3");

    // Display the book
    displayBook(&book);

    return 0;
}