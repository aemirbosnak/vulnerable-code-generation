//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: introspective
// C Metadata Extractor Example Program

#include <stdio.h>
#include <stdlib.h>

// Declare the structure for storing metadata
struct metadata {
    char *name;
    char *description;
    char *author;
};

// Declare the function for extracting metadata
void extract_metadata(char *file, struct metadata *metadata) {
    // Open the file and read the first line
    FILE *fp = fopen(file, "r");
    char line[1024];
    fgets(line, 1024, fp);

    // Extract the metadata from the line
    char *name = strtok(line, ",");
    char *description = strtok(NULL, ",");
    char *author = strtok(NULL, ",");

    // Store the metadata in the structure
    metadata->name = name;
    metadata->description = description;
    metadata->author = author;

    // Close the file
    fclose(fp);
}

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    // Declare the structure for storing metadata
    struct metadata metadata;

    // Extract the metadata from the file
    extract_metadata(argv[1], &metadata);

    // Print the metadata
    printf("Name: %s\n", metadata.name);
    printf("Description: %s\n", metadata.description);
    printf("Author: %s\n", metadata.author);

    return 0;
}