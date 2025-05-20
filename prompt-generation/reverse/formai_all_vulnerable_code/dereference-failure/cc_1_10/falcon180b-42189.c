//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a metadata object
typedef struct {
    char *key;
    char *value;
} Metadata;

// Function to extract metadata from a file
void ExtractMetadata(FILE *file, Metadata *metadata) {
    char line[1024];
    char *key, *value;
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (line[0] == '#') {
            key = strtok(line, " ");
            value = strtok(NULL, " ");
            metadata->key = strdup(key);
            metadata->value = strdup(value);
            break;
        }
    }
}

// Function to print metadata
void PrintMetadata(Metadata *metadata) {
    printf("Key: %s\n", metadata->key);
    printf("Value: %s\n", metadata->value);
}

// Function to free memory allocated for metadata
void FreeMetadata(Metadata *metadata) {
    free(metadata->key);
    free(metadata->value);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    Metadata metadata;
    ExtractMetadata(input_file, &metadata);
    PrintMetadata(&metadata);

    fprintf(output_file, "Key: %s\n", metadata.key);
    fprintf(output_file, "Value: %s\n", metadata.value);

    fclose(input_file);
    fclose(output_file);

    FreeMetadata(&metadata);

    return 0;
}