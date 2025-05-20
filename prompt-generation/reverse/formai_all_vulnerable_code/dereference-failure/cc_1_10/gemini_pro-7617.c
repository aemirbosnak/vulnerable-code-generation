//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *text;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Book;

Book *read_book(char *filename) {
    FILE *fp;
    char *line_buffer;
    int line_length;
    Book *book;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    line_buffer = malloc(MAX_LINE_LENGTH);
    if (line_buffer == NULL) {
        fclose(fp);
        return NULL;
    }

    book = malloc(sizeof(Book));
    if (book == NULL) {
        free(line_buffer);
        fclose(fp);
        return NULL;
    }

    book->lines = NULL;
    book->num_lines = 0;

    while (fgets(line_buffer, MAX_LINE_LENGTH, fp) != NULL) {
        line_length = strlen(line_buffer);
        if (line_length > 0) {
            book->lines = realloc(book->lines, (book->num_lines + 1) * sizeof(Line));
            if (book->lines == NULL) {
                free(line_buffer);
                fclose(fp);
                free(book);
                return NULL;
            }

            book->lines[book->num_lines].text = malloc(line_length + 1);
            if (book->lines[book->num_lines].text == NULL) {
                free(line_buffer);
                fclose(fp);
                free(book);
                free(book->lines);
                return NULL;
            }

            strcpy(book->lines[book->num_lines].text, line_buffer);
            book->lines[book->num_lines].length = line_length;
            book->num_lines++;
        }
    }

    free(line_buffer);
    fclose(fp);

    return book;
}

void free_book(Book *book) {
    int i;

    for (i = 0; i < book->num_lines; i++) {
        free(book->lines[i].text);
    }

    free(book->lines);
    free(book);
}

void print_book(Book *book) {
    int i;

    for (i = 0; i < book->num_lines; i++) {
        printf("%s", book->lines[i].text);
    }
}

int main(int argc, char **argv) {
    Book *book;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    book = read_book(argv[1]);
    if (book == NULL) {
        printf("Error: could not read book '%s'\n", argv[1]);
        return EXIT_FAILURE;
    }

    print_book(book);
    free_book(book);

    return EXIT_SUCCESS;
}