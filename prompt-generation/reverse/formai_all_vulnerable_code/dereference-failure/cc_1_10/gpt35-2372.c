//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1000
#define MAX_METADATA_LENGTH 100

// Function to extract metadata from a given line
char* extract_metadata(char* line) {
    int i = 0;
    char* metadata = (char*) malloc(MAX_METADATA_LENGTH * sizeof(char));

    // Loop through the line until we reach the metadata delimiter
    while (line[i] != ':' && line[i] != '\0') {
        metadata[i] = line[i];
        i++;
    }

    // Add a null terminator to the end of the metadata string
    metadata[i] = '\0';

    // Return a pointer to the extracted metadata string
    return metadata;
}

// Function to print all the metadata in a file
void print_metadata(FILE* fp) {
    char line[MAX_LINE_LENGTH];
    bool metadata_found = false;

    // Loop through the file and print any metadata lines
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        // Check if the line contains metadata, and print it if it does
        if (line[0] == '@') {
            char* metadata = extract_metadata(line);
            printf("%s\n", metadata);
            free(metadata);
            metadata_found = true;
        }
        // Stop searching for metadata if we find a line that doesn't contain any
        else {
            if (metadata_found) {
                break;
            }
        }
    }
}

// Main function
int main(int argc, char** argv) {
    // Check if a filename was provided as command-line argument
    if (argc > 1) {
        FILE* fp = fopen(argv[1], "r");

        // Check if the file was opened successfully
        if (fp) {
            print_metadata(fp);
            fclose(fp);
        }
        else {
            printf("Error opening file %s\n", argv[1]);
        }
    }
    else {
        printf("No filename provided as command-line argument\n");
    }

    // Return 0 to indicate success
    return 0;
}