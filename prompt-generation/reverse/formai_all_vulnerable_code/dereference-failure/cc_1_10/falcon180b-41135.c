//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *text;
    int length;
} TextLine;

typedef struct {
    TextLine *lines;
    int num_lines;
} TextFile;

TextFile *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    TextFile *text = NULL;

    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    text = malloc(sizeof(TextFile));
    text->lines = NULL;
    text->num_lines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int length = strlen(line);
        TextLine *new_line = malloc(sizeof(TextLine));
        new_line->text = malloc(length + 1);
        strcpy(new_line->text, line);
        new_line->length = length;
        text->lines = realloc(text->lines, sizeof(TextLine) * (text->num_lines + 1));
        text->lines[text->num_lines++] = *new_line;
    }

    fclose(file);
    return text;
}

void print_file(const TextFile *text) {
    for (int i = 0; i < text->num_lines; i++) {
        printf("%s\n", text->lines[i].text);
    }
}

void free_file(TextFile *text) {
    if (text == NULL) {
        return;
    }

    for (int i = 0; i < text->num_lines; i++) {
        free(text->lines[i].text);
    }
    free(text->lines);
    free(text);
}

int main() {
    const char *filename = "example.txt";
    TextFile *text = read_file(filename);
    print_file(text);
    free_file(text);

    return 0;
}