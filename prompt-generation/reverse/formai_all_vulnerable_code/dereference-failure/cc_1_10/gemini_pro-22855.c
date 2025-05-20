//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    char *content;
} Book;

Book *read_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    char *buffer = malloc(size + 1);
    if (buffer == NULL) {
        return NULL;
    }

    fread(buffer, 1, size, fp);
    buffer[size] = '\0';

    char *title = strtok(buffer, "\n");
    char *author = strtok(NULL, "\n");
    char *content = strtok(NULL, "\0");

    Book *book = malloc(sizeof(Book));
    if (book == NULL) {
        free(buffer);
        return NULL;
    }

    book->title = strdup(title);
    book->author = strdup(author);
    book->content = strdup(content);

    free(buffer);
    fclose(fp);

    return book;
}

void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->content);
    free(book);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Book *book = read_book(argv[1]);
    if (book == NULL) {
        printf("Error: could not read book.\n");
        return 1;
    }

    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("\n%s\n", book->content);

    free_book(book);

    return 0;
}