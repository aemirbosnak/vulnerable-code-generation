//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    int num_pages;
    char **pages;
} Book;

Book *read_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    Book *book = malloc(sizeof(Book));
    if (book == NULL) {
        fclose(fp);
        return NULL;
    }

    char line[1024];
    while (fgets(line, 1024, fp) != NULL) {
        if (line[0] == '#') {
            continue;
        }

        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        if (strcmp(key, "title") == 0) {
            book->title = strdup(value);
        } else if (strcmp(key, "author") == 0) {
            book->author = strdup(value);
        } else if (strcmp(key, "num_pages") == 0) {
            book->num_pages = atoi(value);
        } else if (strcmp(key, "pages") == 0) {
            book->pages = malloc(book->num_pages * sizeof(char *));
            for (int i = 0; i < book->num_pages; i++) {
                fgets(line, 1024, fp);
                book->pages[i] = strdup(line);
            }
        }
    }

    fclose(fp);

    return book;
}

void free_book(Book *book) {
    free(book->title);
    free(book->author);
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i]);
    }
    free(book->pages);
    free(book);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Book *book = read_book(argv[1]);
    if (book == NULL) {
        printf("Error: could not read book '%s'\n", argv[1]);
        return 1;
    }

    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);

    for (int i = 0; i < book->num_pages; i++) {
        printf("Page %d:\n", i + 1);
        printf("%s\n", book->pages[i]);
    }

    free_book(book);

    return 0;
}