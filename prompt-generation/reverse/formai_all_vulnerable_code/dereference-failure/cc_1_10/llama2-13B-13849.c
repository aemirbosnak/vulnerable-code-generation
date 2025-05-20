//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096
#define BOOK_SIZE 1024 * 1024 * 10

typedef struct {
    char *name;
    char *author;
    char *description;
    char *content;
} Book;

typedef struct {
    Book books[10];
    int current_book;
} Library;

void load_book(Library *library, const char *path) {
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("Error opening book file");
        return;
    }

    struct stat stat;
    fstat(fd, &stat);

    char *content = mmap(NULL, stat.st_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (content == MAP_FAILED) {
        perror("Error mmapping book content");
        close(fd);
        return;
    }

    Book book;
    book.name = (char *)content;
    content += strlen(content) + 1;
    book.author = content;
    content += strlen(content) + 1;
    book.description = content;
    content += strlen(content) + 1;
    book.content = content;

    library->books[library->current_book] = book;
    library->current_book++;

    munmap(content, stat.st_size);
    close(fd);
}

void display_book(Library *library) {
    printf("Current book: %s by %s\n", library->books[library->current_book - 1].name, library->books[library->current_book - 1].author);
    printf("Description: %s\n", library->books[library->current_book - 1].description);
    printf("Content:\n%s\n", library->books[library->current_book - 1].content);
}

int main() {
    Library library;
    library.current_book = 0;

    load_book(&library, "book1.txt");
    load_book(&library, "book2.txt");
    load_book(&library, "book3.txt");

    display_book(&library);

    return 0;
}