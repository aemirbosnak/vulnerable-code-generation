//Falcon-180B DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *data;
    size_t length;
} String;

typedef struct {
    String *lines;
    size_t num_lines;
} File;

int read_file(const char *filename, File *file) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    size_t num_lines = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        String *new_line = malloc(sizeof(String));
        new_line->data = strdup(line);
        new_line->length = strlen(line);
        file->lines = realloc(file->lines, sizeof(String) * (num_lines + 1));
        file->lines[num_lines] = *new_line;
        file->num_lines++;
        num_lines++;
    }

    fclose(fp);
    return 0;
}

int write_file(const char *filename, File *file) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file '%s' for writing\n", filename);
        return 1;
    }

    for (size_t i = 0; i < file->num_lines; i++) {
        fprintf(fp, "%s", file->lines[i].data);
    }

    fclose(fp);
    return 0;
}

int main() {
    File file;

    if (read_file("input.txt", &file)!= 0) {
        return 1;
    }

    String *line = malloc(sizeof(String));
    line->data = strdup("This is a new line of text.");
    line->length = strlen(line->data);
    file.lines = realloc(file.lines, sizeof(String) * (file.num_lines + 1));
    file.lines[file.num_lines] = *line;
    file.num_lines++;

    if (write_file("output.txt", &file)!= 0) {
        return 1;
    }

    for (size_t i = 0; i < file.num_lines; i++) {
        printf("%s", file.lines[i].data);
    }

    for (size_t i = 0; i < file.num_lines; i++) {
        free(file.lines[i].data);
    }
    free(file.lines);

    return 0;
}