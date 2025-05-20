//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    char *content;
    int num_pages;
} Book;

Book *read_book(FILE *fp) {
    Book *book = malloc(sizeof(Book));
    char line[1024];

    // Read the title
    fgets(line, 1024, fp);
    book->title = strdup(line);

    // Read the author
    fgets(line, 1024, fp);
    book->author = strdup(line);

    // Read the content
    book->content = malloc(1024);
    int num_pages = 0;
    while (fgets(line, 1024, fp)) {
        strcat(book->content, line);
        num_pages++;
    }

    book->num_pages = num_pages;

    return book;
}

void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Content: %s\n", book->content);
    printf("Number of pages: %d\n", book->num_pages);
}

int main() {
    FILE *fp = fopen("book.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    Book *book = read_book(fp);
    fclose(fp);

    print_book(book);

    return 0;
}