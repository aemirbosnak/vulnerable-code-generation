//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct _book {
    char *title;
    char *author;
    char *text;
    size_t size;
} book;

book *read_book(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *buffer = malloc(size + 1);
    if (buffer == NULL) {
        fclose(fp);
        return NULL;
    }

    fread(buffer, 1, size, fp);
    fclose(fp);

    buffer[size] = '\0';

    char *title = strtok(buffer, "\n");
    char *author = strtok(NULL, "\n");
    char *text = strtok(NULL, "\0");

    book *b = malloc(sizeof(book));
    if (b == NULL) {
        free(buffer);
        return NULL;
    }

    b->title = strdup(title);
    b->author = strdup(author);
    b->text = strdup(text);
    b->size = size;

    free(buffer);

    return b;
}

void print_book(const book *b) {
    printf("Title: %s\n", b->title);
    printf("Author: %s\n", b->author);
    printf("Text:\n%s\n", b->text);
}

void free_book(book *b) {
    free(b->title);
    free(b->author);
    free(b->text);
    free(b);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    book *b = read_book(argv[1]);
    if (b == NULL) {
        printf("Error: could not read book\n");
        return 1;
    }

    print_book(b);

    free_book(b);

    return 0;
}