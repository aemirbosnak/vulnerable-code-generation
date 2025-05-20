//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Lines;

Lines *read_lines(FILE *fp) {
    Lines *lines = malloc(sizeof(Lines));
    lines->num_lines = 0;
    lines->lines = NULL;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        Line *line_struct = malloc(sizeof(Line));
        line_struct->line = strdup(line);
        line_struct->length = strlen(line);

        lines->num_lines++;
        lines->lines = realloc(lines->lines, sizeof(Line) * lines->num_lines);
        lines->lines[lines->num_lines - 1] = *line_struct;
    }

    return lines;
}

void free_lines(Lines *lines) {
    for (int i = 0; i < lines->num_lines; i++) {
        free(lines->lines[i].line);
    }
    free(lines->lines);
    free(lines);
}

void print_lines(Lines *lines) {
    for (int i = 0; i < lines->num_lines; i++) {
        printf("%s", lines->lines[i].line);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    Lines *lines = read_lines(fp);
    fclose(fp);

    print_lines(lines);

    free_lines(lines);

    return EXIT_SUCCESS;
}