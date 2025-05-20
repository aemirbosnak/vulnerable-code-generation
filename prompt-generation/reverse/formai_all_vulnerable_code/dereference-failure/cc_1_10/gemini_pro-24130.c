//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom metadata struct
typedef struct {
    char *name;
    char *value;
} Metadata;

// Define a function to extract metadata from a string
Metadata *extract_metadata(char *input) {
    // Allocate memory for the metadata struct
    Metadata *metadata = malloc(sizeof(Metadata));

    // Find the first colon in the input string
    char *colon = strchr(input, ':');

    // If there is no colon, the input is not valid metadata
    if (colon == NULL) {
        return NULL;
    }

    // Allocate memory for the name and value strings
    metadata->name = malloc(colon - input + 1);
    metadata->value = malloc(strlen(colon + 1) + 1);

    // Copy the name and value strings from the input string
    strncpy(metadata->name, input, colon - input);
    metadata->name[colon - input] = '\0';
    strcpy(metadata->value, colon + 1);

    // Return the metadata struct
    return metadata;
}

// Define a function to print metadata
void print_metadata(Metadata *metadata) {
    // Print the name and value of the metadata
    printf("%s: %s\n", metadata->name, metadata->value);
}

int main() {
    // Define a string containing metadata
    char *input = "name: John Doe";

    // Extract the metadata from the string
    Metadata *metadata = extract_metadata(input);

    // Print the metadata
    print_metadata(metadata);

    // Free the memory allocated for the metadata struct
    free(metadata->name);
    free(metadata->value);
    free(metadata);

    return 0;
}