//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct Book {
    char *title;
    char *author;
    char *content;
    int pages;
} Book;

void read_book(Book *book) {
    int fd;
    char buffer[4096];
    int bytes_read;

    fd = open(book->title, O_RDONLY);
    if (fd < 0) {
        printf("Error: Could not open '%s'\n", book->title);
        return;
    }

    printf("\n=========================\n");
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    printf("=========================\n\n");

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        printf("%s", buffer);
        fflush(stdout);
    }

    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <title.txt> <author.txt>\n", argv[0]);
        return 1;
    }

    Book book;
    book.title = malloc(strlen(argv[1]) + 1);
    strcpy(book.title, argv[1]);
    book.author = malloc(strlen(argv[2]) + 1);
    strcpy(book.author, argv[2]);

    FILE *title_file = fopen(argv[1], "r");
    if (title_file == NULL) {
        printf("Error: Could not open title file '%s'\n", argv[1]);
        free(book.title);
        free(book.author);
        return 1;
    }

    fscanf(title_file, "%d", &book.pages);
    fclose(title_file);

    FILE *author_file = fopen(argv[2], "r");
    if (author_file == NULL) {
        printf("Error: Could not open author file '%s'\n", argv[2]);
        free(book.title);
        free(book.author);
        return 1;
    }

    fscanf(author_file, "%s%*s", book.title);
    fscanf(author_file, "%s", book.author);
    fclose(author_file);

    read_book(&book);

    free(book.title);
    free(book.author);

    return 0;
}