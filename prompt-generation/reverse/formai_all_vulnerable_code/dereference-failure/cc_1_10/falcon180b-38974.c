//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define EBOOK_FILE "ebook.txt"
#define EBOOK_TITLE "The Adventures of Sherlock Holmes"
#define EBOOK_AUTHOR "Arthur Conan Doyle"

typedef struct {
    char *title;
    char *author;
    char *content;
} eBook;

eBook ebook;

void readEbookFile() {
    FILE *file = fopen(EBOOK_FILE, "r");
    if (file == NULL) {
        printf("Error: could not open ebook file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char *content = NULL;
    size_t contentSize = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        content = realloc(content, contentSize + strlen(line) + 1);
        strcat(content, line);
        contentSize += strlen(line);
    }

    ebook.content = content;
    ebook.title = strdup(EBOOK_TITLE);
    ebook.author = strdup(EBOOK_AUTHOR);

    fclose(file);
}

void displayEbook() {
    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Content:\n");

    char *line = strtok(ebook.content, "\n");
    while (line!= NULL) {
        printf("%s\n", line);
        line = strtok(NULL, "\n");
    }
}

int main() {
    readEbookFile();
    displayEbook();

    return 0;
}