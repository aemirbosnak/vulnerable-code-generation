//FormAI DATASET v1.0 Category: Ebook reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EBOOK_TITLE_LENGTH 50
#define MAX_EBOOK_PAGES 1000
#define MAX_EBOOKS_IN_LIBRARY 100

typedef struct {
    char title[MAX_EBOOK_TITLE_LENGTH];
    int num_pages;
    int* pages;
} Ebook;

typedef struct {
    Ebook library[MAX_EBOOKS_IN_LIBRARY];
    int num_ebooks;
} EbookLibrary;

void print_ebook(Ebook* book) {
    printf("Title: %s\n", book->title);
    printf("Number of Pages: %d\n", book->num_pages);
    printf("Table of Contents:\n");
    for (int i = 0; i < book->num_pages; i++) {
        printf("%d\n", book->pages[i]);
    }
}

void add_ebook_to_library(EbookLibrary* library, Ebook* book) {
    library->library[library->num_ebooks] = *book;
    library->num_ebooks++;
}

Ebook* create_ebook(char* title, int num_pages) {
    Ebook* book = (Ebook*)malloc(sizeof(Ebook));
    strcpy(book->title, title);
    book->num_pages = num_pages;
    book->pages = (int*)malloc(sizeof(int) * num_pages);
    for (int i = 0; i < num_pages; i++) {
        book->pages[i] = i + 1;
    }
    return book;
}

int main() {
    EbookLibrary library;
    library.num_ebooks = 0;

    Ebook* ebook1 = create_ebook("The Catcher in the Rye", 277);
    add_ebook_to_library(&library, ebook1);

    Ebook* ebook2 = create_ebook("To Kill a Mockingbird", 324);
    add_ebook_to_library(&library, ebook2);

    printf("Number of ebooks in library: %d\n", library.num_ebooks);

    print_ebook(&library.library[0]);
    print_ebook(&library.library[1]);

    return 0;
}