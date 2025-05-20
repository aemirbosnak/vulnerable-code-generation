//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *line;
    int length;
} Line;

Line *read_lines(FILE *file) {
    Line *lines = NULL;
    char line[MAX_LINE_LENGTH];
    int length = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        length = strlen(line);
        if (length > 0 && line[length - 1] == '\n') {
            line[--length] = '\0';
        }
        Line *new_line = (Line *) malloc(sizeof(Line));
        new_line->line = strdup(line);
        new_line->length = length;
        lines = (Line *) realloc(lines, sizeof(Line) * (lines? lines_count(lines) + 1 : 1));
        lines[lines_count(lines) - 1] = *new_line;
    }

    return lines;
}

int lines_count(Line *lines) {
    if (!lines) {
        return 0;
    }

    int count = 0;
    while (lines[count].line) {
        count++;
    }

    return count;
}

void free_lines(Line *lines) {
    if (!lines) {
        return;
    }

    for (int i = 0; i < lines_count(lines); i++) {
        free(lines[i].line);
    }

    free(lines);
}

void print_lines(Line *lines) {
    if (!lines) {
        return;
    }

    for (int i = 0; i < lines_count(lines); i++) {
        printf("%s\n", lines[i].line);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s FILE\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    Line *lines = read_lines(file);
    if (!lines) {
        printf("Error reading file: %s\n", argv[1]);
        return 1;
    }

    print_lines(lines);

    free_lines(lines);
    fclose(file);

    return 0;
}