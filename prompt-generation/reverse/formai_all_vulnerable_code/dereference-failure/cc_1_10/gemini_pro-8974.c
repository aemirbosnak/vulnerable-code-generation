//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: light-weight
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Simple struct to hold metadata.
typedef struct {
    char *name;
    char *value;
} Metadata;

// Function to extract metadata from a string.
Metadata *extract_metadata(char *str) {
    // Allocate memory for the metadata struct.
    Metadata *metadata = malloc(sizeof(Metadata));

    // Initialize the metadata struct.
    metadata->name = NULL;
    metadata->value = NULL;
    
    // Check if the argument is empty or null.
    if(strlen(str) <= 0){
        return metadata;
    }

    // Extract the metadata from the string.
    char *name = strtok(str, ":");
    char *value = strtok(NULL, "\0");

    // Assign the metadata to the struct.
    metadata->name = strdup(name);
    metadata->value = strdup(value);

    // Return the metadata struct.
    return metadata;
}

// Function to print the metadata.
void print_metadata(Metadata *metadata) {
    // Check if the metadata is valid.
    if (metadata == NULL) {
        printf("Invalid metadata.\n");
        return;
    }

    // Print the metadata.
    printf("%s: %s\n", metadata->name, metadata->value);
}

// Main function.
int main() {
    // Declare the metadata string.
    char *metadata_str = "name:John Doe";

    // Extract the metadata from the string.
    Metadata *metadata = extract_metadata(metadata_str);

    // Print the metadata.
    print_metadata(metadata);

    // Free the memory allocated for the metadata.
    free(metadata->name);
    free(metadata->value);
    free(metadata);

    return 0;
}