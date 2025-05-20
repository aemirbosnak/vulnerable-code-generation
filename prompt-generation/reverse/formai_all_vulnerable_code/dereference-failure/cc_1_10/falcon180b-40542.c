//Falcon-180B DATASET v1.0 Category: Text processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000

typedef struct {
    char *text;
    int line_number;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Text;

void text_init(Text *text) {
    text->lines = NULL;
    text->num_lines = 0;
}

void text_destroy(Text *text) {
    for (int i = 0; i < text->num_lines; i++) {
        free(text->lines[i].text);
    }
    free(text->lines);
}

void text_add_line(Text *text, const char *line) {
    Line *new_line = malloc(sizeof(Line));
    new_line->text = strdup(line);
    new_line->line_number = text->num_lines;
    text->lines = realloc(text->lines, sizeof(Line) * (text->num_lines + 1));
    text->lines[text->num_lines++] = *new_line;
}

int text_get_num_lines(Text *text) {
    return text->num_lines;
}

int text_get_line_number(Text *text, int index) {
    if (index < 0 || index >= text->num_lines) {
        return -1;
    }
    return text->lines[index].line_number;
}

char *text_get_line(Text *text, int index) {
    if (index < 0 || index >= text->num_lines) {
        return NULL;
    }
    return text->lines[index].text;
}

void text_print(Text *text) {
    for (int i = 0; i < text->num_lines; i++) {
        printf("%d: %s\n", text->lines[i].line_number, text->lines[i].text);
    }
}

int main() {
    Text text;
    text_init(&text);

    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_number++;
        text_add_line(&text, line);
    }

    fclose(file);

    text_print(&text);

    text_destroy(&text);

    return 0;
}