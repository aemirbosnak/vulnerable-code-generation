//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold metadata of a file
typedef struct {
    char fileName[100];
    char fileType[50];
    long fileSize;
    char creationDate[30];
} FileMetadata;

// Function to retrieve file metadata
FileMetadata getFileMetadata(const char *filePath) {
    FileMetadata metadata;
    
    // Initialize file metadata
    strcpy(metadata.fileName, filePath);
    strcpy(metadata.fileType, "unknown");
    metadata.fileSize = 0;
    strcpy(metadata.creationDate, "not available");
    
    // Open the file to gather metadata
    FILE *file = fopen(filePath, "r");
    if (file != NULL) {
        // Get size of the file
        fseek(file, 0, SEEK_END);
        metadata.fileSize = ftell(file);
        fseek(file, 0, SEEK_SET);
        
        // Simple check for file type based on extension
        const char *dot = strrchr(filePath, '.');
        if (dot) {
            if (strcmp(dot, ".txt") == 0) {
                strcpy(metadata.fileType, "Text File");
            } else if (strcmp(dot, ".jpg") == 0) {
                strcpy(metadata.fileType, "Image File");
            } else if (strcmp(dot, ".png") == 0) {
                strcpy(metadata.fileType, "Image File");
            } else if (strcmp(dot, ".mp3") == 0) {
                strcpy(metadata.fileType, "Audio File");
            } else {
                strcpy(metadata.fileType, "Other");
            }
        }

        // Mock creation date for demonstration since actual creation date retrieval is system specific
        strcpy(metadata.creationDate, "2023-10-01");

        fclose(file);
    } else {
        perror("File could not be opened");
    }

    return metadata;
}

// Function to print file metadata
void printMetadata(FileMetadata metadata) {
    printf("File Name: %s\n", metadata.fileName);
    printf("File Type: %s\n", metadata.fileType);
    printf("File Size: %ld bytes\n", metadata.fileSize);
    printf("Creation Date: %s\n", metadata.creationDate);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Retrieve metadata for the specified file
    FileMetadata metadata = getFileMetadata(argv[1]);
    
    // Print the file metadata
    printMetadata(metadata);

    return EXIT_SUCCESS;
}