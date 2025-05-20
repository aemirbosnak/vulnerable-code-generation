//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold metadata information
typedef struct {
    char *filename;
    int filesize;
    char *filetype;
    char *filepath;
} Metadata;

// Function to extract metadata from a file
void extractMetadata(char *filename, Metadata *metadata) {
    FILE *fp;
    char buffer[1024];
    char *extension = strrchr(filename, '.');

    // Open the file for reading
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Read the file contents into a buffer
    fseek(fp, 0, SEEK_END);
    metadata->filesize = ftell(fp);
    rewind(fp);
    fread(buffer, metadata->filesize, 1, fp);
    fclose(fp);

    // Determine the file type based on the extension
    if (extension == NULL) {
        metadata->filetype = "Unknown";
    } else {
        metadata->filetype = strdup(extension);
    }

    // Set the filename and filepath
    metadata->filename = strdup(filename);
    metadata->filepath = strdup(dirname(filename));
}

// Function to print metadata information
void printMetadata(Metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("File Size: %d bytes\n", metadata->filesize);
    printf("File Type: %s\n", metadata->filetype);
    printf("File Path: %s\n", metadata->filepath);
}

// Main function to run the program
int main(int argc, char *argv[]) {
    Metadata metadata;

    // Check if the correct number of arguments were provided
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    // Extract metadata from the file
    extractMetadata(argv[1], &metadata);

    // Print the metadata information
    printMetadata(&metadata);

    // Free the memory allocated for metadata
    free(metadata.filename);
    free(metadata.filetype);
    free(metadata.filepath);

    return 0;
}