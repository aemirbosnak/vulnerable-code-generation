//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define WORDS_PER_PAGE 20

typedef struct Page {
    char **words;
    int num_words;
} Page;

typedef struct Book {
    Page **pages;
    int num_pages;
} Book;

Book *create_book(int num_pages) {
    Book *book = malloc(sizeof(Book));
    book->pages = malloc(sizeof(Page *) * num_pages);
    book->num_pages = num_pages;

    for (int i = 0; i < num_pages; i++) {
        book->pages[i] = malloc(sizeof(Page));
        book->pages[i]->words = malloc(sizeof(char *) * WORDS_PER_PAGE);
        book->pages[i]->num_words = 0;
    }

    return book;
}

void add_word_to_book(Book *book, char *word) {
    int page_num = book->pages[0]->num_words / WORDS_PER_PAGE;
    Page *page = book->pages[page_num];

    page->words[page->num_words++] = word;
}

void print_book(Book *book) {
    for (int i = 0; i < book->num_pages; i++) {
        for (int j = 0; j < book->pages[i]->num_words; j++) {
            printf("%s ", book->pages[i]->words[j]);
        }

        printf("\n");
    }
}

int main() {
    Book *book = create_book(10);

    add_word_to_book(book, "Hello");
    add_word_to_book(book, "World");
    add_word_to_book(book, "Welcome");
    add_word_to_book(book, "To");
    add_word_to_book(book, "This");
    add_word_to_book(book, "Book");

    print_book(book);

    return 0;
}