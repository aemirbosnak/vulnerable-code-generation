//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a metadata object
typedef struct {
    char* key;
    char* value;
} Metadata;

// Function to extract metadata from a string
Metadata* extract_metadata(char* input) {
    // Initialize metadata object
    Metadata* metadata = malloc(sizeof(Metadata));
    metadata->key = NULL;
    metadata->value = NULL;

    // Split input string into key-value pairs
    char* pair = strtok(input, ":");
    while (pair!= NULL) {
        // Allocate memory for key and value strings
        char* key = malloc(strlen(pair) + 1);
        char* value = malloc(strlen(pair) + 1);

        // Copy key and value strings
        strcpy(key, pair);
        strcpy(value, strtok(NULL, ":"));

        // Set metadata object's key and value
        metadata->key = key;
        metadata->value = value;

        // Move to next pair
        pair = strtok(NULL, ":");
    }

    return metadata;
}

// Function to print metadata
void print_metadata(Metadata* metadata) {
    if (metadata->key!= NULL && metadata->value!= NULL) {
        printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
    } else {
        printf("Invalid metadata.\n");
    }
}

// Main function
int main() {
    // Test case 1
    char* input1 = "author:John Doe\ntitle:The Adventures of Captain Bluebeard";
    Metadata* metadata1 = extract_metadata(input1);
    print_metadata(metadata1);

    // Test case 2
    char* input2 = "publisher:Pirate Press\nyear:2022";
    Metadata* metadata2 = extract_metadata(input2);
    print_metadata(metadata2);

    // Free memory
    free(metadata1->key);
    free(metadata1->value);
    free(metadata1);
    free(metadata2->key);
    free(metadata2->value);
    free(metadata2);

    return 0;
}