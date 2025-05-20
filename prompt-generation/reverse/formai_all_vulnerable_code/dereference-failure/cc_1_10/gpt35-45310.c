//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_MAX_LENGTH 100

// Define metadata structure
typedef struct {
    char fileName[FILE_NAME_MAX_LENGTH];
    int fileSize;
    char author[100];
    char dateCreated[20];
    char dateModified[20];
} Metadata;

// Function to extract metadata
Metadata extractMetadata(char* filePath) {
    Metadata metadata;
    FILE* file = fopen(filePath, "rb");
    if (file != NULL) {
        // Get file name
        strcpy(metadata.fileName, filePath);
        
        // Get file size
        fseek(file, 0L, SEEK_END);
        metadata.fileSize = ftell(file);
        rewind(file);
        
        // Get author
        strcpy(metadata.author, "Unknown");
        
        // Get date created and modified
        strcpy(metadata.dateCreated, "Unknown");
        strcpy(metadata.dateModified, "Unknown");
        
        fclose(file);
    } else {
        printf("Failed to open file: %s\n", filePath);
    }
    
    return metadata;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    // Extract metadata
    Metadata metadata = extractMetadata(argv[1]);
    printf("File name: %s\n", metadata.fileName);
    printf("File size: %d bytes\n", metadata.fileSize);
    printf("Author: %s\n", metadata.author);
    printf("Date created: %s\n", metadata.dateCreated);
    printf("Date modified: %s\n", metadata.dateModified);
    
    return 0;
}