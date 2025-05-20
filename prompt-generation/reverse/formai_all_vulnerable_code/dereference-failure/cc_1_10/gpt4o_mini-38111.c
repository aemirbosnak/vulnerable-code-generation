//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold file metadata
typedef struct {
    char filename[256];
    long fileSize;
    char fileType[50];
    char created[20];
    char modified[20];
} FileMetadata;

// Function to extract file metadata
FileMetadata extractMetadata(const char *filename) {
    FileMetadata metadata;
    FILE *file = fopen(filename, "rb");
    
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Use fseek and ftell to get file size
    fseek(file, 0, SEEK_END);
    metadata.fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Fill in the filename
    strncpy(metadata.filename, filename, sizeof(metadata.filename) - 1);
    
    // Simple magic number check for file types (could be expanded)
    if (strstr(filename, ".txt") != NULL) {
        strcpy(metadata.fileType, "Text File");
    } else if (strstr(filename, ".jpg") != NULL) {
        strcpy(metadata.fileType, "JPEG Image");
    } else if (strstr(filename, ".png") != NULL) {
        strcpy(metadata.fileType, "PNG Image");
    } else {
        strcpy(metadata.fileType, "Unknown File Type");
    }

    // Placeholder for created and modified dates (requires advanced system calls)
    strcpy(metadata.created, "Unknown");
    strcpy(metadata.modified, "Unknown");

    fclose(file);
    return metadata;
}

// Function to print the metadata
void printMetadata(FileMetadata metadata) {
    printf("File Metadata:\n");
    printf("Filename: %s\n", metadata.filename);
    printf("File Size: %ld bytes\n", metadata.fileSize);
    printf("File Type: %s\n", metadata.fileType);
    printf("Created: %s\n", metadata.created);
    printf("Modified: %s\n", metadata.modified);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Extract metadata for each filename provided as argument
    for (int i = 1; i < argc; i++) {
        printf("Processing file: %s\n", argv[i]);
        FileMetadata metadata = extractMetadata(argv[i]);
        printMetadata(metadata);
        printf("\n");
    }
    
    return EXIT_SUCCESS;
}