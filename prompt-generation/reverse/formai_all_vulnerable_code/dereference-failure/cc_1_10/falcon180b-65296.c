//Falcon-180B DATASET v1.0 Category: File handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 10000

typedef struct {
    char *line;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} File;

File *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    File *result = malloc(sizeof(File));
    result->lines = malloc(sizeof(Line) * MAX_NUM_LINES);
    result->num_lines = 0;

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        Line line = {.line = strdup(buffer),.length = strlen(buffer) };
        if (result->num_lines >= MAX_NUM_LINES) {
            fprintf(stderr, "Error: reached maximum number of lines\n");
            exit(1);
        }
        result->lines[result->num_lines++] = line;
    }

    fclose(file);
    return result;
}

void print_file(const File *file) {
    for (int i = 0; i < file->num_lines; i++) {
        printf("%s\n", file->lines[i].line);
    }
}

void write_file(const File *file, const char *filename) {
    FILE *out_file = fopen(filename, "w");
    if (out_file == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < file->num_lines; i++) {
        fprintf(out_file, "%s", file->lines[i].line);
    }

    fclose(out_file);
}

int main() {
    File *input_file = read_file("input.txt");

    print_file(input_file);

    write_file(input_file, "output.txt");

    return 0;
}