//Falcon-180B DATASET v1.0 Category: File handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char *filename;
    FILE *file;
    size_t size;
} File;

void init_file(File *file, const char *filename) {
    file->filename = strdup(filename);
    file->file = fopen(filename, "r");
    file->size = 0;
}

void destroy_file(File *file) {
    if (file->filename) {
        free(file->filename);
        file->filename = NULL;
    }
    if (file->file) {
        fclose(file->file);
        file->file = NULL;
    }
}

int read_line(File *file, char *buffer, size_t max_size) {
    char *line = NULL;
    size_t line_size = 0;

    while (fgets(line, MAX_LINE_SIZE, file->file)!= NULL) {
        if (line_size + strlen(line) + 1 > max_size) {
            break;
        }
        strcat(buffer, line);
        buffer[strlen(buffer) - 1] = '\n';
        line_size += strlen(line);
        line = NULL;
    }

    return line_size;
}

int main() {
    File file;
    char buffer[MAX_FILE_SIZE];
    size_t line_size;

    init_file(&file, "test.txt");

    while ((line_size = read_line(&file, buffer, MAX_FILE_SIZE - 1)) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, MAX_FILE_SIZE);
    }

    destroy_file(&file);

    return 0;
}