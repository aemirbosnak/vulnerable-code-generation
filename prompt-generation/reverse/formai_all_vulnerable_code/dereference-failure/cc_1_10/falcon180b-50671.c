//Falcon-180B DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *filename;
    FILE *file;
    char *mode;
} File;

File *open_file(const char *filename, const char *mode) {
    File *file = malloc(sizeof(File));
    if (file == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    file->filename = strdup(filename);
    file->mode = strdup(mode);
    file->file = fopen(filename, mode);
    if (file->file == NULL) {
        printf("Error: Failed to open file '%s'\n", filename);
        free(file->filename);
        free(file->mode);
        free(file);
        exit(1);
    }
    return file;
}

int close_file(File *file) {
    int result = fclose(file->file);
    free(file->filename);
    free(file->mode);
    free(file);
    return result;
}

char *read_line(File *file) {
    char *line = malloc(MAX_LINE_SIZE);
    if (line == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    if (fgets(line, MAX_LINE_SIZE, file->file) == NULL) {
        printf("Error: Failed to read line from file\n");
        free(line);
        exit(1);
    }
    return line;
}

int write_line(File *file, const char *line) {
    int result = fprintf(file->file, "%s", line);
    if (result < 0) {
        printf("Error: Failed to write line to file\n");
        exit(1);
    }
    return result;
}

int main() {
    File *input_file, *output_file;
    char *line;

    // Open input file for reading
    input_file = open_file("input.txt", "r");

    // Open output file for writing
    output_file = open_file("output.txt", "w");

    // Read each line from input file and write to output file
    while ((line = read_line(input_file))!= NULL) {
        line[strcspn(line, "\n")] = '\0'; // Remove newline character
        if (write_line(output_file, line) < 0) {
            printf("Error: Failed to write line to output file\n");
            exit(1);
        }
    }

    // Close files
    close_file(input_file);
    close_file(output_file);

    return 0;
}