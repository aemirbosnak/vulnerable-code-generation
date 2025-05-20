//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 500

typedef struct {
    char *title;
    char *author;
    char *text;
} Ebook;

char *read_line(FILE *file) {
    char *line = NULL;
    size_t size = 0;
    getline(&line, &size, file);
    return line;
}

Ebook *read_ebook(FILE *file) {
    Ebook *ebook = malloc(sizeof(Ebook));
    ebook->title = read_line(file);
    ebook->author = read_line(file);
    ebook->text = malloc(MAX_LINE_LENGTH * sizeof(char));
    int text_length = 0;
    char *line = NULL;
    while ((line = read_line(file))!= NULL) {
        int line_length = strlen(line);
        if (text_length + line_length + 1 >= MAX_LINE_LENGTH) {
            break;
        }
        strcat(ebook->text, line);
        text_length += line_length;
    }
    return ebook;
}

void print_ebook(Ebook *ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n\n", ebook->author);
    printf("Text:\n%s\n", ebook->text);
}

int main() {
    FILE *file = fopen("example_ebook.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    Ebook *ebook = read_ebook(file);
    if (ebook == NULL) {
        printf("Error: could not read ebook.\n");
        return 1;
    }

    print_ebook(ebook);

    free(ebook->title);
    free(ebook->author);
    free(ebook->text);
    free(ebook);

    fclose(file);
    return 0;
}