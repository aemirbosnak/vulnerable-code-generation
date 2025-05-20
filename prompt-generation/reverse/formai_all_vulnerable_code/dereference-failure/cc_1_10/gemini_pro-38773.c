//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *text;
    int len;
} Book;

Book *load_book(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    int len = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *text = malloc(len + 1);
    if (text == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fread(text, 1, len, fp);
    text[len] = '\0';

    fclose(fp);

    Book *book = malloc(sizeof(Book));
    if (book == NULL) {
        perror("malloc");
        free(text);
        return NULL;
    }

    book->name = strdup(filename);
    book->text = text;
    book->len = len;

    return book;
}

void free_book(Book *book) {
    free(book->name);
    free(book->text);
    free(book);
}

void print_book(Book *book) {
    printf("%s:\n", book->name);
    printf("%s\n", book->text);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Book *book = load_book(argv[1]);
    if (book == NULL) {
        return EXIT_FAILURE;
    }

    print_book(book);

    free_book(book);

    return EXIT_SUCCESS;
}