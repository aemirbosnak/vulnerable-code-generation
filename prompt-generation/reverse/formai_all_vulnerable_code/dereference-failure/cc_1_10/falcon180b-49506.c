//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_BOOK_LENGTH 1000000

typedef struct {
    char *title;
    char *author;
    char *content;
    int content_length;
} Book;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <ebook_file>\n", argv[0]);
        return 1;
    }

    FILE *ebook_file = fopen(argv[1], "r");
    if (ebook_file == NULL) {
        printf("Error: Cannot open ebook file.\n");
        return 1;
    }

    Book ebook;
    ebook.title = NULL;
    ebook.author = NULL;
    ebook.content = NULL;
    ebook.content_length = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, ebook_file)!= NULL) {
        if (ebook.title == NULL) {
            int title_length = strlen(line);
            ebook.title = malloc(title_length + 1);
            strcpy(ebook.title, line);
        } else if (ebook.author == NULL) {
            int author_length = strlen(line);
            ebook.author = malloc(author_length + 1);
            strcpy(ebook.author, line);
        } else {
            ebook.content = realloc(ebook.content, ebook.content_length + strlen(line) + 1);
            strcat(ebook.content, line);
            ebook.content_length += strlen(line);
        }
    }

    fclose(ebook_file);

    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);

    printf("Content:\n");
    printf("%s", ebook.content);

    free(ebook.title);
    free(ebook.author);
    free(ebook.content);

    return 0;
}