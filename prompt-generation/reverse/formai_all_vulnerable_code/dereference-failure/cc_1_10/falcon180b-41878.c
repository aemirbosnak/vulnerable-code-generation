//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_WORD 1024

typedef struct {
    char *title;
    char *author;
    char *genre;
    int num_pages;
} Book;

typedef struct {
    char *filename;
    char *title;
    char *author;
    char *genre;
    int num_pages;
    char *content;
} EBook;

void load_ebook(EBook *ebook) {
    FILE *fp;
    char line[MAX_LINE];
    char word[MAX_WORD];
    char *content = NULL;
    int num_pages = 0;

    fp = fopen(ebook->filename, "r");

    if (fp == NULL) {
        printf("Error: Unable to open ebook file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        num_pages++;
        content = realloc(content, strlen(content) + strlen(line) + 1);
        strcat(content, line);
    }

    fclose(fp);

    ebook->content = content;
    ebook->num_pages = num_pages;
}

void read_ebook(EBook *ebook) {
    int i, j, k;
    char *word;
    char *delim = " \t\n\r\f\v:;,.?!()[]{}<>";

    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Genre: %s\n", ebook->genre);
    printf("Number of Pages: %d\n", ebook->num_pages);

    for (i = 0; i < ebook->num_pages; i++) {
        if ((word = strtok(ebook->content + i * MAX_LINE, delim))!= NULL) {
            printf("Page %d:\n", i + 1);
            do {
                printf("%s ", word);
            } while ((word = strtok(NULL, delim))!= NULL);
            printf("\n");
        }
    }
}

int main() {
    EBook ebook;

    ebook.filename = "example.ebook";
    ebook.title = "Example Ebook";
    ebook.author = "John Doe";
    ebook.genre = "Fiction";
    ebook.num_pages = 0;
    ebook.content = NULL;

    load_ebook(&ebook);
    read_ebook(&ebook);

    return 0;
}