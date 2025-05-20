//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOK_SIZE 1000000 // Maximum size of the book (in characters)
#define MAX_LINE_SIZE 1000 // Maximum size of a line (in characters)

typedef struct {
    char *title;
    char *author;
    char *content;
    int content_size;
} Book;

void read_book(Book *book, FILE *fp) {
    char line[MAX_LINE_SIZE];
    int content_size = 0;

    fseek(fp, 0, SEEK_SET);
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        content_size += strlen(line);
        if (content_size > MAX_BOOK_SIZE) {
            fprintf(stderr, "Book is too large!\n");
            exit(1);
        }
        book->content = realloc(book->content, content_size + 1);
        strcat(book->content, line);
    }

    book->content_size = content_size;
}

void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Content:\n%s", book->content);
}

int main() {
    Book book;
    FILE *fp;

    fp = fopen("book.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open book file!\n");
        exit(1);
    }

    read_book(&book, fp);
    fclose(fp);

    print_book(&book);

    free(book.title);
    free(book.author);
    free(book.content);

    return 0;
}