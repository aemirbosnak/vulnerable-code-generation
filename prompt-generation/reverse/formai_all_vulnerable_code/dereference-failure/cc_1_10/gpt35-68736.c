//FormAI DATASET v1.0 Category: Ebook reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 50
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_FILENAME_LENGTH 50
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int num_pages;
    char file_name[MAX_FILENAME_LENGTH];
} Ebook;

void load_library(Ebook library[], int *num_books);

void print_library(Ebook library[], int num_books);

void open_book(Ebook book);

int main() {
    Ebook library[MAX_BOOKS];
    int num_books = 0;
    load_library(library, &num_books);
    print_library(library, num_books);
    int selection;
    do {
        printf("Enter the number of the book you would like to read (0 to quit):\n");
        scanf("%d", &selection);
        if (selection > 0 && selection <= num_books) {
            Ebook book = library[selection-1];
            open_book(book);
        } else if (selection != 0) {
            printf("Invalid selection.\n");
        }
    } while (selection != 0);
    return 0;
}

void load_library(Ebook library[], int *num_books) {
    FILE *file = fopen("library.txt", "r");
    if (file == NULL) {
        printf("Error loading library.\n");
        exit(1);
    }
    char line[MAX_TITLE_LENGTH+MAX_AUTHOR_LENGTH+MAX_FILENAME_LENGTH+10];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *title = strtok(line, "|");
        char *author = strtok(NULL, "|");
        char *filename = strtok(NULL, "\n");
        Ebook book;
        strcpy(book.title, title);
        strcpy(book.author, author);
        book.num_pages = MAX_PAGES;
        strcpy(book.file_name, filename);
        library[*num_books] = book;
        *num_books += 1;
    }
}

void print_library(Ebook library[], int num_books) {
    printf("Library:\n");
    for (int i = 0; i < num_books; i++) {
        Ebook book = library[i];
        printf("%d: %s by %s\n", i+1, book.title, book.author);
    }
}

void open_book(Ebook book) {
    printf("Opening %s by %s...\n", book.title, book.author);
    printf("Loading file from %s...\n", book.file_name);
    // code to open ebook and display content goes here
}