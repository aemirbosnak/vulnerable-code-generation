//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char *content;
    size_t content_size;
} eBook;

void load_eBook(const char *filename, eBook *book) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open the file");
        exit(EXIT_FAILURE);
    }

    fgets(book->title, MAX_TITLE_LENGTH, file);
    fgets(book->author, MAX_AUTHOR_LENGTH, file);

    fseek(file, 0, SEEK_END);
    book->content_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    book->content = malloc(book->content_size + 1);
    if (!book->content) {
        perror("Failed to allocate memory");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fread(book->content, 1, book->content_size, file);
    book->content[book->content_size] = '\0'; // Null-terminate the string

    fclose(file);
}

void display_eBook(eBook *book) {
    printf("Title: %s", book->title);
    printf("Author: %s", book->author);
    printf("Content:\n%s\n", book->content);
}

void free_eBook(eBook *book) {
    free(book->content);
}

int main() {
    eBook myBook;
    const char *filename = "sample_ebook.txt";

    load_eBook(filename, &myBook);
    display_eBook(&myBook);
    free_eBook(&myBook);

    return 0;
}