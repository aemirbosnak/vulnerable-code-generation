//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LINE_COUNT 1000

typedef struct {
    char *text;
    int length;
} line_t;

line_t *lines = NULL;
int line_count = 0;

void add_line(const char *text) {
    line_t *line = malloc(sizeof(line_t));
    line->text = strdup(text);
    line->length = strlen(text);
    lines = realloc(lines, sizeof(line_t) * ++line_count);
    lines[line_count - 1] = *line;
    free(line);
}

void print_lines() {
    for (int i = 0; i < line_count; ++i) {
        printf("%s\n", lines[i].text);
    }
}

void free_lines() {
    for (int i = 0; i < line_count; ++i) {
        free(lines[i].text);
    }
    free(lines);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        add_line(line);
    }

    fclose(file);
    print_lines();
    free_lines();

    return 0;
}