//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PAGE_SIZE 10000
#define PAGE_SIZE 100

typedef struct {
    char title[100];
    float *content;
    int pages;
} Book;

void readFile(const char *filename, Book *book) {
    FILE *file = fopen(filename, "r");
    char line[1024];
    int i = 0;

    fgets(book->title, 100, file);
    book->pages = ceil(strlen(fgets(line, 1024, file)) / (PAGE_SIZE + 1));
    book->content = (float *) malloc(book->pages * PAGE_SIZE * sizeof(float));

    for (i = 0; i < book->pages; i++) {
        fgets(line, 1024, file);
        sscanf(line, "%f", &book->content[i]);
    }

    fclose(file);
}

void displayPage(int page, Book book) {
    int start = page * PAGE_SIZE;
    int end = start + PAGE_SIZE;

    printf("\n------------------------\n");
    printf("Page %d\n", page + 1);
    printf("------------------------\n");

    for (int i = start; i < end && i < book.pages * PAGE_SIZE; i++) {
        printf("%.3f ", book.content[i]);
    }

    printf("\n");
}

void printBook(Book book) {
    printf("%s\n", book.title);
    int i = floor(sqrt(book.pages * 100.0));

    for (int page = 0; page < i * i && page < book.pages; page++) {
        displayPage(page / i + (page % i) / i, book);
    }

    free(book.content);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ebook.txt>\n", argv[0]);
        return -1;
    }

    Book book;
    readFile(argv[1], &book);
    printBook(book);

    return 0;
}