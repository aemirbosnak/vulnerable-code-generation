//FormAI DATASET v1.0 Category: Ebook reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_FILENAME_LENGTH 100
#define MAX_LINE_LENGTH 200

typedef struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year_published;
    char filename[MAX_FILENAME_LENGTH];
} Book;

int main() {
    Book library[MAX_BOOKS];
    int num_books = 0;
    char filename[MAX_FILENAME_LENGTH];

    printf("Welcome to the Ebook Reader program!\n");

    while (1) {
        printf("\nEnter the filename to load a new book: ");
        scanf("%s", filename);

        if (strcmp(filename, "quit") == 0) {
            break;
        }

        FILE* fp = fopen(filename, "r");
        if (!fp) {
            printf("Error: could not open file\n");
            continue;
        }

        char line[MAX_LINE_LENGTH];
        fgets(line, MAX_LINE_LENGTH, fp); // skip first line

        if (num_books == MAX_BOOKS) {
            printf("Error: library is full\n");
            fclose(fp);
            continue;
        }

        Book new_book;
        strcpy(new_book.filename, filename);
        while (fgets(line, MAX_LINE_LENGTH, fp)) {
            char* token = strtok(line, ",");
            strcpy(new_book.title, token);
            token = strtok(NULL, ",");
            strcpy(new_book.author, token);
            token = strtok(NULL, ",");
            new_book.year_published = atoi(token);
        }

        library[num_books++] = new_book;
        printf("Successfully loaded book into library!\n");
        fclose(fp);
    }

    printf("\nLibrary:\n");

    for (int i = 0; i < num_books; i++) {
        printf("%d. \"%s\" by %s (%d)\n", i+1, library[i].title, library[i].author, library[i].year_published);
    }

    printf("\nThanks for using Ebook Reader!\n");

    return 0;
}