//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_BOOK_SIZE 1000000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char content[MAX_BOOK_SIZE];
} Book;

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;

    // Read in book data from file
    FILE *fp = fopen("books.txt", "r");
    if (fp == NULL) {
        printf("Error reading book data!\n");
        return 1;
    }

    char line[MAX_TITLE_LENGTH + MAX_AUTHOR_LENGTH + MAX_BOOK_SIZE + 1];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *title = strtok(line, "\t");
        char *author = strtok(NULL, "\t");
        char *content = strtok(NULL, "\n");

        strncpy(books[numBooks].title, title, MAX_TITLE_LENGTH);
        strncpy(books[numBooks].author, author, MAX_AUTHOR_LENGTH);
        strncpy(books[numBooks].content, content, MAX_BOOK_SIZE);

        numBooks++;
        if (numBooks >= MAX_BOOKS) {
            break;
        }
    }

    fclose(fp);

    // Display book data
    for (int i = 0; i < numBooks; i++) {
        printf("Title: %s\nAuthor: %s\nContent:\n%s\n\n", books[i].title, books[i].author, books[i].content);
    }

    return 0;
}