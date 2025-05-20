//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    int num_pages;
    char *text;
} Book;

Book *load_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    Book *book = malloc(sizeof(Book));
    fscanf(fp, "%[^\n]\n", book->title);
    fscanf(fp, "%[^\n]\n", book->author);
    fscanf(fp, "%d\n", &book->num_pages);

    book->text = malloc(book->num_pages * 1024);
    fread(book->text, 1024, book->num_pages, fp);

    fclose(fp);

    return book;
}

void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->text);
    free(book);
}

void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Text:\n%s\n", book->text);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Book *book = load_book(argv[1]);
    if (book == NULL) {
        printf("Error loading book.\n");
        return 1;
    }

    print_book(book);

    free_book(book);

    return 0;
}