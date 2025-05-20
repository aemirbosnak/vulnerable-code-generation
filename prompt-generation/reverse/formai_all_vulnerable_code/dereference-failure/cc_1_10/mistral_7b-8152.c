//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_BOOK_SIZE 100000
#define BUFFER_SIZE 1024

typedef struct {
    char title[100];
    char author[100];
    char **pages;
    int num_pages;
} Book;

void read_file_into_buffer(int file_desc, char *buffer) {
    int bytes_read = 0;
    while ((bytes_read = read(file_desc, buffer, BUFFER_SIZE)) > 0) {
        buffer += bytes_read;
    }
}

void load_book(Book *book, char *filename) {
    int file_desc = open(filename, O_RDONLY);
    if (file_desc < 0) {
        perror("Error opening file");
        return;
    }

    char buffer[BUFFER_SIZE];
    read_file_into_buffer(file_desc, buffer);

    sscanf(buffer, "%s %s", book->title, book->author);
    book->num_pages = 0;

    char *token = strtok(buffer, "\n");
    while (token != NULL) {
        if (book->num_pages >= MAX_BOOK_SIZE / sizeof(char *)) {
            printf("Error: book too large\n");
            close(file_desc);
            return;
        }
        book->pages[book->num_pages] = strdup(token);
        book->num_pages++;

        token = strtok(NULL, "\n");
    }

    close(file_desc);
}

void display_book(Book book) {
    printf("\n%s by %s\n", book.title, book.author);
    for (int i = 0; i < book.num_pages; i++) {
        printf("\nPage %d: %s\n", i + 1, book.pages[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <book.txt>\n", argv[0]);
        return 1;
    }

    Book my_book;
    load_book(&my_book, argv[1]);
    display_book(my_book);

    for (int i = 0; i < my_book.num_pages; i++) {
        free(my_book.pages[i]);
    }
    free(my_book.pages);

    return 0;
}