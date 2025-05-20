//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *data;
    size_t size;
} Book;

Book *book_new(char *name, char *data, size_t size) {
    Book *book = malloc(sizeof(Book));
    book->name = strdup(name);
    book->data = malloc(size);
    memcpy(book->data, data, size);
    book->size = size;
    return book;
}

void book_free(Book *book) {
    free(book->name);
    free(book->data);
    free(book);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *data = malloc(size);
    fread(data, 1, size, fp);
    fclose(fp);

    Book *book = book_new(argv[1], data, size);

    char *start = book->data;
    char *end = book->data + book->size;

    while (start < end) {
        char *line = start;
        while (start < end && *start != '\n') start++;
        *start = '\0';
        printf("%s\n", line);
        start++;
    }

    book_free(book);

    return 0;
}