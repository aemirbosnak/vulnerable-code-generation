//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <utime.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_SIZE 100000

typedef struct {
    char *filename;
    char *text;
    size_t len;
    size_t pos;
} Book;

Book current_book;

void init_book(const char *filename) {
    current_book.filename = strdup(filename);
    current_book.text = malloc(MAX_FILE_SIZE);
    current_book.len = 0;
    current_book.pos = 0;
}

void read_book(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }
    size_t len = read(fd, current_book.text, MAX_FILE_SIZE);
    if (len == -1) {
        perror("Error reading file");
        close(fd);
        return;
    }
    current_book.len = len;
    close(fd);
}

void next_page() {
    if (current_book.pos == current_book.len) {
        printf("End of book\n");
        return;
    }
    current_book.pos++;
}

void display_page() {
    if (current_book.pos > 0 && current_book.pos < current_book.len) {
        printf("%.*s", (int)current_book.pos, current_book.text + current_book.pos);
    } else {
        printf("Page not found\n");
    }
}

int main() {
    init_book("example.txt");
    read_book("example.txt");
    while (1) {
        next_page();
        display_page();
    }
    return 0;
}