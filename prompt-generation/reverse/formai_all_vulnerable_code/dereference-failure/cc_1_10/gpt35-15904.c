//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if the user has provided a file path
    if (argc != 2) {
        printf("Please provide a file path as an argument.\n");
        return 1;
    }

    // Open the file in read-only mode
    FILE *input_file = fopen(argv[1], "r");

    // Check if the file exists and can be opened
    if (input_file == NULL) {
        printf("Failed to open file %s.\n", argv[1]);
        return 1;
    }

    // Seek to the end of the file to get its size
    fseek(input_file, 0L, SEEK_END);
    long file_size = ftell(input_file);

    // Seek back to the beginning of the file
    fseek(input_file, 0L, SEEK_SET);

    // Allocate a buffer to hold the file contents
    char *buffer = (char *)malloc(file_size);

    // Read the entire file into the buffer
    size_t bytes_read = fread(buffer, 1, file_size, input_file);

    // Check if the file was read successfully
    if (bytes_read != file_size) {
        printf("Failed to read file %s.\n", argv[1]);
        return 1;
    }

    // Close the input file
    fclose(input_file);

    // Look for metadata in the buffer
    char *metadata = strstr(buffer, "Metadata:");

    // Check if metadata was found
    if (metadata == NULL) {
        printf("No metadata found in file %s.\n", argv[1]);
        return 0;
    }

    // Print the metadata and its length
    printf("Metadata: %s\n", metadata);
    printf("Metadata length: %ld\n", strlen(metadata));

    // Free the buffer
    free(buffer);

    return 0;
}