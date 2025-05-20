//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the metadata structure
typedef struct {
    char* author;
    char* title;
    int publication_year;
    char* publisher;
} Metadata;

// Function to extract metadata from a given file
Metadata* extract_metadata(FILE* file) {
    Metadata* metadata = malloc(sizeof(Metadata));
    char line[256];

    // Extract author
    fgets(line, sizeof(line), file);
    metadata->author = strtok(line, ":");

    // Extract title
    fgets(line, sizeof(line), file);
    metadata->title = strtok(line, ":");

    // Extract publication year
    fgets(line, sizeof(line), file);
    metadata->publication_year = atoi(strtok(line, ":"));

    // Extract publisher
    fgets(line, sizeof(line), file);
    metadata->publisher = strtok(line, ":");

    return metadata;
}

// Function to print metadata
void print_metadata(Metadata* metadata) {
    printf("Author: %s\n", metadata->author);
    printf("Title: %s\n", metadata->title);
    printf("Publication Year: %d\n", metadata->publication_year);
    printf("Publisher: %s\n", metadata->publisher);
}

// Function to free metadata memory
void free_metadata(Metadata* metadata) {
    free(metadata->author);
    free(metadata->title);
    free(metadata->publisher);
    free(metadata);
}

int main() {
    // Open the metadata file
    FILE* metadata_file = fopen("metadata.txt", "r");
    if (metadata_file == NULL) {
        printf("Error: Could not open metadata file.\n");
        return 1;
    }

    // Extract metadata
    Metadata* metadata = extract_metadata(metadata_file);

    // Print metadata
    printf("Metadata:\n");
    print_metadata(metadata);

    // Free metadata memory
    free_metadata(metadata);

    // Close the metadata file
    fclose(metadata_file);

    return 0;
}