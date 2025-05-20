//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100

void read_file(const char* filename, char* buffer, size_t size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file '%s'.\n", filename);
        exit(1);
    }

    size_t bytes_read = fread(buffer, 1, size, file);
    if (bytes_read < size) {
        printf("Error reading from file '%s'.\n", filename);
        exit(1);
    }

    fclose(file);
}

void write_file(const char* filename, const char* buffer, size_t size) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file '%s'.\n", filename);
        exit(1);
    }

    size_t bytes_written = fwrite(buffer, 1, size, file);
    if (bytes_written!= size) {
        printf("Error writing to file '%s'.\n", filename);
        exit(1);
    }

    fclose(file);
}

void synchronize_files(const char* source, const char* destination, const char* output) {
    char source_buffer[MAX_LINE_LEN];
    char destination_buffer[MAX_LINE_LEN];
    char output_buffer[MAX_LINE_LEN];

    read_file(source, source_buffer, MAX_LINE_LEN);
    read_file(destination, destination_buffer, MAX_LINE_LEN);

    if (strncmp(source_buffer, destination_buffer, MAX_LINE_LEN)!= 0) {
        printf("Files are not synchronized.\n");
        exit(1);
    }

    write_file(output, source_buffer, MAX_LINE_LEN);
    printf("Files synchronized successfully.\n");
}

int main() {
    const char* source = "source.txt";
    const char* destination = "destination.txt";
    const char* output = "output.txt";

    synchronize_files(source, destination, output);

    return 0;
}