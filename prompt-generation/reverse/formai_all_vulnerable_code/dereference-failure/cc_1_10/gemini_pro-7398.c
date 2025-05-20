//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    char *content;
} Book;

Book *load_book(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    Book *book = malloc(sizeof(Book));
    if (book == NULL) {
        fclose(fp);
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Read the title
    read = getline(&line, &len, fp);
    if (read == -1) {
        free(book);
        fclose(fp);
        return NULL;
    }
    line[read - 1] = '\0';
    book->title = strdup(line);

    // Read the author
    read = getline(&line, &len, fp);
    if (read == -1) {
        free(book->title);
        free(book);
        fclose(fp);
        return NULL;
    }
    line[read - 1] = '\0';
    book->author = strdup(line);

    // Read the content
    char *content = NULL;
    size_t content_len = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        content = realloc(content, content_len + read + 1);
        memcpy(content + content_len, line, read);
        content_len += read;
    }
    content[content_len] = '\0';
    book->content = content;

    fclose(fp);
    return book;
}

void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->content);
    free(book);
}

void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Content:\n%s", book->content);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Book *book = load_book(argv[1]);
    if (book == NULL) {
        fprintf(stderr, "Error loading book: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    print_book(book);
    free_book(book);

    return EXIT_SUCCESS;
}