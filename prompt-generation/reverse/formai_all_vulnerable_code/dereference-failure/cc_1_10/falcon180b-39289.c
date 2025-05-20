//Falcon-180B DATASET v1.0 Category: File handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 100000

typedef struct {
    char *line;
    size_t line_length;
} Line;

typedef struct {
    Line *lines;
    size_t num_lines;
} File;

File *file_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    File *file = malloc(sizeof(File));
    file->lines = NULL;
    file->num_lines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        Line *line_obj = malloc(sizeof(Line));
        line_obj->line = strdup(line);
        line_obj->line_length = strlen(line_obj->line);
        file->lines = realloc(file->lines, sizeof(Line) * (file->num_lines + 1));
        file->lines[file->num_lines] = *line_obj;
        file->num_lines++;
    }

    fclose(fp);
    return file;
}

void file_print(const File *file) {
    for (size_t i = 0; i < file->num_lines; i++) {
        printf("%s", file->lines[i].line);
    }
}

void file_close(File *file) {
    for (size_t i = 0; i < file->num_lines; i++) {
        free(file->lines[i].line);
    }
    free(file->lines);
    free(file);
}

int main() {
    File *file = file_open("example.txt");
    file_print(file);
    file_close(file);

    return 0;
}