//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000000

typedef struct {
    char *line;
    int length;
} Line;

Line *lines = NULL;
int num_lines = 0;

void add_line(char *new_line) {
    Line *new_line_struct = malloc(sizeof(Line));
    new_line_struct->line = strdup(new_line);
    new_line_struct->length = strlen(new_line);
    lines = realloc(lines, sizeof(Line) * ++num_lines);
    lines[num_lines - 1] = *new_line_struct;
    free(new_line_struct);
}

int compare_lines(const void *a, const void *b) {
    Line *line_a = (Line *)a;
    Line *line_b = (Line *)b;

    if (line_a->length > line_b->length) {
        return 1;
    } else if (line_a->length < line_b->length) {
        return -1;
    } else {
        return 0;
    }
}

void print_lines() {
    qsort(lines, num_lines, sizeof(Line), compare_lines);

    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i].line);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
        add_line(line);

        if (num_lines >= MAX_NUM_LINES) {
            print_lines();
            num_lines = 0;
        }
    }

    if (num_lines > 0) {
        print_lines();
    }

    return 0;
}