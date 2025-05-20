//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BOOK_SIZE 1024 * 1024 * 50
#define MAX_CHAPTERS 100
#define MAX_PAGES 100

typedef struct {
    char *title;
    char *author;
    char *description;
    off_t size;
    off_t chapter_size[MAX_CHAPTERS];
    char *pages[MAX_PAGES];
} Book;

Book *load_book(const char *path) {
    Book *book = malloc(sizeof(Book));
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return NULL;
    }

    book->title = malloc(100);
    book->author = malloc(100);
    book->description = malloc(100);

    fscanf(file, "%s %s %s", book->title, book->author, book->description);

    book->size = ftell(file);
    rewind(file);

    book->chapter_size[0] = ftell(file);
    book->pages[0] = malloc(book->chapter_size[0]);
    fread(book->pages[0], 1, book->chapter_size[0], file);

    for (int i = 1; i < MAX_CHAPTERS; i++) {
        book->chapter_size[i] = ftell(file);
        book->pages[i] = malloc(book->chapter_size[i]);
        fread(book->pages[i], 1, book->chapter_size[i], file);
    }

    fclose(file);

    return book;
}

void display_book(Book *book) {
    printf("Book Title: %s\n", book->title);
    printf("Book Author: %s\n", book->author);
    printf("Book Description: %s\n", book->description);

    for (int i = 0; i < MAX_CHAPTERS; i++) {
        printf("Chapter %d: %s\n", i + 1, book->pages[i]);
    }
}

int main() {
    Book *book = load_book("example_book.txt");
    if (book == NULL) {
        perror("Failed to load book");
        return 1;
    }

    display_book(book);

    for (int i = 0; i < MAX_PAGES; i++) {
        free(book->pages[i]);
    }

    free(book->title);
    free(book->author);
    free(book->description);

    return 0;
}