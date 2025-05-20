//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

#define BUFFER_SIZE 4096
#define MAX_CHAPTERS 10
#define MAX_PAGES 50

typedef struct {
    char *name;
    char *content;
} chapter_t;

typedef struct {
    chapter_t chapters[MAX_CHAPTERS];
    int current_chapter;
    int current_page;
} book_t;

book_t *load_book(const char *path) {
    book_t *book = malloc(sizeof(book_t));
    book->current_chapter = 0;
    book->current_page = 0;

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return NULL;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        if (strcmp(buffer, "\n") == 0) {
            continue;
        }

        char *token = strtok(buffer, " ");
        if (token == NULL) {
            continue;
        }

        if (strcmp(token, "Chapter") == 0) {
            chapter_t *chapter = malloc(sizeof(chapter_t));
            chapter->name = token + 7;
            chapter->content = strtok(NULL, "\n");
            book->chapters[book->current_chapter++] = *chapter;
        } else if (strcmp(token, "Page") == 0) {
            book->current_page++;
        }
    }

    fclose(file);
    return book;
}

void display_book(book_t *book) {
    printf("Book: %s\n", book->chapters[book->current_chapter - 1].name);
    printf("Page: %d/%d\n", book->current_page, book->chapters[book->current_chapter - 1].content ? strcspn(book->chapters[book->current_chapter - 1].content, "\n") : 0);
}

void turn_page(book_t *book) {
    if (book->current_page >= book->chapters[book->current_chapter - 1].content ? strcspn(book->chapters[book->current_chapter - 1].content, "\n") : 0) {
        book->current_page = 0;
        book->current_chapter++;
    } else {
        book->current_page++;
    }

    display_book(book);
}

int main() {
    book_t *book = load_book("example.txt");
    if (book == NULL) {
        perror("Failed to load book");
        return 1;
    }

    while (1) {
        display_book(book);
        turn_page(book);
    }

    return 0;
}