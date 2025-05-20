//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: surprised
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
    int count;
    int size;
} Lines;

void lines_init(Lines *lines) {
    lines->lines = malloc(sizeof(Line) * 10);
    lines->count = 0;
    lines->size = 10;
}

void lines_free(Lines *lines) {
    for (int i = 0; i < lines->count; i++) {
        free(lines->lines[i].line);
    }

    free(lines->lines);
}

void lines_add(Lines *lines, char *line) {
    if (lines->count == lines->size) {
        lines->size *= 2;
        lines->lines = realloc(lines->lines, sizeof(Line) * lines->size);
    }

    lines->lines[lines->count].line = strdup(line);
    lines->lines[lines->count].length = strlen(line);
    lines->count++;
}

void lines_print(Lines *lines) {
    for (int i = 0; i < lines->count; i++) {
        printf("%s", lines->lines[i].line);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    Lines lines;
    lines_init(&lines);

    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        lines_add(&lines, line);
    }

    fclose(fp);

    lines_print(&lines);
    
    lines_free(&lines);

    return EXIT_SUCCESS;
}