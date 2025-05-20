//Falcon-180B DATASET v1.0 Category: File handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *file;
} File;

File* file_open(char *filename) {
    File *file = malloc(sizeof(File));
    file->filename = strdup(filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }
    return file;
}

void file_close(File *file) {
    fclose(file->file);
    free(file->filename);
    free(file);
}

char* file_read_line(File *file) {
    char *line = NULL;
    size_t capacity = 0;
    ssize_t read;

    while ((read = getline(&line, &capacity, file->file))!= -1) {
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
            break;
        } else if (read == capacity - 1) {
            capacity += MAX_LINE_LENGTH;
            line = realloc(line, capacity);
        }
    }

    return line;
}

int main() {
    File *file = file_open("example.txt");

    char *line = NULL;
    while ((line = file_read_line(file))!= NULL) {
        printf("Line: %s\n", line);
    }

    file_close(file);
    return 0;
}