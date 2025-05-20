//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for metadata
struct Metadata {
    char* key;
    char* value;
};

// Function to extract metadata from file
void extractMetadata(char* filename, struct Metadata* metadata, int size) {
    FILE* fp = fopen(filename, "r");  // Open file for reading

    // Check if file exists
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    char line[100];  // Define buffer for reading lines

    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        char* key = strtok(line, ":");        // Extract key
        char* value = strtok(NULL, "\n");     // Extract value

        metadata[i].key = (char*)malloc(strlen(key) + 1);     // Allocate memory for key
        metadata[i].value = (char*)malloc(strlen(value) + 1); // Allocate memory for value

        strcpy(metadata[i].key, key);      // Copy key to metadata struct
        strcpy(metadata[i].value, value);  // Copy value to metadata struct

        i++;

        if (i == size) {
            break;  // Stop extracting metadata if we have reached the maximum size
        }
    }

    fclose(fp);  // Close file
}

int main() {
    char* filename = "example.txt";
    struct Metadata metadata[10];  // Define metadata array

    extractMetadata(filename, metadata, 10);  // Extract metadata from file

    // Print extracted metadata
    for (int i = 0; i < 10; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }

    return 0;
}