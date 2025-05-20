//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 100 // 100 MB

// Function to read a file into memory
void read_file(const char* filename, char* buffer) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File is too large (%ld bytes)\n", file_size);
        exit(1);
    }

    fread(buffer, file_size, 1, file);
    fclose(file);
}

// Function to write a buffer to a file
void write_file(const char* filename, const char* buffer, long file_size) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Error: Could not create file '%s'\n", filename);
        exit(1);
    }

    fwrite(buffer, file_size, 1, file);
    fclose(file);
}

// Function to recover deleted data from a file
void recover_data(const char* filename) {
    char buffer[MAX_FILE_SIZE];
    read_file(filename, buffer);

    long file_size = strlen(buffer);
    char* new_buffer = malloc(file_size + 1);
    strcpy(new_buffer, buffer);

    printf("Recovered data:\n%s\n", new_buffer);

    write_file(filename, new_buffer, file_size);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    const char* filename = argv[1];
    recover_data(filename);

    return 0;
}