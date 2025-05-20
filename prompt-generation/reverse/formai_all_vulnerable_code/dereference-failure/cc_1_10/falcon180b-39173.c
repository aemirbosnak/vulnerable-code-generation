//Falcon-180B DATASET v1.0 Category: File handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *file;
    int line_count;
} File;

void init_file(File *file, const char *filename) {
    file->filename = strdup(filename);
    file->file = fopen(file->filename, "r");
    if (file->file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }
    file->line_count = 0;
}

void free_file(File *file) {
    if (file->file!= NULL) {
        fclose(file->file);
    }
    free(file->filename);
    free(file);
}

char *read_line(FILE *file) {
    char *line = NULL;
    size_t capacity = 0;
    ssize_t bytes_read;

    if (getline(&line, &capacity, file) == -1) {
        if (feof(file)) {
            return NULL;
        } else {
            fprintf(stderr, "Error reading line from file\n");
            exit(1);
        }
    }

    line[strcspn(line, "\r\n")] = '\0';
    return line;
}

void print_line_numbers(File *file) {
    for (int i = 1; i <= file->line_count; i++) {
        printf("%d: ", i);
    }
    printf("\n");
}

int main() {
    File file;
    char *line;

    init_file(&file, "example.txt");

    while ((line = read_line(file.file))!= NULL) {
        printf("%s", line);
        file.line_count++;
    }

    free_file(&file);

    return 0;
}