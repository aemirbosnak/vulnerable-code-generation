//Falcon-180B DATASET v1.0 Category: File handling ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 4096

typedef struct {
    char *filename;
    FILE *file;
    char *mode;
} FILE_HANDLE;

FILE_HANDLE *open_file(const char *filename, const char *mode) {
    FILE_HANDLE *handle = (FILE_HANDLE*) malloc(sizeof(FILE_HANDLE));
    handle->filename = strdup(filename);
    handle->file = fopen(filename, mode);
    handle->mode = strdup(mode);

    if (handle->file == NULL) {
        fprintf(stderr, "Error opening file '%s' in mode '%s'\n", filename, mode);
        exit(1);
    }

    return handle;
}

void close_file(FILE_HANDLE *handle) {
    fclose(handle->file);
    free(handle->filename);
    free(handle->mode);
    free(handle);
}

char *read_line(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    line = malloc(MAX_LINE_SIZE);
    if (line == NULL) {
        fprintf(stderr, "Error allocating memory for line\n");
        exit(1);
    }

    read = getline(&line, &len, file);
    if (read == -1) {
        fprintf(stderr, "Error reading line from file\n");
        exit(1);
    }

    line[read] = '\0';
    return line;
}

void write_line(FILE *file, const char *line) {
    fprintf(file, "%s", line);
}

int main() {
    FILE_HANDLE *in_handle = open_file("input.txt", "r");
    FILE_HANDLE *out_handle = open_file("output.txt", "w");

    char *line;

    while ((line = read_line(in_handle->file))!= NULL) {
        line[strcspn(line, "\r\n")] = '\0'; // Remove newline characters
        write_line(out_handle->file, line);
    }

    close_file(in_handle);
    close_file(out_handle);

    return 0;
}