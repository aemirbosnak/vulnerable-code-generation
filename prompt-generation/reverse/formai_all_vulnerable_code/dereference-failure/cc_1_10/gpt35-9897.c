//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the metadata string
#define MAX_META_LENGTH 1024

// Define a function to extract metadata from a file
char* extract_metadata(char* filename) {
    char* metadata = (char*)malloc(MAX_META_LENGTH * sizeof(char));
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: unable to open file %s\n", filename);
        return NULL;
    }

    // Seek to the end of the file to get the file size
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate a buffer to hold the file contents and read them into the buffer
    char* file_contents = (char*)malloc(file_size * sizeof(char));
    fread(file_contents, sizeof(char), file_size, fp);
    fclose(fp);

    // Search for the metadata string using strstr
    char* meta_start = strstr(file_contents, "metadata:");
    if (meta_start == NULL) {
        printf("Error: metadata string not found in file %s\n", filename);
        return NULL;
    }
    meta_start += strlen("metadata:");
    char* meta_end = strstr(meta_start, "\n");
    if (meta_end == NULL) {
        printf("Error: end of metadata not found in file %s\n", filename);
        return NULL;
    }
    *meta_end = '\0';

    // Copy the metadata string into the metadata buffer
    strncpy(metadata, meta_start, MAX_META_LENGTH);

    // Free the file contents buffer
    free(file_contents);

    // Return the metadata buffer
    return metadata;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: metadata_extractor filename\n");
        return 1;
    }
    char* meta = extract_metadata(argv[1]);
    if (meta == NULL) return 1;
    printf("Metadata: %s\n", meta);
    free(meta);
    return 0;
}