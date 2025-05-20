//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold metadata information
typedef struct {
    char *filename;
    int filesize;
    char *filetype;
} Metadata;

// Function to extract metadata from a file
Metadata extractMetadata(char *filename) {
    FILE *file;
    Metadata metadata;
    char magic[4];

    // Open the file in binary mode
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    // Read the file header to determine file type
    fread(magic, 1, 4, file);
    if (strcmp(magic, "GIF8") == 0) {
        metadata.filetype = "GIF";
    } else if (strcmp(magic, "JFIF") == 0) {
        metadata.filetype = "JPEG";
    } else if (strcmp(magic, "BM") == 0) {
        metadata.filetype = "BMP";
    } else {
        metadata.filetype = "Unknown";
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    metadata.filesize = ftell(file);

    // Close the file
    fclose(file);

    // Allocate memory for the filename string
    metadata.filename = malloc(strlen(filename) + 1);
    if (metadata.filename == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    // Copy the filename to the metadata struct
    strcpy(metadata.filename, filename);

    return metadata;
}

// Function to print metadata information
void printMetadata(Metadata metadata) {
    printf("Filename: %s\n", metadata.filename);
    printf("File size: %d bytes\n", metadata.filesize);
    printf("File type: %s\n", metadata.filetype);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Metadata metadata = extractMetadata(argv[1]);
    printMetadata(metadata);

    free(metadata.filename);
    return 0;
}