//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A custom metadata extractor function
int extract_metadata(char *filename, char *key, char *value) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Check if the line contains the key
        if (strstr(line, key) != NULL) {
            // Get the value of the key
            char *value_start = strstr(line, ":");
            if (value_start != NULL) {
                // Copy the value into the output buffer
                strcpy(value, value_start + 1);
                // Remove any trailing newline characters
                char *newline = strchr(value, '\n');
                if (newline != NULL) {
                    *newline = '\0';
                }
                // Close the file and return success
                fclose(file);
                return 0;
            }
        }
    }

    // Close the file and return failure
    fclose(file);
    return -1;
}

int main(int argc, char *argv[]) {
    // Check if the user provided enough arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s filename key value\n", argv[0]);
        return 1;
    }

    // Extract the metadata
    char value[1024];
    int result = extract_metadata(argv[1], argv[2], value);

    // Check if the metadata was extracted successfully
    if (result == 0) {
        // Print the metadata value
        printf("%s: %s\n", argv[2], value);
    } else {
        // Print an error message
        fprintf(stderr, "Error extracting metadata from %s\n", argv[1]);
    }

    return 0;
}