//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Define a structure to hold metadata information
typedef struct {
    char* name;
    char* value;
} metadata_t;

// Function to extract metadata from a string
metadata_t* extract_metadata(char* input) {
    metadata_t* metadata = malloc(sizeof(metadata_t));
    metadata->name = NULL;
    metadata->value = NULL;

    // Loop through the input string
    char* token;
    char* delimiter = "=";
    token = strtok(input, delimiter);
    while (token!= NULL) {
        // Check if the token is a name or value
        if (metadata->name == NULL) {
            metadata->name = strdup(token);
        } else if (metadata->value == NULL) {
            metadata->value = strdup(token);
        }

        // Move to the next token
        token = strtok(NULL, delimiter);
    }

    return metadata;
}

// Function to print metadata
void print_metadata(metadata_t* metadata) {
    if (metadata!= NULL) {
        printf("Name: %s\n", metadata->name);
        printf("Value: %s\n", metadata->value);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }

    // Read input from file or standard input
    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }
    char input[1024];
    while (fgets(input, sizeof(input), input_file)!= NULL) {
        // Extract metadata from each line
        metadata_t* metadata = extract_metadata(input);
        if (metadata!= NULL) {
            print_metadata(metadata);
            free(metadata->name);
            free(metadata->value);
            free(metadata);
        }
    }
    fclose(input_file);

    return 0;
}