//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

// Function to read a file into memory
void read_file(FILE *file, char *buffer) {
    int bytes_read = 0;
    int buffer_index = 0;
    while ((bytes_read = fread(buffer + buffer_index, 1, MAX_FILE_SIZE - buffer_index, file)) > 0) {
        buffer_index += bytes_read;
    }
    buffer[buffer_index] = '\0';
}

// Function to write a buffer to a file
void write_file(FILE *file, char *buffer) {
    fwrite(buffer, strlen(buffer), 1, file);
}

// Function to compare two files and synchronize them
void synchronize_files(char *file1, char *file2) {
    FILE *file1_ptr = fopen(file1, "r");
    FILE *file2_ptr = fopen(file2, "r");
    if (file1_ptr == NULL || file2_ptr == NULL) {
        printf("Error: Could not open file(s)\n");
        return;
    }

    char buffer1[MAX_FILE_SIZE], buffer2[MAX_FILE_SIZE];
    read_file(file1_ptr, buffer1);
    read_file(file2_ptr, buffer2);

    int buffer1_index = 0, buffer2_index = 0;
    while (buffer1[buffer1_index]!= '\0' && buffer2[buffer2_index]!= '\0') {
        if (buffer1[buffer1_index] == buffer2[buffer2_index]) {
            buffer1_index++;
            buffer2_index++;
        } else {
            if (buffer1[buffer1_index] < buffer2[buffer2_index]) {
                write_file(file2_ptr, buffer1 + buffer1_index);
                buffer1_index++;
            } else {
                write_file(file1_ptr, buffer2 + buffer2_index);
                buffer2_index++;
            }
        }
    }

    if (buffer1[buffer1_index]!= '\0') {
        write_file(file2_ptr, buffer1 + buffer1_index);
    } else {
        write_file(file1_ptr, buffer2 + buffer2_index);
    }

    fclose(file1_ptr);
    fclose(file2_ptr);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        return 1;
    }

    synchronize_files(argv[1], argv[2]);

    return 0;
}