//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to extract metadata from file
void extractMetadata(char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (!file) {
        printf("Error: Could not open file\n");
        return;
    }

    // Create a buffer to store file contents
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);
    char* fileContents = (char*)malloc((fileSize + 1) * sizeof(char));
    fread(fileContents, fileSize, 1, file);
    fileContents[fileSize] = '\0';

    // Define metadata field names
    char* fieldNames[] = {"Title", "Author", "Date", "Keywords"};

    // Initialize metadata fields
    char* title = "";
    char* author = "";
    char* date = "";
    char* keywords = "";

    // Search file contents for metadata fields
    int i, j;
    for (i = 0; i < 4; i++) {
        char* fieldName = fieldNames[i];
        int fieldLength = strlen(fieldName);
        int startIndex = 0;
        bool foundField = false;
        
        // Find field name in file contents
        while (startIndex + fieldLength <= fileSize) {
            if (strncmp(fileContents + startIndex, fieldName, fieldLength) == 0) {
                foundField = true;
                break;
            }
            startIndex++;
        }

        // If field name found, extract value
        if (foundField) {
            startIndex += fieldLength;
            int endIndex = startIndex;
            while (endIndex < fileSize && fileContents[endIndex] != ';') {
                endIndex++;
            }
            int valueLength = endIndex - startIndex;
            char* value = (char*)malloc((valueLength + 1) * sizeof(char));
            strncpy(value, fileContents + startIndex, valueLength);
            value[valueLength] = '\0';

            // Assign value to metadata field
            switch (i) {
            case 0: // Title
                title = value;
                break;
            case 1: // Author
                author = value;
                break;
            case 2: // Date
                date = value;
                break;
            case 3: // Keywords
                keywords = value;
                break;
            }
        }
    }

    // Print extracted metadata
    printf("Title: %s\n", title);
    printf("Author: %s\n", author);
    printf("Date: %s\n", date);
    printf("Keywords: %s\n", keywords);

    // Free memory
    fclose(file);
    free(fileContents);
}

int main() {
    char* fileName = "example.txt";
    extractMetadata(fileName);
    return 0;
}