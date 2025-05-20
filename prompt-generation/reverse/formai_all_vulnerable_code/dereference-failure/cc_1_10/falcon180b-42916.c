//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 255
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int length;
} Line;

Line *lines;
int num_lines;

void init() {
    lines = (Line *)malloc(MAX_NUM_LINES * sizeof(Line));
    num_lines = 0;
}

void add_line(char *str) {
    Line *new_line = (Line *)malloc(sizeof(Line));
    new_line->line = strdup(str);
    new_line->length = strlen(str);
    lines[num_lines++] = *new_line;
}

void print_lines() {
    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i].line);
    }
}

int main() {
    init();

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, stdin)!= NULL) {
        add_line(buffer);
    }

    print_lines();

    for (int i = 0; i < num_lines; i++) {
        free(lines[i].line);
    }
    free(lines);

    return 0;
}