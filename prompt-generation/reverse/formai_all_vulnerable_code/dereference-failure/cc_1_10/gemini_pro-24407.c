//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    int length;
    int capacity;
} Line;

typedef struct {
    Line *lines;
    int count;
    int capacity;
} Lines;

Lines *lines_new() {
    Lines *lines = malloc(sizeof(Lines));
    lines->lines = malloc(sizeof(Line) * 10);
    lines->count = 0;
    lines->capacity = 10;
    return lines;
}

void lines_free(Lines *lines) {
    for (int i = 0; i < lines->count; i++) {
        free(lines->lines[i].line);
    }
    free(lines->lines);
    free(lines);
}

void lines_add(Lines *lines, char *line) {
    if (lines->count >= lines->capacity) {
        lines->lines = realloc(lines->lines, sizeof(Line) * lines->capacity * 2);
        lines->capacity *= 2;
    }
    lines->lines[lines->count].line = strdup(line);
    lines->lines[lines->count].length = strlen(line);
    lines->lines[lines->count].capacity = lines->lines[lines->count].length + 1;
    lines->count++;
}

char *lines_join(Lines *lines) {
    int total_length = 0;
    for (int i = 0; i < lines->count; i++) {
        total_length += lines->lines[i].length + 1;
    }
    char *joined_lines = malloc(total_length);
    int offset = 0;
    for (int i = 0; i < lines->count; i++) {
        memcpy(joined_lines + offset, lines->lines[i].line, lines->lines[i].length);
        offset += lines->lines[i].length;
        joined_lines[offset++] = '\n';
    }
    return joined_lines;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    Lines *lines = lines_new();
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        lines_add(lines, line);
    }
    fclose(fp);

    char *joined_lines = lines_join(lines);
    printf("%s", joined_lines);
    free(joined_lines);
    lines_free(lines);

    return 0;
}