//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int page;
    char *text;
} BookPage;

typedef struct {
    char *title;
    int num_pages;
    BookPage *pages;
} Book;

Book *create_book(char *title, int num_pages) {
    Book *book = (Book *)malloc(sizeof(Book));
    book->title = (char *)malloc(strlen(title) + 1);
    strcpy(book->title, title);
    book->num_pages = num_pages;
    book->pages = (BookPage *)malloc(sizeof(BookPage) * num_pages);
    for (int i = 0; i < num_pages; i++) {
        book->pages[i].page = i + 1;
        book->pages[i].text = (char *)malloc(1024);
        sprintf(book->pages[i].text, "Page %d", i + 1);
    }
    return book;
}

void free_book(Book *book) {
    free(book->title);
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i].text);
    }
    free(book->pages);
    free(book);
}

void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    for (int i = 0; i < book->num_pages; i++) {
        printf("Page %d:\n%s\n", book->pages[i].page, book->pages[i].text);
    }
}

int main() {
    Book *book = create_book("My Book", 10);
    print_book(book);
    free_book(book);
    return 0;
}