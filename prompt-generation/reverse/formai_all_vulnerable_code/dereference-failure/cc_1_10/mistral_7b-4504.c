//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

typedef struct Page {
    char content[MAX_LENGTH];
    struct Page *next;
} Page;

typedef struct Book {
    char title[50];
    int numPages;
    Page *firstPage;
} Book;

void readBook(Book *book) {
    Page *currentPage = book->firstPage;
    int pageNumber = 1;

    printf("Reading %s...\n", book->title);

    while (currentPage != NULL) {
        printf("\nPage %d:\n%s", pageNumber, currentPage->content);
        currentPage = currentPage->next;
        pageNumber++;
    }
}

void addPage(Book *book, char *content) {
    Page *newPage = (Page *)malloc(sizeof(Page));
    strcpy(newPage->content, content);
    newPage->next = book->firstPage;
    book->firstPage = newPage;
    book->numPages++;
}

int main() {
    Book myBook = {"The C Programming Language", 0, NULL};

    addPage(&myBook, "This is the first page.");
    addPage(&myBook, "This is the second page.");
    addPage(&myBook, "This is the third page.");

    myBook.numPages = 3;

    readBook(&myBook);

    return 0;
}