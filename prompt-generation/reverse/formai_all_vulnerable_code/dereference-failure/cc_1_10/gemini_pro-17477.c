//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    int num_pages;
    char *text;
} Book;

Book *read_book(const char *filename) {
    FILE *fp;
    Book *book;
    char *buffer;
    size_t size;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    book = malloc(sizeof(Book));
    if (book == NULL) {
        perror("Error allocating memory for book");
        fclose(fp);
        return NULL;
    }

    size = 1024;
    buffer = malloc(size);
    if (buffer == NULL) {
        perror("Error allocating memory for buffer");
        fclose(fp);
        free(book);
        return NULL;
    }

    while (!feof(fp)) {
        ssize_t bytes_read = fread(buffer, 1, size, fp);
        if (bytes_read < 0) {
            perror("Error reading file");
            fclose(fp);
            free(book);
            free(buffer);
            return NULL;
        }

        if (bytes_read == size) {
            size *= 2;
            buffer = realloc(buffer, size);
            if (buffer == NULL) {
                perror("Error reallocating memory for buffer");
                fclose(fp);
                free(book);
                free(buffer);
                return NULL;
            }
        }

        buffer[bytes_read] = '\0';
        strcat(book->text, buffer);
    }

    fclose(fp);
    free(buffer);

    return book;
}

void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Text:\n%s\n", book->text);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Book *book = read_book(argv[1]);
    if (book == NULL) {
        return EXIT_FAILURE;
    }

    print_book(book);

    free(book->title);
    free(book->author);
    free(book->text);
    free(book);

    return EXIT_SUCCESS;
}