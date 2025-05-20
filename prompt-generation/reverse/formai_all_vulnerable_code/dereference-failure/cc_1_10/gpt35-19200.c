//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct definition for metadata
typedef struct metadata {
    char *filename;
    char *author;
    char *date_created;
    char *date_modified;
} Metadata;

// Function to extract metadata from file
Metadata extract_metadata(char *file_path) {

    Metadata metadata;
    metadata.filename = strdup(file_path); // Get filename from file_path
    
    // Open file for reading in binary mode
    FILE *file = fopen(file_path, "rb");

    // Check if file exists
    if (!file) {
        printf("Error opening file!\n");
        return metadata;
    }

    // Read file into buffer
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    char *file_buffer = malloc(file_size);
    fseek(file, 0, SEEK_SET);
    fread(file_buffer, file_size, 1, file);

    // Extract metadata from buffer
    char *pos = strstr(file_buffer, "Author:");
    if (pos) {
        metadata.author = strdup(pos + strlen("Author:"));
        char *end_pos = strchr(metadata.author, '\n');
        if (end_pos) *end_pos = '\0';
    }

    pos = strstr(file_buffer, "Date Created:");
    if (pos) {
        metadata.date_created = strdup(pos + strlen("Date Created:"));
        char *end_pos = strchr(metadata.date_created, '\n');
        if (end_pos) *end_pos = '\0';
    }

    pos = strstr(file_buffer, "Date Modified:");
    if (pos) {
        metadata.date_modified = strdup(pos + strlen("Date Modified:"));
        char *end_pos = strchr(metadata.date_modified, '\n');
        if (end_pos) *end_pos = '\0';
    }

    // Free buffer and close file
    free(file_buffer);
    fclose(file);

    return metadata;
}

int main() {

    char *file_path = "example.txt";

    Metadata metadata = extract_metadata(file_path);

    if (metadata.author) {
        printf("Author: %s\n", metadata.author);
    }

    if (metadata.date_created) {
        printf("Date Created: %s\n", metadata.date_created);
    }

    if (metadata.date_modified) {
        printf("Date Modified: %s\n", metadata.date_modified);
    }

    free(metadata.filename);
    free(metadata.author);
    free(metadata.date_created);
    free(metadata.date_modified);

    return 0;
}