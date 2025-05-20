//FormAI DATASET v1.0 Category: File Encyptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1048576 // 1 MB

int main(int argc, char *argv[]) {
    if (argc < 3) {
        // Check if the user has provided file input and output paths
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    char input_file_path[256], output_file_path[256];
    strcpy(input_file_path, argv[1]);
    strcpy(output_file_path, argv[2]);

    FILE *input_file, *output_file;

    // Open the input file in binary read mode
    if ((input_file = fopen(input_file_path, "rb")) == NULL) {
        printf("Unable to open the input file.\n");
        exit(1);
    }

    // Open the output file in binary write mode
    if ((output_file = fopen(output_file_path, "wb")) == NULL) {
        printf("Unable to open the output file.\n");
        exit(1);
    }

    // Read the content of the input file into a buffer
    unsigned char *buffer = malloc(MAX_FILE_SIZE);
    size_t bytes_read = fread(buffer, sizeof(unsigned char), MAX_FILE_SIZE, input_file) * sizeof(unsigned char);

    // Loop through the buffer and XOR each byte with a key
    unsigned char key = 0xFF;
    for (size_t i = 0; i < bytes_read; i++) {
        buffer[i] ^= key;
    }

    // Write the encrypted content to the output file
    fwrite(buffer, sizeof(unsigned char), bytes_read, output_file);

    // Close both files and free the memory allocated for the buffer
    fclose(input_file);
    fclose(output_file);
    free(buffer);

    printf("File encryption completed successfully.\n");

    return 0;
}