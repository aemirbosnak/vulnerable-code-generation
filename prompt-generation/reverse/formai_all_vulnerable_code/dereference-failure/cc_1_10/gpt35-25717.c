//FormAI DATASET v1.0 Category: Ebook reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {
    char title[100];
    char author[50];
    int year;
    float price;
    char isbn[20];
} Book;

int main() {
    int i, bookCount;
    char searchTitle[100];
    char filename[20];
    FILE *fp;
    Book *books;

    printf("Enter the name of the file to read from: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error: Unable to open file %s", filename);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    bookCount = ftell(fp) / sizeof(Book);
    fseek(fp, 0, SEEK_SET);

    books = (Book*) malloc(bookCount * sizeof(Book));
    fread(books, sizeof(Book), bookCount, fp);
    fclose(fp);

    printf("Enter the title to search for: ");
    scanf("%s", searchTitle);

    for (i = 0; i < bookCount; i++) {
        if (strcmp(searchTitle, books[i].title) == 0) {
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Year: %d\n", books[i].year);
            printf("Price: %.2f\n", books[i].price);
            printf("ISBN: %s\n", books[i].isbn);
        }
    }

    free(books);

    return 0;
}