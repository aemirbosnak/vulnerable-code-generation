//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_METADATA_LENGTH 2048

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char metadata[MAX_METADATA_LENGTH];
} FileMetadata;

FileMetadata extract_metadata(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Seek to the end of the file
    if (fseek(file, 0, SEEK_END) != 0) {
        printf("Error seeking to end of file!\n");
        exit(1);
    }

    // Get the byte offset of the end of the file
    long filesize = ftell(file);
    if (filesize == -1) {
        printf("Error getting file size!\n");
        exit(1);
    }

    // Seek to the start of the metadata
    if (fseek(file, filesize - MAX_METADATA_LENGTH, SEEK_SET) != 0) {
        printf("Error seeking to start of metadata!\n");
        exit(1);
    }

    // Read the metadata
    char metadata[MAX_METADATA_LENGTH];
    if (fread(metadata, sizeof(char), MAX_METADATA_LENGTH, file) != MAX_METADATA_LENGTH) {
        printf("Error reading metadata!\n");
        exit(1);
    }

    // Close the file
    if (fclose(file) != 0) {
        printf("Error closing file!\n");
        exit(1);
    }

    // Create a file metadata structure and return it
    FileMetadata file_metadata;
    strncpy(file_metadata.filename, filename, MAX_FILENAME_LENGTH);
    strncpy(file_metadata.metadata, metadata, MAX_METADATA_LENGTH);
    return file_metadata;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./extract_metadata <filename>\n");
        exit(1);
    }

    const char* filename = argv[1];
    FileMetadata file_metadata = extract_metadata(filename);

    printf("Filename: %s\n", file_metadata.filename);
    printf("Metadata: %s\n", file_metadata.metadata);

    return 0;
}