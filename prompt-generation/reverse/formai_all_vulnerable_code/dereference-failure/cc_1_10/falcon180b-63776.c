//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    size_t length;
} Line;

typedef struct {
    Line *lines;
    size_t count;
} Lines;

static void add_line(Lines *lines, const char *line) {
    if (lines->count >= MAX_LINE_LENGTH) {
        printf("Error: Maximum number of lines reached.\n");
        return;
    }

    size_t length = strlen(line);
    Line *new_line = (Line *)malloc(sizeof(Line) + length + 1);
    if (new_line == NULL) {
        printf("Error: Out of memory.\n");
        return;
    }

    new_line->length = length;
    strcpy(new_line->line, line);

    lines->lines = (Line *)realloc(lines->lines, sizeof(Line) * (lines->count + 1));
    if (lines->lines == NULL) {
        printf("Error: Out of memory.\n");
        free(new_line);
        return;
    }

    lines->lines[lines->count] = *new_line;
    free(new_line);
    lines->count++;
}

static void print_lines(const Lines *lines) {
    for (size_t i = 0; i < lines->count; i++) {
        printf("%s\n", lines->lines[i].line);
    }
}

int main() {
    Lines lines = {NULL, 0};

    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)!= NULL) {
        add_line(&lines, line);
    }

    fclose(file);

    print_lines(&lines);

    free(lines.lines);
    return 0;
}