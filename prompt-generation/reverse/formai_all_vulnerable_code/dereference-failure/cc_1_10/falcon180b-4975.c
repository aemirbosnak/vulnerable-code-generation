//Falcon-180B DATASET v1.0 Category: File handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *file;
} File;

void open_file(File *file, const char *filename) {
    file->filename = strdup(filename); // make a copy of the filename
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        exit(1);
    }
}

void close_file(File *file) {
    fclose(file->file);
    free(file->filename);
}

int read_line(File *file, char *buffer, size_t size) {
    char *line = NULL;
    size_t len = 0;
    ssize_t bytes_read;

    while ((bytes_read = getline(&line, &len, file->file))!= -1) {
        if (bytes_read >= size) {
            fprintf(stderr, "Line too long\n");
            exit(1);
        }
        strncpy(buffer, line, bytes_read);
        buffer[bytes_read] = '\0';
        return bytes_read;
    }

    if (bytes_read == -1) {
        if (ferror(file->file)) {
            fprintf(stderr, "Error reading file '%s'\n", file->filename);
            exit(1);
        }
    }

    return 0;
}

void process_file(File *file) {
    char buffer[MAX_LINE_LENGTH];
    size_t bytes_read;

    while ((bytes_read = read_line(file, buffer, MAX_LINE_LENGTH)) > 0) {
        // do something with the line
        printf("Line: %s\n", buffer);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    File file;
    open_file(&file, argv[1]);
    process_file(&file);
    close_file(&file);

    return 0;
}