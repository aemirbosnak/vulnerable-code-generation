//Falcon-180B DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_LINES 1000

typedef struct {
    char *line;
    size_t length;
} Line;

FILE *file;
Line lines[MAX_LINES];
size_t num_lines = 0;

void read_file(const char *filename) {
    char buffer[MAX_LINE_SIZE];
    size_t i = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    while (fgets(buffer, MAX_LINE_SIZE, file)!= NULL) {
        lines[i].line = strdup(buffer);
        lines[i].length = strlen(lines[i].line);
        i++;
        num_lines++;
    }

    fclose(file);
}

void print_lines() {
    for (size_t i = 0; i < num_lines; i++) {
        printf("%zu. %s\n", i + 1, lines[i].line);
    }
}

void reverse_lines() {
    for (size_t i = 0; i < num_lines / 2; i++) {
        Line temp = lines[i];
        lines[i] = lines[num_lines - i - 1];
        lines[num_lines - i - 1] = temp;
    }
}

void write_file(const char *filename) {
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    for (size_t i = 0; i < num_lines; i++) {
        fprintf(file, "%s", lines[i].line);
    }

    fclose(file);
}

int main() {
    char input_filename[MAX_LINE_SIZE];
    char output_filename[MAX_LINE_SIZE];

    printf("Enter input filename: ");
    fgets(input_filename, MAX_LINE_SIZE, stdin);

    printf("Enter output filename: ");
    fgets(output_filename, MAX_LINE_SIZE, stdin);

    read_file(input_filename);
    reverse_lines();
    write_file(output_filename);

    printf("File read, lines reversed, and written to %s\n", output_filename);

    return 0;
}