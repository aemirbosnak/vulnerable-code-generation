//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 256

// Function to extract metadata from a file
char* extract_metadata(char* filename, char* key) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    char* metadata = malloc(sizeof(char) * MAX_METADATA_SIZE);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, key) != NULL) {
            char* value = strstr(line, ":") + 2;
            strncpy(metadata, value, MAX_METADATA_SIZE);
            break;
        }
    }

    free(line);
    fclose(fp);

    if (strlen(metadata) == 0) {
        printf("Metadata key %s not found in file %s\n", key, filename);
        exit(EXIT_FAILURE);
    }

    return metadata;
}

int main() {
    char* metadata = extract_metadata("example_file.txt", "Author");
    printf("Author: %s\n", metadata);
    free(metadata);

    metadata = extract_metadata("example_file.txt", "Title");
    printf("Title: %s\n", metadata);
    free(metadata);

    metadata = extract_metadata("example_file.txt", "Date");
    printf("Date: %s\n", metadata);
    free(metadata);

    return 0;
}