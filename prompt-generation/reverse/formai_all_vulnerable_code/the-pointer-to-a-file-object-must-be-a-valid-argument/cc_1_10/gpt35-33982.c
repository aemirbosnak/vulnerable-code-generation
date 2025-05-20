//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the metadata tag
#define MAX_METADATA_TAG_SIZE 50

// Define the maximum size of the metadata value
#define MAX_METADATA_VALUE_SIZE 100

// Define the metadata struct
typedef struct {
    char tag[MAX_METADATA_TAG_SIZE];
    char value[MAX_METADATA_VALUE_SIZE];
} metadata_t;

// Define the extract_metadata function
void extract_metadata(const char* filename, metadata_t* metadata, int* num_metadata) {
    // Open the file for reading
    FILE* fp = fopen(filename, "r");

    // Initialize the number of metadata tags to 0
    *num_metadata = 0;

    // Read the file line by line
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        // Check if the line starts with a metadata tag
        if (line[0] == '@') {
            // Remove the newline character
            line[strcspn(line, "\n")] = 0;

            // Extract the metadata tag and value
            char tag[MAX_METADATA_TAG_SIZE] = {0};
            char value[MAX_METADATA_VALUE_SIZE] = {0};
            sscanf(line, "@%s %s", tag, value);

            // Copy the metadata tag and value to the metadata struct
            strcpy(metadata[*num_metadata].tag, tag);
            strcpy(metadata[*num_metadata].value, value);

            // Increment the number of metadata tags
            (*num_metadata)++;
        }
    }

    // Close the file
    fclose(fp);
}

int main() {
    // Initialize the metadata struct and the number of metadata tags
    metadata_t metadata[10];
    int num_metadata;

    // Extract the metadata from the file
    extract_metadata("example.txt", metadata, &num_metadata);

    // Print the metadata
    for (int i = 0; i < num_metadata; i++) {
        printf("Tag: %s\nValue: %s\n", metadata[i].tag, metadata[i].value);
    }

    return 0;
}