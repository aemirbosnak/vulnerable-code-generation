//Falcon-180B DATASET v1.0 Category: File handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// File handling functions
#define MAX_FILE_NAME 256
#define MAX_LINE_SIZE 1024

typedef struct {
    char *file_name;
    FILE *file_pointer;
} FILE_HANDLE;

FILE_HANDLE *open_file(char *file_name, char *mode) {
    FILE_HANDLE *file_handle = (FILE_HANDLE *) malloc(sizeof(FILE_HANDLE));
    strcpy(file_handle->file_name, file_name);
    file_handle->file_pointer = fopen(file_name, mode);
    if (file_handle->file_pointer == NULL) {
        printf("Error: File %s could not be opened\n", file_name);
        exit(1);
    }
    return file_handle;
}

void close_file(FILE_HANDLE *file_handle) {
    fclose(file_handle->file_pointer);
    free(file_handle);
}

char *read_line(FILE_HANDLE *file_handle) {
    char *line = (char *) malloc(MAX_LINE_SIZE * sizeof(char));
    fgets(line, MAX_LINE_SIZE, file_handle->file_pointer);
    return line;
}

bool write_line(FILE_HANDLE *file_handle, char *line) {
    return fputs(line, file_handle->file_pointer)!= EOF;
}

int main() {
    FILE_HANDLE *file_handle = open_file("example.txt", "r");
    char *line = read_line(file_handle);
    while (line!= NULL) {
        printf("%s", line);
        line = read_line(file_handle);
    }
    close_file(file_handle);
    return 0;
}