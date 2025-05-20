//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PAGES 100
#define MAX_TEXT_LENGTH 1000

typedef struct {
    char *title;
    char *author;
    char *text;
} Book;

Book current_book;

void init_book(Book *book) {
    book->title = "Untitled";
    book->author = "Unknown";
    book->text = "";
}

void add_page(Book *book, char *text) {
    if (strlen(book->text) + strlen(text) > MAX_TEXT_LENGTH) {
        printf("Error: Text exceeds maximum length of %d characters.\n", MAX_TEXT_LENGTH);
        return;
    }
    strcat(book->text, text);
}

void turn_page(Book *book) {
    if (strlen(book->text) == 0) {
        return;
    }
    char *page = book->text;
    book->text = "";
    printf("Page %s\n", page);
}

int main() {
    Book book;
    init_book(&book);

    char text[MAX_TEXT_LENGTH];
    int page_num = 0;

    while (1) {
        printf("Enter text for page %d (Q to quit): ", page_num + 1);
        fgets(text, MAX_TEXT_LENGTH, stdin);

        add_page(&book, text);

        turn_page(&book);

        if (strcmp(text, "Q") == 0) {
            break;
        }

        page_num++;
    }

    return 0;
}