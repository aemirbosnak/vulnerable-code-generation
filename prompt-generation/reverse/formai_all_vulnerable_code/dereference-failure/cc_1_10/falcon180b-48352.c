//Falcon-180B DATASET v1.0 Category: Text processing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *text;
    int line_number;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Text;

Text *read_text_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    Text *text = malloc(sizeof(Text));
    text->lines = NULL;
    text->num_lines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        Line *new_line = malloc(sizeof(Line));
        new_line->text = strdup(line);
        new_line->line_number = text->num_lines;
        text->lines = realloc(text->lines, sizeof(Line) * ++text->num_lines);
        text->lines[text->num_lines - 1] = *new_line;
    }

    fclose(file);
    return text;
}

void print_text(const Text *text) {
    for (int i = 0; i < text->num_lines; i++) {
        printf("%d: %s\n", text->lines[i].line_number, text->lines[i].text);
    }
}

void free_text(Text *text) {
    for (int i = 0; i < text->num_lines; i++) {
        free(text->lines[i].text);
    }
    free(text->lines);
    free(text);
}

int main() {
    Text *text = read_text_from_file("example.txt");
    print_text(text);
    free_text(text);
    return 0;
}