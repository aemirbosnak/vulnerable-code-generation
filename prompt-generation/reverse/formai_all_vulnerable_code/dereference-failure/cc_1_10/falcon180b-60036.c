//Falcon-180B DATASET v1.0 Category: File handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *file;
} File;

void init_file(File *file, const char *filename) {
    file->filename = strdup(filename);
    file->file = fopen(file->filename, "r");
    if (!file->file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
}

void close_file(File *file) {
    if (file->file) {
        fclose(file->file);
        free(file->filename);
    }
}

char *read_line(File *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (file->file) {
        getline(&line, &len, file->file);
        if (line && line[strlen(line) - 1] == '\n') {
            line[--len] = '\0';
        }
    }

    return line;
}

int main() {
    File file;
    char *line;
    int count = 0;

    init_file(&file, "input.txt");

    while ((line = read_line(&file))) {
        printf("%d: %s", ++count, line);
    }

    close_file(&file);

    return 0;
}