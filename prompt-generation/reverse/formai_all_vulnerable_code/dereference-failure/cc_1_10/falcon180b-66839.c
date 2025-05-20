//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold metadata information
typedef struct {
    char* filename;
    int filesize;
    char* filetype;
} metadata;

// Function to extract metadata from a file
metadata get_metadata(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    metadata metadata;
    metadata.filename = filename;
    metadata.filesize = 0;
    metadata.filetype = "unknown";
    fseek(file, 0, SEEK_END);
    metadata.filesize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char magic[4];
    fread(magic, 1, 4, file);
    if (strcmp(magic, "GIF8") == 0) {
        metadata.filetype = "GIF";
    } else if (strcmp(magic, "JFIF") == 0) {
        metadata.filetype = "JPEG";
    } else if (strcmp(magic, "BM") == 0) {
        metadata.filetype = "BMP";
    } else if (strcmp(magic, "PNG") == 0) {
        metadata.filetype = "PNG";
    } else {
        metadata.filetype = "unknown";
    }
    fclose(file);
    return metadata;
}

// Function to print metadata
void print_metadata(metadata metadata) {
    printf("Filename: %s\n", metadata.filename);
    printf("File size: %d bytes\n", metadata.filesize);
    printf("File type: %s\n", metadata.filetype);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    metadata metadata = get_metadata(argv[1]);
    print_metadata(metadata);
    return 0;
}