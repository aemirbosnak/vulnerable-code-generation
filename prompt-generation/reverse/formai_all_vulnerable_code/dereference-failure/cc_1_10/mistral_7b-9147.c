//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_CHARS 80

typedef struct {
    char title[MAX_CHARS];
    char* content;
    int lines;
} Book;

void load_book(Book* book, const char* filename) {
    FILE* file = fopen(filename, "r");
    char line[MAX_CHARS];
    int i = 0;

    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    strcpy(book->title, filename);
    book->content = malloc(MAX_LINES * MAX_CHARS);
    book->lines = 0;

    while (fgets(line, MAX_CHARS, file)) {
        strcpy(book->content + i * MAX_CHARS, line);
        i++;
        book->lines++;
    }

    fclose(file);
}

void print_book(const Book* book) {
    printf("\n%s\n", book->title);
    int i;

    for (i = 0; i < book->lines; i++) {
        printf("%s", book->content + i * MAX_CHARS);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ebook filename>\n", argv[0]);
        exit(1);
    }

    Book book;
    load_book(&book, argv[1]);
    print_book(&book);

    free(book.content);
    return 0;
}