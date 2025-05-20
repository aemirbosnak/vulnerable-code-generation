//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define META_MAX_SIZE 1024

// Define the metadata structure
typedef struct {
    char *filename;
    char *description;
    char *author;
    char *date;
} Metadata;

// Function to extract metadata from a file
Metadata *extract_metadata(FILE *fp) {
    char line[META_MAX_SIZE];
    Metadata *meta = malloc(sizeof(Metadata));

    // Read the first line of the file, which contains the filename
    fgets(line, META_MAX_SIZE, fp);
    meta->filename = strdup(line);

    // Read the second line of the file, which contains the description
    fgets(line, META_MAX_SIZE, fp);
    meta->description = strdup(line);

    // Read the third line of the file, which contains the author
    fgets(line, META_MAX_SIZE, fp);
    meta->author = strdup(line);

    // Read the fourth line of the file, which contains the date
    fgets(line, META_MAX_SIZE, fp);
    meta->date = strdup(line);

    return meta;
}

// Function to print the metadata
void print_metadata(Metadata *meta) {
    printf("Filename: %s", meta->filename);
    printf("Description: %s", meta->description);
    printf("Author: %s", meta->author);
    printf("Date: %s", meta->date);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided a filename
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file '%s'\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Extract the metadata from the file
    Metadata *meta = extract_metadata(fp);

    // Print the metadata
    print_metadata(meta);

    // Free the allocated memory
    free(meta->filename);
    free(meta->description);
    free(meta->author);
    free(meta->date);
    free(meta);

    // Close the file
    fclose(fp);

    return EXIT_SUCCESS;
}