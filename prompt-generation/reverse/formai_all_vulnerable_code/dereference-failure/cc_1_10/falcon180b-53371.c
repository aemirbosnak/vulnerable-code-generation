//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_SIZE 500000000 // 500 MB

// Function to read a file into memory
void read_file(FILE* fp, char* buffer) {
    fseek(fp, 0L, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File size exceeds maximum allowed limit.\n");
        exit(1);
    }

    fread(buffer, file_size, 1, fp);
}

// Function to write a buffer to a new file
void write_file(char* buffer, int buffer_size, char* output_file) {
    FILE* output = fopen(output_file, "wb");

    if (output == NULL) {
        printf("Error: Unable to create output file.\n");
        exit(1);
    }

    fwrite(buffer, buffer_size, 1, output);
    fclose(output);
}

// Function to check if a buffer contains valid data
bool is_valid_data(char* buffer, int buffer_size) {
    for (int i = 0; i < buffer_size; i++) {
        if (buffer[i] == 0) {
            return false;
        }
    }

    return true;
}

// Main function
int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    char input_file[256];
    strcpy(input_file, argv[1]);

    char output_file[256];
    strcpy(output_file, argv[2]);

    FILE* input = fopen(input_file, "rb");

    if (input == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    char* buffer = malloc(MAX_FILE_SIZE);
    read_file(input, buffer);
    fclose(input);

    if (!is_valid_data(buffer, strlen(buffer))) {
        printf("Error: Input file contains invalid data.\n");
        exit(1);
    }

    write_file(buffer, strlen(buffer), output_file);
    free(buffer);

    printf("File recovery successful!\n");
    return 0;
}