//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

typedef struct {
    char *lines[MAX_LINES];
    int num_lines;
} ebook;

ebook *ebook_new() {
    ebook *book = malloc(sizeof(ebook));
    book->num_lines = 0;
    return book;
}

void ebook_free(ebook *book) {
    for (int i = 0; i < book->num_lines; i++) {
        free(book->lines[i]);
    }
    free(book);
}

int ebook_add_line(ebook *book, char *line) {
    if (book->num_lines >= MAX_LINES) {
        return -1;
    }
    book->lines[book->num_lines] = malloc(strlen(line) + 1);
    strcpy(book->lines[book->num_lines], line);
    book->num_lines++;
    return 0;
}

int ebook_load(ebook *book, FILE *fp) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        ebook_add_line(book, line);
    }
    return 0;
}

void ebook_print(ebook *book) {
    for (int i = 0; i < book->num_lines; i++) {
        printf("%s", book->lines[i]);
    }
}

int main() {
    ebook *book = ebook_new();
    ebook_load(book, stdin);
    ebook_print(book);
    ebook_free(book);
    return 0;
}