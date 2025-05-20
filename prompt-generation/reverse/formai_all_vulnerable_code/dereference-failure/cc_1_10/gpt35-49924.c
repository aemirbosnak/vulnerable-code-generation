//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct to store metadata
typedef struct {
    char* author;
    char* date;
    int version;
} Metadata;

// Function to extract metadata from file
Metadata extract_metadata(char* filename) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    // Initialize metadata
    Metadata metadata = {"", "", 0};

    fp = fopen(filename, "r"); // Open file in read mode
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Read each line of the file
    while ((read = getline(&line, &len, fp)) != -1) {
        // Check for metadata tags
        if (strstr(line, "// @Author:")) {
            metadata.author = strdup(line+12); // Copy author name from line
        }
        else if (strstr(line, "// @Date:")) {
            metadata.date = strdup(line+10); // Copy date from line
        }
        else if (strstr(line, "// @Version:")) {
            metadata.version = atoi(line+13); // Convert version to integer
        }
    }

    // Close file
    fclose(fp);

    // Return metadata struct
    return metadata;
}

// Main function to test metadata extraction
int main() {
    // Define filename
    char* filename = "example.c";

    // Extract metadata from file
    Metadata metadata = extract_metadata(filename);

    // Print metadata
    printf("Author: %s", metadata.author);
    printf("Date: %s", metadata.date);
    printf("Version: %d\n", metadata.version);

    // Free memory used by metadata
    free(metadata.author);
    free(metadata.date);
    
    return 0;
}