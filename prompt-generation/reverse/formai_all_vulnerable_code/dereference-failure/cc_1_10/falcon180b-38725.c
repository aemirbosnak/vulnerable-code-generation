//Falcon-180B DATASET v1.0 Category: File handling ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FILE_NAME_LEN 100

typedef struct {
    char filename[MAX_FILE_NAME_LEN];
    FILE *fp;
} FILE_HANDLE;

FILE_HANDLE *open_file(char *filename, char *mode) {
    FILE_HANDLE *handle = (FILE_HANDLE *)malloc(sizeof(FILE_HANDLE));
    strcpy(handle->filename, filename);
    handle->fp = fopen(filename, mode);
    if (handle->fp == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        exit(1);
    }
    return handle;
}

int read_line(FILE_HANDLE *handle, char *buffer, int max_size) {
    char c;
    int count = 0;
    while ((c = fgetc(handle->fp))!= EOF) {
        if (count >= max_size - 1) {
            printf("Error: Line too long\n");
            exit(1);
        }
        buffer[count++] = c;
    }
    if (count == 0) {
        printf("Error: Empty line\n");
        exit(1);
    }
    buffer[count] = '\0';
    return count;
}

int write_line(FILE_HANDLE *handle, char *buffer) {
    return fputs(buffer, handle->fp);
}

void close_file(FILE_HANDLE *handle) {
    fclose(handle->fp);
    free(handle);
}

int main() {
    FILE_HANDLE *input_file, *output_file;
    char filename[MAX_FILE_NAME_LEN];
    char buffer[MAX_LINE_SIZE];
    int count;

    printf("Enter input file name: ");
    scanf("%s", filename);
    input_file = open_file(filename, "r");

    printf("Enter output file name: ");
    scanf("%s", filename);
    output_file = open_file(filename, "w");

    while ((count = read_line(input_file, buffer, MAX_LINE_SIZE)) > 0) {
        write_line(output_file, buffer);
    }

    close_file(input_file);
    close_file(output_file);

    printf("File copy successful!\n");
    return 0;
}