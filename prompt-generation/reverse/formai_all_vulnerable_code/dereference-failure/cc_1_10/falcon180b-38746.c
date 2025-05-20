//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a filename
#define MAX_FILENAME_LENGTH 256

// Define the metadata structure
typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int file_size;
    char file_type[MAX_FILENAME_LENGTH];
} Metadata;

// Function to extract metadata from a file
void extract_metadata(Metadata *metadata, const char *filename) {
    FILE *fp;
    char magic_buffer[4];

    // Open the file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Read the magic number
    fread(magic_buffer, 1, 4, fp);

    // Determine the file type based on the magic number
    if (strcmp(magic_buffer, "GIF8") == 0) {
        strcpy(metadata->file_type, "GIF");
    } else if (strcmp(magic_buffer, "PNG") == 0) {
        strcpy(metadata->file_type, "PNG");
    } else if (strcmp(magic_buffer, "JFIF") == 0) {
        strcpy(metadata->file_type, "JPEG");
    } else {
        strcpy(metadata->file_type, "Unknown");
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    metadata->file_size = ftell(fp);

    // Close the file
    fclose(fp);

    // Copy the filename
    strcpy(metadata->filename, filename);
}

// Function to print metadata
void print_metadata(const Metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("File size: %d bytes\n", metadata->file_size);
    printf("File type: %s\n", metadata->file_type);
}

// Main function
int main(int argc, char *argv[]) {
    Metadata metadata;

    // Check if the correct number of arguments was provided
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    // Extract metadata from the file
    extract_metadata(&metadata, argv[1]);

    // Print metadata
    printf("Metadata for file %s:\n", argv[1]);
    print_metadata(&metadata);

    return 0;
}