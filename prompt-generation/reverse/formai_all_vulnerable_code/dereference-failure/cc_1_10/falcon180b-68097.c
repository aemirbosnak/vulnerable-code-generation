//Falcon-180B DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 256
#define MAX_FILE_NAME_SIZE 100

typedef struct {
    char file_name[MAX_FILE_NAME_SIZE];
    FILE *file_pointer;
} FILE_HANDLE;

FILE_HANDLE *open_file(char *file_name) {
    FILE_HANDLE *file_handle = (FILE_HANDLE *) malloc(sizeof(FILE_HANDLE));
    strcpy(file_handle->file_name, file_name);
    file_handle->file_pointer = fopen(file_name, "r");
    if (file_handle->file_pointer == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    return file_handle;
}

int close_file(FILE_HANDLE *file_handle) {
    int ret_val = fclose(file_handle->file_pointer);
    free(file_handle);
    return ret_val;
}

int read_line(FILE_HANDLE *file_handle, char *buffer, int buffer_size) {
    char line[MAX_LINE_SIZE];
    int line_len = 0;
    while (fgets(line, MAX_LINE_SIZE, file_handle->file_pointer)!= NULL) {
        if (line_len >= buffer_size) {
            printf("Error: Line too long.\n");
            exit(1);
        }
        strncat(buffer, line, buffer_size - line_len);
        line_len += strlen(line);
        if (line[strlen(line) - 1]!= '\n') {
            printf("Error: Line too long.\n");
            exit(1);
        }
    }
    return line_len;
}

int main() {
    FILE_HANDLE *file_handle = open_file("example.txt");
    char buffer[MAX_LINE_SIZE];
    int line_len;
    while ((line_len = read_line(file_handle, buffer, MAX_LINE_SIZE)) > 0) {
        printf("%s", buffer);
    }
    close_file(file_handle);
    return 0;
}