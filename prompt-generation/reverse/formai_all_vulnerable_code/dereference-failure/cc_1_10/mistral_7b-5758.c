//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char *content;
    struct Book *next;
} Book;

void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Content: %s\n", book->content);
    printf("\n");
}

Book *create_book(char *title, char *author, char *content) {
    Book *new_book = (Book *)malloc(sizeof(Book));
    strncpy(new_book->title, title, MAX_TITLE_LENGTH);
    strncpy(new_book->author, author, MAX_AUTHOR_LENGTH);
    new_book->content = content;
    new_book->next = NULL;
    return new_book;
}

void add_book(Book **catalog, Book *new_book) {
    if (*catalog == NULL) {
        *catalog = new_book;
    } else {
        Book *current = *catalog;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_book;
    }
}

void search_catalog(Book *catalog, char *search_term) {
    Book *current = catalog;
    while (current != NULL) {
        if (strstr(current->title, search_term) != NULL ||
            strstr(current->author, search_term) != NULL) {
            print_book(current);
        }
        current = current->next;
    }
}

int main() {
    char title1[MAX_TITLE_LENGTH] = "The Great Gatsby";
    char author1[MAX_AUTHOR_LENGTH] = "F. Scott Fitzgerald";
    char *content1 = "Jay Gatsby is the man who has everything. But one thing will always be out of his reach...\n";

    char title2[MAX_TITLE_LENGTH] = "To Kill a Mockingbird";
    char author2[MAX_AUTHOR_LENGTH] = "Harper Lee";
    char *content2 = "Set in the deep south during the 1930s, it tells the story of Scout Finch, a young girl growing up in a sleepy Southern town.";

    Book *catalog = NULL;
    add_book(&catalog, create_book(title1, author1, content1));
    add_book(&catalog, create_book(title2, author2, content2));

    char search_term[50] = "Mockingbird";
    printf("Catalog:\n");
    search_catalog(catalog, "");
    printf("\nSearch Results for \"%s\":\n", search_term);
    search_catalog(catalog, search_term);

    return 0;
}