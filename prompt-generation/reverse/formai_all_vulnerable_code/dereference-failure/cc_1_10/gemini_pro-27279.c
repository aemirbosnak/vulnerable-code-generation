//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the metadata structure.
typedef struct {
    char *name;
    char *value;
} Metadata;

// Define the function to extract metadata from a string.
Metadata *extract_metadata(char *string) {
    // Allocate memory for the metadata structure.
    Metadata *metadata = malloc(sizeof(Metadata));

    // Extract the name and value of the metadata item.
    char *name = strtok(string, ":");
    char *value = strtok(NULL, "\n");

    // Copy the name and value to the metadata structure.
    metadata->name = strdup(name);
    metadata->value = strdup(value);

    // Return the metadata structure.
    return metadata;
}

// Define the function to print the metadata.
void print_metadata(Metadata *metadata) {
    // Print the name and value of the metadata item.
    printf("%s: %s\n", metadata->name, metadata->value);
}

// Define the main function.
int main(int argc, char **argv) {
    // Check if the user has provided a string to extract metadata from.
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Extract the metadata from the string.
    Metadata *metadata = extract_metadata(argv[1]);

    // Print the metadata.
    print_metadata(metadata);

    // Free the memory allocated for the metadata structure.
    free(metadata->name);
    free(metadata->value);
    free(metadata);

    return EXIT_SUCCESS;
}