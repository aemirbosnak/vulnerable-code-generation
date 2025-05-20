//Falcon-180B DATASET v1.0 Category: File handling ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *filename;
    FILE *file;
} File;

int create_file(char *filename) {
    File *file = malloc(sizeof(File));
    if (file == NULL) {
        printf("Error: could not allocate memory for file.\n");
        return 1;
    }
    file->filename = strdup(filename);
    file->file = fopen(filename, "w");
    if (file->file == NULL) {
        printf("Error: could not create file '%s'.\n", filename);
        free(file->filename);
        free(file);
        return 1;
    }
    return 0;
}

int write_line(File *file, char *line) {
    if (fputs(line, file->file) == EOF) {
        printf("Error: could not write line to file.\n");
        fclose(file->file);
        free(file->filename);
        free(file);
        return 1;
    }
    return 0;
}

int close_file(File *file) {
    if (fclose(file->file) == EOF) {
        printf("Error: could not close file.\n");
        free(file->filename);
        free(file);
        return 1;
    }
    free(file->filename);
    free(file);
    return 0;
}

int main() {
    char input_buffer[MAX_LINE_SIZE];
    char *filename = NULL;
    File *file = NULL;

    printf("Enter filename: ");
    fgets(input_buffer, MAX_LINE_SIZE, stdin);
    filename = strtok(input_buffer, "\n");

    if (create_file(filename)) {
        return 1;
    }

    while (fgets(input_buffer, MAX_LINE_SIZE, stdin)!= NULL) {
        if (write_line(file, input_buffer)) {
            return 1;
        }
    }

    if (close_file(file)) {
        return 1;
    }

    printf("File '%s' created successfully.\n", filename);
    return 0;
}