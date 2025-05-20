//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: high level of detail
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Define the maximum length of a metadata entry
#define MAX_METADATA_LENGTH 1024

// Define the maximum number of metadata entries
#define MAX_METADATA_ENTRIES 100

// Define the metadata structure
typedef struct {
    char *key;
    char *value;
} MetadataEntry;

// Define the metadata array
MetadataEntry metadataEntries[MAX_METADATA_ENTRIES];

// Define the number of metadata entries
int numMetadataEntries = 0;

// Function to add a metadata entry to the array
void addMetadataEntry(char *key, char *value) {
    // Check if the array is full
    if (numMetadataEntries >= MAX_METADATA_ENTRIES) {
        printf("Error: Metadata array is full\n");
        return;
    }

    // Allocate memory for the key and value
    metadataEntries[numMetadataEntries].key = malloc(strlen(key) + 1);
    metadataEntries[numMetadataEntries].value = malloc(strlen(value) + 1);

    // Copy the key and value to the array
    strcpy(metadataEntries[numMetadataEntries].key, key);
    strcpy(metadataEntries[numMetadataEntries].value, value);

    // Increment the number of metadata entries
    numMetadataEntries++;
}

// Function to get a metadata entry by key
char *getMetadataEntry(char *key) {
    // Loop through the array of metadata entries
    for (int i = 0; i < numMetadataEntries; i++) {
        // Check if the key matches
        if (strcmp(metadataEntries[i].key, key) == 0) {
            // Return the value
            return metadataEntries[i].value;
        }
    }

    // Return NULL if the key was not found
    return NULL;
}

// Function to print the metadata
void printMetadata() {
    // Loop through the array of metadata entries
    for (int i = 0; i < numMetadataEntries; i++) {
        // Print the key and value
        printf("%s: %s\n", metadataEntries[i].key, metadataEntries[i].value);
    }
}

// Main function
int main() {
    // Add some metadata entries to the array
    addMetadataEntry("Title", "My Awesome Program");
    addMetadataEntry("Author", "John Doe");
    addMetadataEntry("Version", "1.0");
    addMetadataEntry("Description", "This program does some amazing things");

    // Print the metadata
    printMetadata();

    // Get a metadata entry by key
    char *title = getMetadataEntry("Title");

    // Print the title
    printf("Title: %s\n", title);

    // Free the memory allocated for the metadata entries
    for (int i = 0; i < numMetadataEntries; i++) {
        free(metadataEntries[i].key);
        free(metadataEntries[i].value);
    }

    return 0;
}