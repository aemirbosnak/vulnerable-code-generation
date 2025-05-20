//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// Declare a structure to store the metadata
typedef struct _metadata {
    char *name;
    char *value;
} metadata;

// Declare a function to extract the metadata from a file
metadata *extract_metadata(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Allocate memory for the metadata
    metadata *metadata = malloc(sizeof(metadata));
    if (metadata == NULL) {
        fclose(file);
        return NULL;
    }

    // Initialize the metadata
    metadata->name = NULL;
    metadata->value = NULL;

    // Read the file line by line
    char line[MAX_SIZE];
    while (fgets(line, MAX_SIZE, file) != NULL) {
        // Find the colon in the line
        char *colon = strchr(line, ':');
        if (colon == NULL) {
            continue;
        }

        // Extract the name and value from the line
        char *name = malloc(colon - line + 1);
        if (name == NULL) {
            fclose(file);
            free(metadata);
            return NULL;
        }
        strncpy(name, line, colon - line);
        name[colon - line] = '\0';

        char *value = malloc(strlen(colon + 1) + 1);
        if (value == NULL) {
            fclose(file);
            free(metadata);
            free(name);
            return NULL;
        }
        strcpy(value, colon + 1);

        // Store the name and value in the metadata
        metadata->name = name;
        metadata->value = value;
    }

    // Close the file
    fclose(file);

    // Return the metadata
    return metadata;
}

// Declare a function to print the metadata
void print_metadata(metadata *metadata) {
    // Print the name and value of the metadata
    printf("%s: %s\n", metadata->name, metadata->value);
}

// Declare a function to free the memory allocated for the metadata
void free_metadata(metadata *metadata) {
    // Free the memory allocated for the name and value
    free(metadata->name);
    free(metadata->value);

    // Free the memory allocated for the metadata
    free(metadata);
}

int main() {
    // Extract the metadata from the file
    metadata *metadata = extract_metadata("metadata.txt");
    if (metadata == NULL) {
        printf("Error: Could not extract metadata from file.\n");
        return 1;
    }

    // Print the metadata
    print_metadata(metadata);

    // Free the memory allocated for the metadata
    free_metadata(metadata);

    return 0;
}