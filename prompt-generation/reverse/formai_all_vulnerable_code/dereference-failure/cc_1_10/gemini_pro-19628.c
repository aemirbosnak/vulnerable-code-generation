//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    int num_pages;
    char *text;
} book;

void read_book(book *b, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    // Read the title
    char line[1024];
    fgets(line, sizeof(line), fp);
    b->title = strdup(line);

    // Read the author
    fgets(line, sizeof(line), fp);
    b->author = strdup(line);

    // Read the number of pages
    fgets(line, sizeof(line), fp);
    b->num_pages = atoi(line);

    // Read the text
    b->text = malloc(b->num_pages * sizeof(char));
    fread(b->text, sizeof(char), b->num_pages, fp);

    fclose(fp);
}

void print_book(book *b) {
    printf("Title: %s\n", b->title);
    printf("Author: %s\n", b->author);
    printf("Number of pages: %d\n", b->num_pages);
    printf("Text:\n%s", b->text);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    book b;
    read_book(&b, argv[1]);
    print_book(&b);

    return 0;
}