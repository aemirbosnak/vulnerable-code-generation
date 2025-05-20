//Falcon-180B DATASET v1.0 Category: File handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *filename;
    FILE *file;
} file_t;

void open_file(file_t *file, const char *filename) {
    file->filename = strdup(filename);
    file->file = fopen(file->filename, "r");
    if (!file->file) {
        fprintf(stderr, "Error: Failed to open file '%s'\n", filename);
        exit(1);
    }
}

void close_file(file_t *file) {
    fclose(file->file);
    free(file->filename);
}

char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_SIZE);
    size_t len = fgets(line, MAX_LINE_SIZE, file);
    if (len == 0) {
        return NULL;
    }
    line[len - 1] = '\0';
    return line;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file_t file;
    open_file(&file, argv[1]);

    char *line = read_line(file.file);
    while (line!= NULL) {
        printf("%s", line);
        line = read_line(file.file);
    }

    close_file(&file);
    return 0;
}