//Falcon-180B DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_SIZE 1000000

typedef struct {
    char *filename;
    FILE *file;
    size_t lines_written;
} file_t;

void init_file(file_t *file, const char *filename) {
    file->filename = strdup(filename);
    file->file = fopen(filename, "w");
    if (!file->file) {
        fprintf(stderr, "Error: could not open file %s for writing\n", filename);
        exit(1);
    }
    file->lines_written = 0;
}

void write_line(file_t *file, const char *line) {
    if (file->lines_written >= MAX_FILE_SIZE) {
        fprintf(stderr, "Error: file size limit reached\n");
        exit(1);
    }
    if (strlen(line) >= MAX_LINE_LENGTH) {
        fprintf(stderr, "Error: line length limit reached\n");
        exit(1);
    }
    if (fputs(line, file->file) == EOF) {
        fprintf(stderr, "Error: could not write line to file\n");
        exit(1);
    }
    file->lines_written++;
}

void close_file(file_t *file) {
    if (fclose(file->file) == EOF) {
        fprintf(stderr, "Error: could not close file %s\n", file->filename);
        exit(1);
    }
    free(file->filename);
    free(file);
}

void write_lines(const char *filename, const char *lines[], size_t num_lines) {
    file_t file;
    init_file(&file, filename);
    for (size_t i = 0; i < num_lines; i++) {
        write_line(&file, lines[i]);
    }
    close_file(&file);
}

int main() {
    const char *lines[] = {"Hello, world!", "This is a test.", "12345678901234567890"};
    size_t num_lines = sizeof(lines) / sizeof(lines[0]);
    write_lines("test.txt", lines, num_lines);
    return 0;
}