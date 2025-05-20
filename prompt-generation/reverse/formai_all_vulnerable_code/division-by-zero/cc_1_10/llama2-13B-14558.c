//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PAGES 50
#define MAX_WORDS_PER_PAGE 20

typedef struct {
    char title[50];
    char author[50];
    int pages;
    int words_per_page;
} book_t;

book_t current_book = {
    "The Great Gatsby",
    "F. Scott Fitzgerald",
    50,
    20
};

int current_page = 0;
int current_word = 0;

void init_book(book_t *book) {
    strcpy(book->title, "Untitled");
    strcpy(book->author, "Unknown");
    book->pages = 0;
    book->words_per_page = 0;
}

void turn_page(book_t *book) {
    if (current_page < book->pages) {
        current_page++;
        current_word = 0;
    }
}

void read_word(book_t *book) {
    if (current_word < book->words_per_page) {
        printf("%s", book->title);
        current_word++;
    }
}

void book_stats(book_t *book) {
    printf("Book Stats:\n");
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    printf("Words per page: %d\n", book->words_per_page);
}

int main() {
    init_book(&current_book);

    while (1) {
        book_stats(&current_book);
        turn_page(&current_book);
        read_word(&current_book);

        // Add some randomness to the program
        srand(time(NULL));
        int random_page = rand() % current_book.pages;
        int random_word = rand() % current_book.words_per_page;

        if (random_page == current_page && random_word == current_word) {
            printf("You've reached the end of the book! Would you like to start again? (y/n)\n");
            char response = getchar();
            if (response == 'y' || response == 'Y') {
                current_page = 0;
                current_word = 0;
            } else {
                break;
            }
        }
    }

    return 0;
}