//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    int num_pages;
    char **pages;
} Book;

Book *create_book(char *title, char *author, int num_pages) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->pages = malloc(sizeof(char *) * num_pages);
    for (int i = 0; i < num_pages; i++) {
        book->pages[i] = malloc(sizeof(char) * 1024);
    }
    return book;
}

void free_book(Book *book) {
    free(book->title);
    free(book->author);
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i]);
    }
    free(book->pages);
    free(book);
}

void read_book(Book *book) {
    for (int i = 0; i < book->num_pages; i++) {
        printf("%s\n", book->pages[i]);
    }
}

int main() {
    Book *book = create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 250);

    FILE *fp = fopen("hitchhikers_guide.txt", "r");
    if (fp == NULL) {
        perror("Unable to open file");
        return 1;
    }

    char line[1024];
    int page = 0;
    while (fgets(line, sizeof(line), fp)) {
        strcpy(book->pages[page], line);
        page++;
    }

    fclose(fp);

    read_book(book);

    return 0;
}