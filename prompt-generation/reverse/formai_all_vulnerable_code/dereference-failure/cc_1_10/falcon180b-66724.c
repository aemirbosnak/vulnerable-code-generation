//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000 // Maximum length of a line in the book
#define MAX_BOOK_SIZE 1000000 // Maximum size of the book in bytes

typedef struct {
    char *title;
    char *author;
    char *content;
    int size;
} Book;

int read_book(FILE *file, Book *book) {
    char line[MAX_LINE_LENGTH];
    char *content = NULL;
    int size = 0;

    book->title = NULL;
    book->author = NULL;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        size++;
        content = realloc(content, size * sizeof(char));
        strcat(content, line);
    }

    book->content = content;
    book->size = size;

    return 0;
}

void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Content:\n%s", book->content);
}

int main() {
    FILE *file;
    Book book;

    file = fopen("example_book.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    read_book(file, &book);
    print_book(&book);

    fclose(file);
    return 0;
}