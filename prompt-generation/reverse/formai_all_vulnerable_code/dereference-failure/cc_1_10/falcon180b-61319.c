//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_LINE_NUM 100000

typedef struct {
    char *line;
    int len;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
    int max_lines;
} Lines;

void init_lines(Lines *lines, int max_lines) {
    lines->lines = malloc(max_lines * sizeof(Line));
    lines->num_lines = 0;
    lines->max_lines = max_lines;
}

void add_line(Lines *lines, char *line) {
    if (lines->num_lines >= lines->max_lines) {
        printf("Error: Maximum number of lines reached.\n");
        return;
    }
    lines->lines[lines->num_lines].line = strdup(line);
    lines->lines[lines->num_lines].len = strlen(line);
    lines->num_lines++;
}

void print_lines(Lines *lines) {
    for (int i = 0; i < lines->num_lines; i++) {
        printf("%d: %s (%d bytes)\n", i+1, lines->lines[i].line, lines->lines[i].len);
    }
}

int main() {
    Lines lines;
    init_lines(&lines, MAX_LINE_NUM);

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, stdin))!= -1) {
        add_line(&lines, line);
        if (read < 1) {
            break;
        }
    }

    print_lines(&lines);

    for (int i = 0; i < lines.num_lines; i++) {
        free(lines.lines[i].line);
    }
    free(lines.lines);

    return 0;
}