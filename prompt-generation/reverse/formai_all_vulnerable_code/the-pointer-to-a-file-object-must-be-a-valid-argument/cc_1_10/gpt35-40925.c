//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a metadata value
#define MAX_VALUE_LENGTH 100

// Define the maximum length of a line in the metadata file
#define MAX_LINE_LENGTH 2048

// Define a struct to hold a key-value pair
struct Metadata {
    char key[MAX_VALUE_LENGTH];
    char value[MAX_VALUE_LENGTH];
};

int main(int argc, char *argv[]) {
    char *filename;

    // Check for correct number of arguments
    if(argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        exit(1);
    }
    else {
        filename = argv[1];
        printf("Parsing metadata from file: %s\n\n", filename);
    }

    // Open the metadata file for reading
    FILE *metadata_file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];

    // Define an array of struct Metadata to hold the key-value pairs
    struct Metadata metadata[100];

    // Define a counter to keep track of the number of lines read
    int metadata_count = 0;

    // Read each line of the metadata file
    while(fgets(line, MAX_LINE_LENGTH, metadata_file)) {
        // Strip the newline character from the line
        char *pos = strchr(line, '\n');
        if(pos) {
            *pos = '\0';
        }

        // Split the line into a key-value pair
        char *key_value_pair[2];
        key_value_pair[0] = strtok(line, "=");
        key_value_pair[1] = strtok(NULL, "=");

        // Copy the key-value pair into the metadata array
        if(key_value_pair[0] && key_value_pair[1]) {
            strcpy(metadata[metadata_count].key, key_value_pair[0]);
            strcpy(metadata[metadata_count].value, key_value_pair[1]);
            metadata_count++;
        }
    }

    // Close the metadata file
    fclose(metadata_file);

    // Print the key-value pairs
    for(int i = 0; i < metadata_count; i++) {
        printf("Key: %s\nValue: %s\n\n", metadata[i].key, metadata[i].value);
    }

    return 0;
}