//Falcon-180B DATASET v1.0 Category: File handling ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    FILE* file;
} FILE_HANDLE;

FILE_HANDLE* open_file(char* filename) {
    FILE_HANDLE* handle = malloc(sizeof(FILE_HANDLE));
    if (handle == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    strcpy(handle->name, filename);
    handle->file = fopen(filename, "r");
    if (handle->file == NULL) {
        printf("Error: File not found\n");
        exit(2);
    }
    return handle;
}

int close_file(FILE_HANDLE* handle) {
    int ret = fclose(handle->file);
    free(handle);
    return ret;
}

int read_file(FILE_HANDLE* handle, char* buffer) {
    int ret = fscanf(handle->file, "%s", buffer);
    if (ret == EOF) {
        printf("Error: End of file reached\n");
        exit(3);
    }
    return ret;
}

int main() {
    FILE_HANDLE* file_handle = open_file("example.txt");
    if (file_handle == NULL) {
        return 1;
    }
    char line[MAX_LINE_LENGTH];
    while (read_file(file_handle, line)!= EOF) {
        printf("%s", line);
    }
    close_file(file_handle);
    return 0;
}