//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    int num_pages;
    char **pages;
} Book;

Book *create_book(char *title, char *author, int num_pages) {
    Book *book = malloc(sizeof(Book));
    book->title = malloc(strlen(title) + 1);
    strcpy(book->title, title);
    book->author = malloc(strlen(author) + 1);
    strcpy(book->author, author);
    book->num_pages = num_pages;
    book->pages = malloc(sizeof(char *) * num_pages);
    for (int i = 0; i < num_pages; i++) {
        book->pages[i] = NULL;
    }
    return book;
}

void free_book(Book *book) {
    free(book->title);
    free(book->author);
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i]);
    }
    free(book->pages);
    free(book);
}

void load_book(Book *book, FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    getline(&line, &len, fp);
    book->title = malloc(strlen(line) + 1);
    strcpy(book->title, line);

    getline(&line, &len, fp);
    book->author = malloc(strlen(line) + 1);
    strcpy(book->author, line);

    fscanf(fp, "%d\n", &book->num_pages);

    for (int i = 0; i < book->num_pages; i++) {
        getline(&line, &len, fp);
        book->pages[i] = malloc(strlen(line) + 1);
        strcpy(book->pages[i], line);
    }

    free(line);
}

void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    for (int i = 0; i < book->num_pages; i++) {
        printf("Page %d:\n%s\n", i + 1, book->pages[i]);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ebook file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    Book *book = create_book("", "", 0);
    load_book(book, fp);
    fclose(fp);

    print_book(book);
    free_book(book);

    return 0;
}