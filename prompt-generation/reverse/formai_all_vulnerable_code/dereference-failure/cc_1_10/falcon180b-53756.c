//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum length of a metadata field
#define MAX_METADATA_LEN 256

// Struct to hold metadata information
typedef struct {
    char *key;
    char *value;
} Metadata;

// Function to extract metadata from a file
void extract_metadata(FILE *file, Metadata *metadata) {
    char line[MAX_METADATA_LEN];
    char *key = NULL;
    char *value = NULL;

    // Read the first line of the file to get the metadata prefix
    fgets(line, MAX_METADATA_LEN, file);
    if (strstr(line, "metadata:") == NULL) {
        printf("Invalid metadata format\n");
        exit(1);
    }

    // Loop through the rest of the file to extract key-value pairs
    while (fgets(line, MAX_METADATA_LEN, file)!= NULL) {
        if (strstr(line, "key:")!= NULL) {
            key = strchr(line, ':') + 1;
            value = strchr(line, ':') + 2;
            metadata->key = strdup(key);
            metadata->value = strdup(value);
        }
    }
}

// Function to print metadata information
void print_metadata(Metadata *metadata) {
    printf("Key: %s\n", metadata->key);
    printf("Value: %s\n", metadata->value);
}

// Main function to test the metadata extraction
int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    Metadata metadata;
    extract_metadata(input_file, &metadata);
    print_metadata(&metadata);

    fprintf(output_file, "Key: %s\n", metadata.key);
    fprintf(output_file, "Value: %s\n", metadata.value);

    fclose(input_file);
    fclose(output_file);

    return 0;
}