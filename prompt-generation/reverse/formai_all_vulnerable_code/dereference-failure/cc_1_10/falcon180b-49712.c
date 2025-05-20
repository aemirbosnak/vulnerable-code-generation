//Falcon-180B DATASET v1.0 Category: File handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE *file_ptr;
} FILE_HANDLE;

FILE_HANDLE open_file(char *file_name, char *mode) {
    FILE_HANDLE file_handle;
    strcpy(file_handle.file_name, file_name);
    file_handle.file_ptr = fopen(file_name, mode);
    if (file_handle.file_ptr == NULL) {
        printf("Error opening file %s\n", file_name);
        exit(1);
    }
    return file_handle;
}

int read_line(FILE_HANDLE file_handle, char *buffer) {
    int bytes_read = 0;
    char ch;
    while ((ch = fgetc(file_handle.file_ptr))!= EOF) {
        if (bytes_read >= MAX_LINE_LENGTH) {
            printf("Error: Line too long\n");
            exit(1);
        }
        buffer[bytes_read++] = ch;
    }
    if (bytes_read == 0) {
        printf("Error: Empty line\n");
        exit(1);
    }
    buffer[bytes_read] = '\0';
    return bytes_read;
}

void close_file(FILE_HANDLE file_handle) {
    if (fclose(file_handle.file_ptr)!= 0) {
        printf("Error closing file %s\n", file_handle.file_name);
        exit(1);
    }
}

int main() {
    FILE_HANDLE input_file;
    FILE_HANDLE output_file;
    char input_buffer[MAX_LINE_LENGTH];
    char output_buffer[MAX_LINE_LENGTH];
    char input_file_name[MAX_FILE_NAME_LENGTH];
    char output_file_name[MAX_FILE_NAME_LENGTH];

    printf("Enter input file name: ");
    scanf("%s", input_file_name);
    input_file = open_file(input_file_name, "r");

    printf("Enter output file name: ");
    scanf("%s", output_file_name);
    output_file = open_file(output_file_name, "w");

    while (read_line(input_file, input_buffer) > 0) {
        int bytes_written = 0;
        while (bytes_written < strlen(input_buffer)) {
            if (bytes_written >= MAX_LINE_LENGTH) {
                printf("Error: Line too long\n");
                exit(1);
            }
            output_buffer[bytes_written++] = toupper(input_buffer[bytes_written]);
        }
        output_buffer[bytes_written] = '\0';
        if (fputs(output_buffer, output_file.file_ptr) == EOF) {
            printf("Error writing to file %s\n", output_file_name);
            exit(1);
        }
    }

    close_file(input_file);
    close_file(output_file);

    printf("Conversion complete!\n");
    return 0;
}