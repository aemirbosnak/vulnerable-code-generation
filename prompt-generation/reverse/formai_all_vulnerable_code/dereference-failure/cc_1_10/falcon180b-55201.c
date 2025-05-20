//Falcon-180B DATASET v1.0 Category: Error handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int line_num;
} line_t;

int num_lines = 0;
line_t *lines = NULL;

void add_line(char *line, int line_num) {
    if (num_lines >= MAX_NUM_LINES) {
        printf("Error: too many lines.\n");
        exit(1);
    }
    lines = realloc(lines, sizeof(line_t) * (num_lines + 1));
    lines[num_lines].line = strdup(line);
    lines[num_lines].line_num = line_num;
    num_lines++;
}

void print_lines() {
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", lines[i].line_num, lines[i].line);
    }
}

void free_lines() {
    for (int i = 0; i < num_lines; i++) {
        free(lines[i].line);
    }
    free(lines);
    lines = NULL;
}

int main() {
    char line[MAX_LINE_LENGTH];
    int line_num = 1;

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        add_line(line, line_num);
        line_num++;
    }

    print_lines();

    free_lines();

    return 0;
}