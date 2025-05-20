//Falcon-180B DATASET v1.0 Category: File handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *fp;
} File;

void open_file(File *file, const char *filename) {
    file->filename = strdup(filename);
    file->fp = fopen(file->filename, "r");
    if (file->fp == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        exit(1);
    }
}

void close_file(File *file) {
    if (file->fp!= NULL) {
        fclose(file->fp);
        free((void *)file->filename);
    }
}

char *read_line(File *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file->fp))!= -1) {
        if (read > 0 && line[read - 1] == '\n') {
            line[--read] = '\0';
        } else {
            line = realloc(line, read + 1);
            line[read] = '\0';
        }

        if (strlen(line) > MAX_LINE_LENGTH) {
            fprintf(stderr, "Line too long: %s\n", line);
            free(line);
            line = NULL;
            len = 0;
            break;
        }
    }

    return line;
}

int main(int argc, char *argv[]) {
    File input_file, output_file;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    open_file(&input_file, argv[1]);
    open_file(&output_file, argv[2]);

    char *line;
    while ((line = read_line(&input_file))!= NULL) {
        fprintf(output_file.fp, "%s", line);
    }

    close_file(&input_file);
    close_file(&output_file);

    return 0;
}