//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold file metadata
typedef struct {
    char *filename;
    long size;
    char *creationTime;
    char *lastModifiedTime;
} FileMetadata;

// Function prototypes
FileMetadata *extractMetadata(const char *filename);
void printMetadata(FileMetadata *metadata);
void freeMetadata(FileMetadata *metadata);
void getFileSize(const char *filename, long *size);
void getFileTimes(const char *filename, char **creationTime, char **lastModifiedTime);

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FileMetadata *metadata = extractMetadata(argv[1]);
    if (metadata == NULL) {
        fprintf(stderr, "Error extracting metadata for %s\n", argv[1]);
        return 1;
    }

    printMetadata(metadata);
    freeMetadata(metadata);

    return 0;
}

// Function to extract metadata
FileMetadata *extractMetadata(const char *filename) {
    FileMetadata *metadata = malloc(sizeof(FileMetadata));
    if (metadata == NULL) {
        return NULL;
    }

    metadata->filename = strdup(filename);
    getFileSize(filename, &metadata->size);
    
    getFileTimes(filename, &metadata->creationTime, &metadata->lastModifiedTime);
    
    return metadata;
}

// Function to print metadata
void printMetadata(FileMetadata *metadata) {
    printf("File Metadata:\n");
    printf("Filename: %s\n", metadata->filename);
    printf("Size: %ld bytes\n", metadata->size);
    printf("Creation Time: %s\n", metadata->creationTime);
    printf("Last Modified Time: %s\n", metadata->lastModifiedTime);
}

// Function to free metadata memory
void freeMetadata(FileMetadata *metadata) {
    if (metadata) {
        free(metadata->filename);
        free(metadata->creationTime);
        free(metadata->lastModifiedTime);
        free(metadata);
    }
}

// Function to get file size
void getFileSize(const char *filename, long *size) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        *size = 0;
        return;
    }
    
    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    fclose(file);
}

// Function to get file times (dummy implementation for creative demonstration)
void getFileTimes(const char *filename, char **creationTime, char **lastModifiedTime) {
    // For demonstration, we'll just provide some fake timestamps
    *creationTime = strdup("2020-01-01 12:00:00");
    *lastModifiedTime = strdup("2023-10-19 15:00:00");
}