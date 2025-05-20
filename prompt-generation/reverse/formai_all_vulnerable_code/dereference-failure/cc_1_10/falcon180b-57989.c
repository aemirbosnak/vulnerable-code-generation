//Falcon-180B DATASET v1.0 Category: File handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int length;
} Line;

Line *read_lines(FILE *file, int *num_lines) {
    Line *lines = NULL;
    int current_line = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        lines = realloc(lines, sizeof(Line) * ++current_line);
        lines[current_line - 1].line = strdup(line);
        lines[current_line - 1].length = strlen(line);
    }

    *num_lines = current_line;
    return lines;
}

void write_lines(Line *lines, int num_lines, FILE *file) {
    for (int i = 0; i < num_lines; i++) {
        fprintf(file, "%s", lines[i].line);
    }
}

void sort_lines(Line *lines, int num_lines) {
    for (int i = 0; i < num_lines - 1; i++) {
        for (int j = i + 1; j < num_lines; j++) {
            if (lines[j].length < lines[i].length) {
                Line temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }

    int num_lines;
    Line *lines = read_lines(input_file, &num_lines);

    sort_lines(lines, num_lines);

    write_lines(lines, num_lines, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}