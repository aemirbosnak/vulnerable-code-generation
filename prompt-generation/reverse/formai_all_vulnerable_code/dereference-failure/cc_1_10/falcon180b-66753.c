//Falcon-180B DATASET v1.0 Category: File handling ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *fp;
} file_t;

file_t *file_open(const char *filename) {
    file_t *file = malloc(sizeof(file_t));
    file->filename = strdup(filename);
    file->fp = fopen(filename, "r");
    if (file->fp == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        exit(1);
    }
    return file;
}

void file_close(file_t *file) {
    fclose(file->fp);
    free(file->filename);
    free(file);
}

char *file_read_line(file_t *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    char *ptr = line;
    int c;

    while ((c = fgetc(file->fp))!= EOF) {
        if (isspace(c)) {
            *ptr = '\0';
            break;
        }
        if (ptr - line >= MAX_LINE_LENGTH - 1) {
            *ptr = '\0';
            fprintf(stderr, "Line too long: %s\n", line);
            exit(1);
        }
        *ptr++ = c;
    }

    return line;
}

int main() {
    file_t *file = file_open("example.txt");

    char *line;
    while ((line = file_read_line(file))!= NULL) {
        printf("%s", line);
        free(line);
    }

    file_close(file);
    return 0;
}