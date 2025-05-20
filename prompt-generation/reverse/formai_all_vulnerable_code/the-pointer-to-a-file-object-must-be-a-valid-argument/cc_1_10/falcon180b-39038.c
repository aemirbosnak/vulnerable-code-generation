//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Metadata structure
typedef struct {
    char* name;
    char* value;
} Metadata;

// Function to extract metadata
void extract_metadata(char* file_path) {
    FILE* file = fopen(file_path, "r");
    char line[1024];
    char* token;
    int line_number = 0;
    int num_metadata = 0;

    // Allocate memory for metadata array
    Metadata* metadata = (Metadata*)malloc(1 * sizeof(Metadata));

    // Loop through each line in the file
    while (fgets(line, sizeof(line), file)!= NULL) {
        line_number++;

        // Check for metadata
        token = strtok(line, ":");
        if (token!= NULL) {
            num_metadata++;

            // Reallocate memory for metadata array if necessary
            if (num_metadata > 1) {
                metadata = (Metadata*)realloc(metadata, num_metadata * sizeof(Metadata));
            }

            // Set metadata name and value
            metadata[num_metadata - 1].name = strdup(token);
            metadata[num_metadata - 1].value = strdup(strtok(NULL, ":"));
        }
    }

    // Print metadata
    for (int i = 0; i < num_metadata; i++) {
        printf("Line %d: %s = %s\n", line_number, metadata[i].name, metadata[i].value);
    }

    // Free memory
    for (int i = 0; i < num_metadata; i++) {
        free(metadata[i].name);
        free(metadata[i].value);
    }
    free(metadata);
    fclose(file);
}

int main() {
    // Test with example file
    char* file_path = "example.txt";
    extract_metadata(file_path);
    return 0;
}