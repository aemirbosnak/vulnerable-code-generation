//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store metadata information
typedef struct {
    char* author;
    char* date;
    char* description;
} Metadata;

// Function to extract metadata from source code
Metadata extractMetadata(char* sourceCode) {
    Metadata metadata;
    metadata.author = NULL;
    metadata.date = NULL;
    metadata.description = NULL;
    
    // Search for metadata tags in source code
    char* authorTag = "// Author: ";
    char* dateTag = "// Date: ";
    char* descriptionTag = "// Description: ";
    
    char* authorPosition = strstr(sourceCode, authorTag);
    if (authorPosition) {
        // Extract author information
        metadata.author = (char*) malloc(sizeof(char) * 100);
        sscanf(authorPosition, "// Author: %[^\n]", metadata.author);
    }
    
    char* datePosition = strstr(sourceCode, dateTag);
    if (datePosition) {
        // Extract date information
        metadata.date = (char*) malloc(sizeof(char) * 100);
        sscanf(datePosition, "// Date: %[^\n]", metadata.date);
    }
    
    char* descriptionPosition = strstr(sourceCode, descriptionTag);
    if (descriptionPosition) {
        // Extract description information
        metadata.description = (char*) malloc(sizeof(char) * 500);
        sscanf(descriptionPosition, "// Description: %[^\n]", metadata.description);
    }
    
    return metadata;
}

int main() {
    // Read source code from file
    FILE* filePointer = fopen("example.c", "r");
    if (!filePointer) {
        printf("Error: Unable to open source code file\n");
        return 1;
    }
    fseek(filePointer, 0, SEEK_END);
    long fileSize = ftell(filePointer);
    fseek(filePointer, 0, SEEK_SET);
    char* sourceCode = (char*) malloc(sizeof(char) * fileSize + 1);
    fread(sourceCode, sizeof(char), fileSize, filePointer);
    fclose(filePointer);
    sourceCode[fileSize] = '\0';
    
    // Extract metadata information from source code
    Metadata metadata = extractMetadata(sourceCode);
    
    // Print metadata information
    printf("Author: %s\n", metadata.author ? metadata.author : "Unknown");
    printf("Date: %s\n", metadata.date ? metadata.date : "Unknown");
    printf("Description: %s\n", metadata.description ? metadata.description : "Unknown");
    
    // Free memory allocated for metadata information
    free(metadata.author);
    free(metadata.date);
    free(metadata.description);
    
    // Free memory allocated for source code
    free(sourceCode);
    
    return 0;
}