//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    char *text;
    int num_pages;
} Book;

Book *read_book(const char *filename) {
    FILE *fp;
    Book *book;
    char *buf;
    int len;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }

    // Read the title
    len = getline(&buf, &len, fp);
    buf[len - 1] = '\0';  // Remove the newline character
    book->title = strdup(buf);

    // Read the author
    len = getline(&buf, &len, fp);
    buf[len - 1] = '\0';  // Remove the newline character
    book->author = strdup(buf);

    // Read the text
    len = getline(&buf, &len, fp);
    buf[len - 1] = '\0';  // Remove the newline character
    book->text = strdup(buf);

    // Read the number of pages
    fscanf(fp, "%d", &book->num_pages);

    fclose(fp);

    return book;
}

void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Text: %s\n", book->text);
    printf("Number of pages: %d\n", book->num_pages);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Book *book = read_book(argv[1]);
    if (book == NULL) {
        return 1;
    }

    print_book(book);

    free(book->title);
    free(book->author);
    free(book->text);
    free(book);

    return 0;
}