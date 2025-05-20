//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

#define BUFFER_SIZE 4096
#define MAX_FILE_SIZE 1073741824

struct eBook {
    char *filename;
    char *title;
    char *author;
    int pageCount;
    char *text;
};

struct eBook *loadBook(const char *filename) {
    struct eBook *book = malloc(sizeof(struct eBook));
    book->filename = strdup(filename);
    book->title = strdup("No title");
    book->author = strdup("No author");
    book->pageCount = 0;
    book->text = NULL;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead = fread(buffer, 1, BUFFER_SIZE, file);
    while (bytesRead > 0) {
        book->text = realloc(book->text, book->pageCount * BUFFER_SIZE);
        memcpy(book->text + book->pageCount * BUFFER_SIZE, buffer, bytesRead);
        book->pageCount++;
        bytesRead = fread(buffer, 1, BUFFER_SIZE, file);
    }

    fclose(file);
    return book;
}

void displayBook(struct eBook *book) {
    printf("Title: %s\nAuthor: %s\nPage Count: %d\nText:\n", book->title, book->author, book->pageCount);
    for (int i = 0; i < book->pageCount; i++) {
        printf("%d: %s\n", i + 1, book->text + (i * BUFFER_SIZE));
    }
}

int main() {
    struct eBook *book = loadBook("example.txt");
    if (book == NULL) {
        printf("Error loading book\n");
        return 1;
    }

    displayBook(book);

    munmap(book->text, book->pageCount * BUFFER_SIZE);
    free(book->text);
    free(book->filename);
    free(book->title);
    free(book->author);
    free(book);

    return 0;
}