//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *text;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Book;

Book *read_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    Book *book = malloc(sizeof(Book));
    book->lines = NULL;
    book->num_lines = 0;

    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fp) != -1) {
        Line *new_line = malloc(sizeof(Line));
        new_line->length = strlen(line);
        new_line->text = malloc(new_line->length + 1);
        strcpy(new_line->text, line);

        book->lines = realloc(book->lines, (book->num_lines + 1) * sizeof(Line));
        book->lines[book->num_lines] = *new_line;
        book->num_lines++;

        free(line);
        line = NULL;
        len = 0;
    }

    free(line);
    fclose(fp);

    return book;
}

void print_book(Book *book) {
    for (int i = 0; i < book->num_lines; i++) {
        printf("%s", book->lines[i].text);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Book *book = read_book(argv[1]);
    if (book == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    print_book(book);

    for (int i = 0; i < book->num_lines; i++) {
        free(book->lines[i].text);
    }
    free(book->lines);
    free(book);

    return 0;
}