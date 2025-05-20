//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10000

typedef struct {
    char *text;
    int len;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Book;

Book *new_book() {
    Book *book = malloc(sizeof(Book));
    book->lines = malloc(MAX_LINES * sizeof(Line));
    book->num_lines = 0;
    return book;
}

void free_book(Book *book) {
    for (int i = 0; i < book->num_lines; i++) {
        free(book->lines[i].text);
    }
    free(book->lines);
    free(book);
}

void add_line(Book *book, char *text) {
    if (book->num_lines >= MAX_LINES) {
        printf("Error: Too many lines in book.\n");
        return;
    }

    book->lines[book->num_lines].text = strdup(text);
    book->lines[book->num_lines].len = strlen(text);
    book->num_lines++;
}

void print_book(Book *book) {
    for (int i = 0; i < book->num_lines; i++) {
        printf("%s\n", book->lines[i].text);
    }
}

int main() {
    Book *book = new_book();

    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, stdin) != -1) {
        add_line(book, line);
    }
    free(line);

    print_book(book);

    free_book(book);

    return 0;
}