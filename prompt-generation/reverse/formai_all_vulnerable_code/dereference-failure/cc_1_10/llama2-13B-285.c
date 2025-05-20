//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BOOK_SIZE 1000000
#define MAX_PAGES 100

typedef struct {
    char *name;
    char *author;
    char *publisher;
    int year;
} book_info_t;

typedef struct {
    char *title;
    char *content;
} page_t;

typedef struct {
    book_info_t book;
    int page_count;
    page_t *pages;
} ebook_t;

ebook_t *load_ebook(const char *filename) {
    ebook_t *eb = malloc(sizeof(ebook_t));
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }
    char magic[10];
    fread(magic, 1, 10, file);
    if (strcmp(magic, "eBook")) {
        fclose(file);
        return NULL;
    }
    int book_size = ftell(file);
    fseek(file, 0, SEEK_END);
    int page_count = (int) (book_size / 100);
    eb->book.name = malloc(strlen(filename) + 1);
    eb->book.author = malloc(strlen(filename) + 1);
    eb->book.publisher = malloc(strlen(filename) + 1);
    fgets(eb->book.name, 100, file);
    fgets(eb->book.author, 100, file);
    fgets(eb->book.publisher, 100, file);
    fclose(file);
    eb->page_count = page_count;
    eb->pages = malloc(page_count * sizeof(page_t));
    for (int i = 0; i < page_count; i++) {
        eb->pages[i].title = malloc(100);
        eb->pages[i].content = malloc(100);
        fgets(eb->pages[i].title, 100, file);
        fgets(eb->pages[i].content, 100, file);
    }
    return eb;
}

void display_ebook(ebook_t *eb) {
    for (int i = 0; i < eb->page_count; i++) {
        printf("%s\n", eb->pages[i].title);
        printf("%s\n", eb->pages[i].content);
    }
}

int main() {
    ebook_t *eb = load_ebook("example_ebook.txt");
    if (!eb) {
        perror("Failed to load eBook");
        return 1;
    }
    display_ebook(eb);
    free(eb->book.name);
    free(eb->book.author);
    free(eb->book.publisher);
    for (int i = 0; i < eb->page_count; i++) {
        free(eb->pages[i].title);
        free(eb->pages[i].content);
    }
    free(eb->pages);
    return 0;
}