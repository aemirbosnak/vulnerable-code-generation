//Falcon-180B DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *file;
} File;

void file_open(File *file, const char *filename) {
    file->filename = strdup(filename);
    file->file = fopen(filename, "r");

    if (file->file == NULL) {
        printf("Error: Failed to open file '%s'\n", filename);
        exit(1);
    }
}

void file_close(File *file) {
    if (file->file!= NULL) {
        fclose(file->file);
        file->file = NULL;
    }

    free(file->filename);
    file->filename = NULL;
}

char *file_read_line(File *file) {
    char *line = NULL;
    size_t line_length = 0;

    if (file->file!= NULL) {
        line = malloc(MAX_LINE_LENGTH);
        fgets(line, MAX_LINE_LENGTH, file->file);
        line_length = strlen(line);

        if (line_length > 0 && line[line_length - 1] == '\n') {
            line[--line_length] = '\0';
        }
    }

    return line;
}

int main() {
    File file;
    char *line;

    file_open(&file, "example.txt");

    while ((line = file_read_line(&file))!= NULL) {
        printf("%s", line);
    }

    file_close(&file);

    return 0;
}