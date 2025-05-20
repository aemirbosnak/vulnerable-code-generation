//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_PAGES 1000
#define MAX_PAGE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
    char *pages_text[MAX_PAGES];
} Book;

int load_book(char *filename, Book *book) {
    FILE *fp;
    int i, j;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    book->pages = 0;
    while (fgets(book->pages_text[book->pages], MAX_PAGE_LENGTH, fp)!= NULL) {
        book->pages++;
    }

    fclose(fp);

    return 0;
}

void display_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    for (int i = 0; i < book->pages; i++) {
        printf("Page %d:\n%s", i+1, book->pages_text[i]);
    }
}

int main() {
    Book book;
    char filename[MAX_TITLE_LENGTH];

    printf("Enter the name of the book file: ");
    scanf("%s", filename);

    if (load_book(filename, &book)) {
        return 1;
    }

    display_book(&book);

    return 0;
}