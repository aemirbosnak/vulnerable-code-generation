//Falcon-180B DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_STRING_LENGTH 1024

typedef struct {
    char *filename;
    FILE *file;
    bool is_open;
} File;

void file_open(File *file, const char *filename) {
    if (file->is_open) {
        fclose(file->file);
    }
    file->filename = strdup(filename);
    file->file = fopen(file->filename, "r");
    if (file->file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }
    file->is_open = true;
}

void file_close(File *file) {
    if (file->is_open) {
        fclose(file->file);
        free(file->filename);
        file->filename = NULL;
        file->is_open = false;
    }
}

char *file_read_line(File *file) {
    char *line = NULL;
    size_t line_length = 0;
    char *buffer = NULL;

    if (file->is_open) {
        buffer = malloc(MAX_LINE_LENGTH);
        if (buffer == NULL) {
            printf("Error: Could not allocate memory for line buffer\n");
            exit(1);
        }
        while (fgets(buffer, MAX_LINE_LENGTH, file->file)!= NULL) {
            line_length = strlen(buffer);
            if (buffer[line_length - 1] == '\n') {
                buffer[line_length - 1] = '\0';
            }
            line = strdup(buffer);
            break;
        }
        free(buffer);
    }

    return line;
}

bool file_write_line(File *file, const char *line) {
    if (file->is_open) {
        return fputs(line, file->file)!= EOF;
    }
    return false;
}

int main() {
    File my_file;
    char *filename = "example.txt";
    char *line = NULL;

    file_open(&my_file, filename);

    while ((line = file_read_line(&my_file))!= NULL) {
        printf("%s", line);
    }

    file_close(&my_file);

    return 0;
}