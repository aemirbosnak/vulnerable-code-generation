//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOK_SIZE 1000
#define MAX_PAGE_SIZE 50

typedef struct book {
    char title[50];
    char author[50];
    int pages;
    struct book *next;
} book_t;

typedef struct page {
    char text[50];
    int num;
    struct page *next;
} page_t;

book_t *create_book(const char *title, const char *author, int pages) {
    book_t *book = malloc(sizeof(book_t));
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->pages = pages;
    book->next = NULL;
    return book;
}

page_t *create_page(const char *text, int num) {
    page_t *page = malloc(sizeof(page_t));
    strcpy(page->text, text);
    page->num = num;
    page->next = NULL;
    return page;
}

void add_page_to_book(book_t *book, page_t *page) {
    book->pages++;
    page->next = book->pages;
    book->pages = page;
}

void display_book(book_t *book) {
    printf("Book Title: %s\n", book->title);
    printf("Book Author: %s\n", book->author);
    printf("Book Pages: %d\n", book->pages);
    book_t *current = book;
    while (current != NULL) {
        page_t *current_page = current->pages;
        while (current_page != NULL) {
            printf("%d. %s\n", current_page->num, current_page->text);
            current_page = current_page->next;
        }
        current = current->next;
    }
}

int main() {
    book_t *book1 = create_book("The Great Gatsby", "F. Scott Fitzgerald", 20);
    book_t *book2 = create_book("To Kill a Mockingbird", "Harper Lee", 25);
    book_t *book3 = create_book("The Catcher in the Rye", "J.D. Salinger", 30);

    page_t *page1 = create_page("In the town of West Egg, there lived a man named Gatsby.", 1);
    page_t *page2 = create_page("He was a mystery, a man of wealth and taste, but also a man of secrets.", 2);
    page_t *page3 = create_page("Nick Carraway, a young man from the Midwest, moved to Long Island and became Gatsby's neighbor.", 3);
    page_t *page4 = create_page("As the summer progressed, Gatsby and Nick became fast friends, bonding over their love of parties and their sense of wonder.", 4);

    add_page_to_book(book1, page1);
    add_page_to_book(book1, page2);
    add_page_to_book(book1, page3);
    add_page_to_book(book2, page4);

    display_book(book1);
    display_book(book2);
    display_book(book3);

    return 0;
}