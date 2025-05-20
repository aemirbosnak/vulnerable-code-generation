//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 100

typedef struct {
    int page_number;
    char title[100];
    char *content;
} Book;

void read_file(FILE *file, Book *book) {
    char line[MAX_LINE_LENGTH];
    char *token;
    int page_number = 1;

    fgets(book->title, sizeof(book->title), file);
    book->title[strcspn(book->title, "\n")] = '\0';

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Page: ") != NULL) {
            token = strtok(line, ":");
            token = strtok(NULL, " ");
            page_number = atoi(token);
            book->page_number = page_number;
        } else if (strstr(line, "Chapter: ") != NULL) {
            // Handle chapters here
        } else {
            size_t len = strlen(book->content) + strlen(line) + 1;
            book->content = realloc(book->content, len);
            strcat(book->content, line);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    Book book;

    if (argc != 2) {
        printf("Usage: %s <ebook_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    read_file(file, &book);
    fclose(file);

    printf("Title: %s\n", book.title);
    printf("Page Number: %d\n", book.page_number);
    printf("Content:\n%s\n", book.content);

    free(book.content);
    return 0;
}