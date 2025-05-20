//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>

#define BUFFER_SIZE 4096
#define BOOK_SIZE 100000
#define CHAPTER_SIZE 100

typedef struct {
    char *name;
    char *content;
} chapter_t;

typedef struct {
    char *title;
    chapter_t chapters[10];
} book_t;

book_t *load_book(const char *file_name) {
    book_t *book = malloc(sizeof(book_t));
    book->title = strdup(file_name);
    FILE *file = fopen(file_name, "r");
    char line[BUFFER_SIZE];
    int i = 0;

    while (fgets(line, BUFFER_SIZE, file)) {
        if (i++ == 0) {
            book->title = strdup(line);
        } else if (strstr(line, "Chapter ") != NULL) {
            chapter_t *chapter = malloc(sizeof(chapter_t));
            chapter->name = strdup(line + 8);
            book->chapters[i - 1] = *chapter;
        }
    }

    fclose(file);
    return book;
}

void display_book(book_t *book) {
    printf("Book Title: %s\n", book->title);
    for (int i = 0; i < 10; i++) {
        printf("Chapter %d: %s\n", i + 1, book->chapters[i].name);
    }
}

void display_chapter(book_t *book, int chapter_number) {
    chapter_t *chapter = &book->chapters[chapter_number - 1];
    printf("Chapter %d: %s\n", chapter_number, chapter->name);
}

int main() {
    book_t *book = load_book("example_book.txt");
    display_book(book);
    display_chapter(book, 3);
    return 0;
}