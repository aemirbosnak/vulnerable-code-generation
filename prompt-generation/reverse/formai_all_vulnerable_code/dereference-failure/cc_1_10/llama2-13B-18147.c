//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define BUFFER_SIZE 4096
#define CHAPTER_SIZE 1024

typedef struct {
    char *name;
    char *content;
} chapter_t;

typedef struct {
    char *title;
    chapter_t *chapters;
    int chapter_count;
} book_t;

book_t *load_book(const char *file_path) {
    book_t *book = malloc(sizeof(book_t));
    book->title = strdup(file_path);
    book->chapter_count = 0;

    FILE *file = fopen(file_path, "r");
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

        if (strcmp(token, "CHAPTER") == 0) {
            chapter_t *chapter = malloc(sizeof(chapter_t));
            chapter->name = strdup(token);
            chapter->content = NULL;
            book->chapters = realloc(book->chapters, (book->chapter_count + 1) * sizeof(chapter_t));
            book->chapters[book->chapter_count] = *chapter;
            book->chapter_count++;
        } else {
            if (book->chapters[book->chapter_count - 1].content == NULL) {
                book->chapters[book->chapter_count - 1].content = malloc(CHAPTER_SIZE);
            }
            strcpy(book->chapters[book->chapter_count - 1].content, token);
        }
    }

    fclose(file);
    return book;
}

void display_book(book_t *book) {
    printf("Book Title: %s\n", book->title);
    for (int i = 0; i < book->chapter_count; i++) {
        printf("Chapter %d: %s\n", i + 1, book->chapters[i].name);
        printf("--------------------------------------------------------\n");
        printf("%s\n", book->chapters[i].content);
    }
}

int main() {
    book_t *book = load_book("example.txt");
    display_book(book);
    free(book);
    return 0;
}