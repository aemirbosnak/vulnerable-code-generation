//FormAI DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

struct page {
    char text[500];
    struct page *next;
};

struct book {
    char title[100];
    struct page *first_page;
    struct page *current_page;
};

struct book* create_book(char* title, char* text) {
    struct book *new_book = (struct book *) malloc(sizeof(struct book));
    struct page *new_page = (struct page *) malloc(sizeof(struct page));
    strcpy(new_book->title, title);
    strcpy(new_page->text, text);
    new_page->next = NULL;
    new_book->first_page = new_page;
    new_book->current_page = new_page;
    return new_book;
}

void add_page(struct book *book, char *text) {
    struct page *new_page = (struct page *) malloc(sizeof(struct page));
    strcpy(new_page->text, text);
    new_page->next = NULL;
    book->current_page->next = new_page;
    book->current_page = new_page;
}

void print_page(struct page *page) {
    printf("%s\n\n", page->text);
}

void display_book(struct book *book) {
    struct page *page = book->first_page;
    while (page != NULL) {
        print_page(page);
        page = page->next;
    }
}

int main() {
    struct book *new_book = create_book("The Adventures of Sir Lancelot", "Once upon a time in a faraway land...");
    add_page(new_book, "...Sir Lancelot encountered a dragon. He bravely fought with his sword...");
    add_page(new_book, "...and finally defeated the dragon. The end.");
    display_book(new_book);
    return 0;
}