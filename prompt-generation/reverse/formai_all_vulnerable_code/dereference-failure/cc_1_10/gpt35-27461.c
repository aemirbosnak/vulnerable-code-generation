//FormAI DATASET v1.0 Category: Ebook reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    int year;
    int pages;
} Book;

void displayBook(Book b) {
    printf("\nTitle: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Year: %d\n", b.year);
    printf("Pages: %d\n", b.pages);
}

void displayAllBooks(Book* books, int size) {
    for(int i = 0; i < size; i++) {
        displayBook(books[i]);
    }
}

Book* readBooksFromFile(char* filename, int* size) {
    FILE *fp;
    Book *books;

    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d", size);
    books = malloc((*size) * sizeof(Book));

    for(int i = 0; i < *size; i++) {
        fscanf(fp, "%s %s %d %d", books[i].title, books[i].author, &books[i].year, &books[i].pages);
    }

    fclose(fp);

    return books;
}

void saveBooksToFile(char* filename, Book* books, int size) {
    FILE *fp;

    fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%d\n", size);

    for(int i = 0; i < size; i++) {
        fprintf(fp, "%s %s %d %d\n", books[i].title, books[i].author, books[i].year, books[i].pages);
    }

    fclose(fp);
}

int main() {
    char filename[] = "books.txt";
    int size;
    Book *books;

    books = readBooksFromFile(filename, &size);

    displayAllBooks(books, size);

    saveBooksToFile(filename, books, size);

    free(books);

    return 0;
}