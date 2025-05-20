//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>

#define MAX_BOOK_SIZE 1024 * 1024 * 50
#define MAX_PAGE_SIZE 1024 * 1024 * 20

typedef struct {
    char *title;
    char *author;
    char *content;
    size_t size;
} Book;

typedef struct {
    Book book;
    size_t page_num;
    size_t page_size;
} Page;

typedef struct {
    Page page[10];
    size_t current_page;
} Bookshelf;

Bookshelf *books;

void init_books(void) {
    books = calloc(1, sizeof(Bookshelf));
    books->current_page = 0;
}

void add_book(const char *title, const char *author, const char *content) {
    Book book;
    book.title = title;
    book.author = author;
    book.content = content;
    book.size = strlen(content);
    books->page[books->current_page].book = book;
    books->page[books->current_page].page_num = 0;
    books->page[books->current_page].page_size = books->current_page == 0 ? MAX_PAGE_SIZE : 0;
    books->current_page++;
}

void turn_page(size_t page_num) {
    if (page_num >= books->current_page) {
        books->current_page = page_num;
        books->page[books->current_page].page_num = 0;
        books->page[books->current_page].page_size = books->current_page == 0 ? MAX_PAGE_SIZE : 0;
    }
}

void display_book(size_t page_num) {
    size_t i;
    for (i = 0; i < page_num; i++) {
        if (books->page[i].page_size > 0) {
            printf("Page %zu: %s\n", i + 1, books->page[i].book.content);
            books->page[i].page_size -= books->page[i].book.size;
        }
    }
}

int main(void) {
    init_books();

    // Example usage:
    add_book("The Great Gatsby", "F. Scott Fitzgerald",
             "In the town of West Egg, Long Island, there lived a man named "
             "Jay Gatsby, who was known for throwing extravagant parties. But "
             "there was more to Gatsby than just his parties...");

    // Display the first page:
    display_book(1);

    // Turn to the second page:
    turn_page(2);

    // Display the second page:
    display_book(2);

    return 0;
}