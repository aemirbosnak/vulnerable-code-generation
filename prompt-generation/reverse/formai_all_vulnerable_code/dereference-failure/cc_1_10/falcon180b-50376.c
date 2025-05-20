//Falcon-180B DATASET v1.0 Category: File handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char *filename;
    FILE *fp;
} FILE_HANDLE;

void open_file(FILE_HANDLE *file_handle, char *filename) {
    file_handle->fp = fopen(filename, "r");
    if (file_handle->fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    file_handle->filename = strdup(filename);
}

void close_file(FILE_HANDLE *file_handle) {
    if (file_handle->fp!= NULL) {
        fclose(file_handle->fp);
        free(file_handle->filename);
    }
}

char *read_line(FILE_HANDLE *file_handle) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (file_handle->fp == NULL) {
        return NULL;
    }

    line = malloc(MAX_LINE_SIZE);
    if (line == NULL) {
        printf("Error allocating memory for line\n");
        exit(1);
    }

    read = getline(&line, &len, file_handle->fp);
    if (read < 0) {
        printf("Error reading line\n");
        exit(1);
    }

    line[read] = '\0';
    return line;
}

int main() {
    FILE_HANDLE file_handle;
    char *filename = "example.txt";
    char *line;

    open_file(&file_handle, filename);

    while ((line = read_line(&file_handle))!= NULL) {
        printf("Line: %s\n", line);
    }

    close_file(&file_handle);

    return 0;
}