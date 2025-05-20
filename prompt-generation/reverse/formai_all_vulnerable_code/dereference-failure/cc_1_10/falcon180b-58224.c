//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_PAGES 1000
#define MAX_WORDS 100000

typedef struct {
    char title[50];
    char author[50];
    int num_pages;
    char pages[MAX_PAGES][MAX_WORDS];
} Book;

int main() {
    int num_books = 0;
    Book books[MAX_BOOKS];
    char filename[100];

    printf("Enter the name of the ebook file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_books >= MAX_BOOKS) {
            printf("Error: too many books in the file.\n");
            fclose(fp);
            return 1;
        }
        books[num_books].title[0] = '\0';
        books[num_books].author[0] = '\0';
        books[num_books].num_pages = 0;
        strcpy(books[num_books].title, strtok(line, ","));
        strcpy(books[num_books].author, strtok(NULL, ","));
        books[num_books].num_pages = atoi(strtok(NULL, ","));
        num_books++;
    }

    fclose(fp);

    printf("Enter the title of the book you want to read: ");
    scanf("%s", filename);

    int book_index = -1;
    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].title, filename) == 0) {
            book_index = i;
            break;
        }
    }

    if (book_index == -1) {
        printf("Error: book not found.\n");
        return 1;
    }

    printf("Reading %s by %s...\n", books[book_index].title, books[book_index].author);
    for (int page = 0; page < books[book_index].num_pages; page++) {
        printf("Page %d:\n", page+1);
        for (int i = 0; i < strlen(books[book_index].pages[page]); i++) {
            printf("%c", books[book_index].pages[page][i]);
        }
        printf("\n\n");
    }

    return 0;
}