//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define MAX_BOOK_SIZE 1024 * 1024 * 10
#define MAX_PAGE_SIZE 64 * 1024

typedef struct {
    char *name;
    char *author;
    char *publisher;
    int pages;
    int size;
} Book;

typedef struct {
    char *title;
    char *chapter;
    char *page;
} Page;

Book current_book;
Page current_page;

void load_book(const char *filename) {
    int fd;
    struct stat st;
    char *buffer;
    size_t buffer_size = MAX_PAGE_SIZE;

    fd = open(filename, O_RDONLY, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    fstat(fd, &st);
    current_book.size = st.st_size;

    buffer = malloc(buffer_size);
    read(fd, buffer, buffer_size);

    current_book.name = strtok(buffer, "\n");
    current_book.author = strtok(NULL, "\n");
    current_book.publisher = strtok(NULL, "\n");
    current_book.pages = strtol(strtok(NULL, "\n"), NULL, 10);

    free(buffer);
    close(fd);
}

void load_page(const char *filename) {
    int fd;
    struct stat st;
    char *buffer;
    size_t buffer_size = MAX_PAGE_SIZE;

    fd = open(filename, O_RDONLY, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    fstat(fd, &st);
    current_page.page = strtok(buffer, "\n");
    current_page.chapter = strtok(NULL, "\n");
    current_page.title = strtok(NULL, "\n");

    free(buffer);
    close(fd);
}

void display_book() {
    printf("Current book:\n");
    printf("Name: %s\n", current_book.name);
    printf("Author: %s\n", current_book.author);
    printf("Publisher: %s\n", current_book.publisher);
    printf("Pages: %d\n", current_book.pages);
}

void display_page() {
    printf("Current page:\n");
    printf("Title: %s\n", current_page.title);
    printf("Chapter: %s\n", current_page.chapter);
    printf("Page: %s\n", current_page.page);
}

int main() {
    char *book_filename = "example_book.txt";
    char *page_filename = "example_page.txt";

    load_book(book_filename);
    load_page(page_filename);

    display_book();
    display_page();

    return 0;
}