//Falcon-180B DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *fp;
    char mode;
} File;

File *open_file(char *filename, char mode) {
    File *file = (File *) malloc(sizeof(File));
    file->filename = strdup(filename);
    file->mode = mode;
    file->fp = fopen(filename, mode);
    if (file->fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    return file;
}

void close_file(File *file) {
    fclose(file->fp);
    free(file->filename);
    free(file);
}

char *read_line(File *file) {
    char *line = (char *) malloc(MAX_LINE_LENGTH * sizeof(char));
    fgets(line, MAX_LINE_LENGTH, file->fp);
    return line;
}

void write_line(File *file, char *line) {
    fprintf(file->fp, "%s", line);
}

int main() {
    File *input_file = open_file("input.txt", "r");
    File *output_file = open_file("output.txt", "w");

    char *line = read_line(input_file);
    while (line!= NULL) {
        line[strcspn(line, "\n")] = '\0'; // Remove newline character
        if (strlen(line) > 0) {
            write_line(output_file, line);
        }
        line = read_line(input_file);
    }

    close_file(input_file);
    close_file(output_file);

    return 0;
}