//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_LINE_LENGTH 100
#define MIN_PAUSE 100
#define MAX_PAUSE 500

typedef struct {
    char title[MAX_LINE_LENGTH];
    char* content;
    size_t content_length;
} Book;

void print_line(const char* line) {
    printf("%s\n", line);
    fflush(stdout);
    usleep(rand() % (MAX_PAUSE - MIN_PAUSE) + MIN_PAUSE);
}

void read_file(const char* path, Book* book) {
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fgets(book->title, MAX_LINE_LENGTH, file);
    book->title[strcspn(book->title, "\n")] = '\0';

    fseek(file, 0, SEEK_END);
    book->content_length = ftell(file);
    book->content = malloc(book->content_length + 1);
    fseek(file, 0, SEEK_SET);

    size_t bytes_read = fread(book->content, 1, book->content_length, file);
    if (bytes_read != book->content_length) {
        perror("Error reading file");
        free(book->content);
        return;
    }

    book->content[book->content_length] = '\0';
    fclose(file);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <path_to_ebook>\n", argv[0]);
        return 1;
    }

    Book book;
    read_file(argv[1], &book);

    printf("Title: %s\n", book.title);

    char* line = strtok(book.content, "\n");
    while (line != NULL) {
        print_line(line);
        line = strtok(NULL, "\n");
    }

    free(book.content);
    return 0;
}