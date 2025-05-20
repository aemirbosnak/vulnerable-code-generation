//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_BOOKS 5
#define MAX_CHAPTERS 10
#define MAX_WORDS_PER_PAGE 50

typedef struct {
    char title[50];
    char author[50];
    int num_chapters;
    char** chapters;
} Book;

void load_book(const char* filename, Book* book) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    fscanf(file, "%s %s", book->title, book->author);
    book->num_chapters = 0;

    book->chapters = malloc(MAX_CHAPTERS * sizeof(char*));

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (book->num_chapters >= MAX_CHAPTERS) {
            printf("Error: Maximum number of chapters reached\n");
            exit(1);
        }
        book->chapters[book->num_chapters] = malloc(strlen(line) + 1);
        strcpy(book->chapters[book->num_chapters], line);
        book->num_chapters++;
    }

    fclose(file);
}

void display_book(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Number of chapters: %d\n", book.num_chapters);

    for (int i = 0; i < book.num_chapters; i++) {
        printf("Chapter %d:\n%s\n", i+1, book.chapters[i]);
    }
}

int main() {
    Book books[MAX_BOOKS];

    for (int i = 0; i < MAX_BOOKS; i++) {
        printf("Enter filename of book %d: ", i+1);
        char filename[50];
        scanf("%s", filename);

        load_book(filename, &books[i]);
    }

    for (int i = 0; i < MAX_BOOKS; i++) {
        printf("\nBook %d:\n", i+1);
        display_book(books[i]);

        for (int j = 0; j < books[i].num_chapters; j++) {
            free(books[i].chapters[j]);
        }
        free(books[i].chapters);
    }

    return 0;
}