//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char *text;
    int line_number;
} Line;

void read_file(const char *filename, Line lines[], int *num_lines) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_LINE_LENGTH];
    int line_number = 1;
    int num_allocated_lines = 10;
    lines = malloc(num_allocated_lines * sizeof(Line));
    if (lines == NULL) {
        fprintf(stderr, "Error: could not allocate memory for lines\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        if (line_number >= num_allocated_lines) {
            num_allocated_lines += 10;
            lines = realloc(lines, num_allocated_lines * sizeof(Line));
            if (lines == NULL) {
                fprintf(stderr, "Error: could not reallocate memory for lines\n");
                exit(EXIT_FAILURE);
            }
        }

        lines[line_number - 1].text = strdup(buffer);
        if (lines[line_number - 1].text == NULL) {
            fprintf(stderr, "Error: could not allocate memory for line %d\n", line_number);
            exit(EXIT_FAILURE);
        }

        lines[line_number - 1].line_number = line_number;
        line_number++;
    }

    fclose(file);

    *num_lines = line_number - 1;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Line lines[10];
    int num_lines = 0;

    read_file(argv[1], lines, &num_lines);

    for (int i = 0; i < num_lines; i++) {
        printf("Line %d: %s\n", lines[i].line_number, lines[i].text);
    }

    for (int i = 0; i < num_lines; i++) {
        free(lines[i].text);
    }
    free(lines);

    return EXIT_SUCCESS;
}