//Falcon-180B DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    FILE *file;
    char *filename;
    int line_number;
} File;

void init_file(File *file, const char *filename) {
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    file->filename = strdup(filename);
    file->line_number = 0;
}

char *read_line(File *file) {
    char *line = NULL;
    size_t length = 0;
    ssize_t bytes_read;

    bytes_read = getline(&line, &length, file->file);
    if (bytes_read == -1) {
        if (ferror(file->file)) {
            printf("Error reading file: %s\n", strerror(ferror(file->file)));
            exit(1);
        } else {
            return NULL;
        }
    }

    line[bytes_read - 1] = '\0';
    file->line_number++;

    return line;
}

void print_line(const char *line) {
    printf("%4d: %s", strlen(line), line);
}

void print_file(const File *file) {
    char *line;

    while ((line = read_line(file))!= NULL) {
        print_line(line);
    }
}

void close_file(File *file) {
    if (file->filename!= NULL) {
        free(file->filename);
    }

    if (file->file!= NULL) {
        fclose(file->file);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    File file;
    init_file(&file, argv[1]);
    print_file(&file);
    close_file(&file);

    return 0;
}