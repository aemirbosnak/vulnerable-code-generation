//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define BOOKSHELF_WIDTH 80
#define BOOKSHELF_HEIGHT 20
#define BOOK_WIDTH 600
#define BOOK_HEIGHT 800

typedef struct book {
    char title[50];
    char author[50];
    char description[100];
} Book;

typedef struct bookshelf {
    Book books[10];
    int current_book;
} Bookshelf;

Bookshelf *bookshelf = NULL;

void init_bookshelf(void) {
    bookshelf = malloc(sizeof(Bookshelf));
    for (int i = 0; i < 10; i++) {
        bookshelf->books[i].title[0] = '\0';
        bookshelf->books[i].author[0] = '\0';
        bookshelf->books[i].description[0] = '\0';
    }
}

void add_book(char *title, char *author, char *description) {
    int i = bookshelf->current_book;
    if (i == 10) {
        printf("Bookshelf is full, cannot add more books.\n");
        return;
    }
    strcpy(bookshelf->books[i].title, title);
    strcpy(bookshelf->books[i].author, author);
    strcpy(bookshelf->books[i].description, description);
    bookshelf->current_book++;
}

void display_bookshelf(void) {
    printf("Virtual Bookshelf\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s - %s\n", i + 1, bookshelf->books[i].title, bookshelf->books[i].author);
    }
}

void select_book(int index) {
    bookshelf->current_book = index;
    printf("Selected book: %s - %s\n", bookshelf->books[index].title, bookshelf->books[index].author);
}

void display_book(void) {
    printf("Book Content:\n");
    for (int i = 0; i < strlen(bookshelf->books[bookshelf->current_book].description); i++) {
        if (bookshelf->books[bookshelf->current_book].description[i] == '\n') {
            printf("");
        } else {
            printf("%c", bookshelf->books[bookshelf->current_book].description[i]);
        }
    }
}

int main(void) {
    init_bookshelf();

    while (1) {
        display_bookshelf();
        printf("Select a book (1-10): ");
        scanf("%d", &index);
        select_book(index);
        display_book();
    }

    return 0;
}