//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store metadata information
typedef struct metadata {
    char *filename;
    char *author;
    char *date;
    char *title;
    char *description;
} metadata_t;

// Function to extract metadata from a file
metadata_t *extract_metadata(const char *filename) {
    FILE *fp;
    char line[1024];
    metadata_t *metadata = NULL;
    char *author = NULL;
    char *date = NULL;
    char *title = NULL;
    char *description = NULL;

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return NULL;
    }

    // Initialize metadata structure
    metadata = (metadata_t *)malloc(sizeof(metadata_t));
    if (metadata == NULL) {
        fclose(fp);
        printf("Error allocating memory for metadata\n");
        return NULL;
    }
    metadata->filename = strdup(filename);
    metadata->author = NULL;
    metadata->date = NULL;
    metadata->title = NULL;
    metadata->description = NULL;

    // Extract metadata from file
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strstr(line, "Author:")!= NULL) {
            author = strdup(&line[8]);
            metadata->author = author;
        } else if (strstr(line, "Date:")!= NULL) {
            date = strdup(&line[6]);
            metadata->date = date;
        } else if (strstr(line, "Title:")!= NULL) {
            title = strdup(&line[7]);
            metadata->title = title;
        } else if (strstr(line, "Description:")!= NULL) {
            description = strdup(&line[14]);
            metadata->description = description;
        }
    }

    // Close the file
    fclose(fp);

    return metadata;
}

// Function to print metadata
void print_metadata(metadata_t *metadata) {
    if (metadata == NULL) {
        printf("No metadata found\n");
        return;
    }

    printf("Filename: %s\n", metadata->filename);
    printf("Author: %s\n", metadata->author);
    printf("Date: %s\n", metadata->date);
    printf("Title: %s\n", metadata->title);
    printf("Description: %s\n", metadata->description);
}

// Function to free metadata
void free_metadata(metadata_t *metadata) {
    if (metadata == NULL) {
        return;
    }

    free(metadata->filename);
    free(metadata->author);
    free(metadata->date);
    free(metadata->title);
    free(metadata->description);
    free(metadata);
}

// Main function
int main(int argc, char *argv[]) {
    metadata_t *metadata = NULL;

    // Check if the correct number of arguments are provided
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Extract metadata from file
    metadata = extract_metadata(argv[1]);

    // Print metadata
    print_metadata(metadata);

    // Free metadata
    free_metadata(metadata);

    return 0;
}