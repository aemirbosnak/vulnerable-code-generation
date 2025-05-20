//Falcon-180B DATASET v1.0 Category: File handling ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int line_num;
} Line;

Line *read_lines(FILE *file) {
    Line *lines = malloc(MAX_NUM_LINES * sizeof(Line));
    int num_lines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        lines[num_lines].line = strdup(line);
        lines[num_lines].line_num = num_lines + 1;
        num_lines++;
    }

    return lines;
}

void write_lines(Line *lines, FILE *file) {
    for (int i = 0; i < MAX_NUM_LINES; i++) {
        if (lines[i].line!= NULL) {
            fprintf(file, "%d: %s\n", lines[i].line_num, lines[i].line);
        }
    }
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    Line *lines = read_lines(input_file);

    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    write_lines(lines, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}