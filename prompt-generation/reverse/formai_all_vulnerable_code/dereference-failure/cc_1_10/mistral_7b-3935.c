//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: Cryptic
#define _CRYPTIC_READER_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct {
    char title[128];
    char author[128];
    char *content;
    int length;
} book;

void _load_file_(char *filename, book *book) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        perror("Error getting file size");
        exit(1);
    }

    book->length = file_stat.st_size;
    book->content = (char *) malloc(book->length);

    ssize_t bytes_read = read(fd, book->content, book->length);
    if (bytes_read != book->length) {
        perror("Error reading file");
        exit(1);
    }

    close(fd);
}

void _print_header_(book *book) {
    printf("\n[+] %s by %s\n", book->title, book->author);
}

void _print_content_(book *book) {
    for (int i = 0; i < book->length; i++) {
        putchar(book->content[i]);
        if ((i + 1) % 40 == 0) putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("[!] Usage: %s <ebook_file>\n", argv[0]);
        exit(1);
    }

    book my_book;
    _load_file_(argv[1], &my_book);

    _print_header_(&my_book);
    _print_content_(&my_book);

    free(my_book.content);
    return 0;
}