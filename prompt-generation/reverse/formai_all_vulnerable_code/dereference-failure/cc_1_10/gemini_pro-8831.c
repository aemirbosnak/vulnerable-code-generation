//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAGE_SIZE 1024

typedef struct {
    char *data;
    int size;
} Page;

typedef struct {
    Page *pages;
    int num_pages;
} Book;

Book *book_new(const char *filename) {
    FILE *fp;
    Book *book;
    char *data;
    int size;

    fp = fopen(filename, "r");
    if (!fp) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    data = malloc(size);
    if (!data) {
        fclose(fp);
        return NULL;
    }

    fread(data, 1, size, fp);
    fclose(fp);

    book = malloc(sizeof(Book));
    if (!book) {
        free(data);
        return NULL;
    }

    book->pages = malloc(sizeof(Page) * (size / MAX_PAGE_SIZE + 1));
    if (!book->pages) {
        free(data);
        free(book);
        return NULL;
    }

    for (int i = 0; i < size / MAX_PAGE_SIZE + 1; i++) {
        book->pages[i].data = data + i * MAX_PAGE_SIZE;
        book->pages[i].size = (i + 1) * MAX_PAGE_SIZE < size ? MAX_PAGE_SIZE : size % MAX_PAGE_SIZE;
    }

    book->num_pages = size / MAX_PAGE_SIZE + 1;

    return book;
}

void book_free(Book *book) {
    free(book->pages);
    free(book);
}

void book_page_turn(Book *book, int page) {
    if (page < 0 || page >= book->num_pages) {
        return;
    }

    printf("Page %d:\n", page + 1);
    fwrite(book->pages[page].data, 1, book->pages[page].size, stdout);
}

int main(int argc, char **argv) {
    Book *book;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    book = book_new(argv[1]);
    if (!book) {
        printf("Error: could not open book %s\n", argv[1]);
        return 1;
    }

    book_page_turn(book, 0);

    book_free(book);

    return 0;
}