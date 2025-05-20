//Falcon-180B DATASET v1.0 Category: Error handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 100

typedef struct {
    char *line;
    int line_num;
} Line;

Line *lines = NULL;
int num_lines = 0;

void add_line(char *line) {
    Line *new_line = malloc(sizeof(Line));
    if (new_line == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_line->line = strdup(line);
    new_line->line_num = num_lines;
    lines = realloc(lines, sizeof(Line) * (num_lines + 1));
    lines[num_lines] = *new_line;
    num_lines++;
}

void print_lines() {
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", lines[i].line_num, lines[i].line);
    }
}

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        add_line(line);
        if (num_lines >= MAX_NUM_LINES) {
            printf("Error: Too many lines\n");
            exit(1);
        }
    }

    fclose(file);

    print_lines();

    return 0;
}