//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>
#include <stdint.h>
#include <inttypes.h>

// Function to extract metadata from a file
int extract_metadata(const char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    // Get the file size
    struct stat st;
    if (stat(filename, &st) == -1) {
        perror("stat");
        return -1;
    }
    size_t file_size = st.st_size;

    // Allocate memory for the file data
    char *file_data = malloc(file_size);
    if (file_data == NULL) {
        perror("malloc");
        return -1;
    }

    // Read the file data into memory
    if (fread(file_data, file_size, 1, fp) != 1) {
        perror("fread");
        return -1;
    }

    // Close the file
    fclose(fp);

    // Extract the metadata
    char *metadata = NULL;
    size_t metadata_size = 0;

    // Find the start of the metadata
    char *start_marker = strstr(file_data, "<!--METADATA_START-->");
    if (start_marker == NULL) {
        fprintf(stderr, "No metadata found in file.\n");
        return -1;
    }

    // Find the end of the metadata
    char *end_marker = strstr(file_data, "<!--METADATA_END-->");
    if (end_marker == NULL) {
        fprintf(stderr, "No metadata found in file.\n");
        return -1;
    }

    // Extract the metadata
    metadata_size = end_marker - start_marker - strlen("<!--METADATA_START-->");
    metadata = malloc(metadata_size + 1);
    if (metadata == NULL) {
        perror("malloc");
        return -1;
    }
    memcpy(metadata, start_marker + strlen("<!--METADATA_START-->"), metadata_size);
    metadata[metadata_size] = '\0';

    // Print the metadata
    printf("Metadata:\n%s\n", metadata);

    // Free the memory
    free(file_data);
    free(metadata);

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check the command-line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    // Extract the metadata from the file
    int result = extract_metadata(argv[1]);
    if (result != 0) {
        return result;
    }

    return 0;
}