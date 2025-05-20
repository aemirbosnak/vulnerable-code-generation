//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char title[50];
    char author[50];
    int pages;
    struct Book *next;
} Book;

void addBook(Book **library, const char *title, const char *author, int pages) {
    Book *newBook = (Book *) malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->pages = pages;
    newBook->next = *library;
    *library = newBook;
}

void displayLibrary(const Book *library) {
    printf("\nLibrary:\n");
    while (library != NULL) {
        printf("Title: %s\n", library->title);
        printf("Author: %s\n", library->author);
        printf("Pages: %d\n", library->pages);
        library = library->next;
    }
}

void searchBookByTitle(const Book *library, const char *title) {
    bool found = false;
    Book *current = library;

    while (current != NULL && !found) {
        if (strcmp(current->title, title) == 0) {
            found = true;
            printf("\nBook found:\n");
            printf("Title: %s\n", current->title);
            printf("Author: %s\n", current->author);
            printf("Pages: %d\n", current->pages);
        }
        current = current->next;
    }

    if (!found) {
        printf("\nBook not found.\n");
    }
}

int main() {
    Book *library = NULL;

    addBook(&library, "The C Programming Language", "Kernighan & Pike", 471);
    addBook(&library, "Clean Code: A Handbook of Software Craftsmanship", "Robert C. Martin", 467);
    addBook(&library, "The Art of Computer Programming, Volume 1", "Donald E. Knuth", 1095);

    displayLibrary(library);

    char title[50];
    printf("\nEnter the title of the book you want to search for: ");
    scanf("%s", title);

    searchBookByTitle(library, title);

    free(library);

    return 0;
}