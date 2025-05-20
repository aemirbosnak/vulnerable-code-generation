//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for metadata
typedef struct metadata {
    char *title;
    char *author;
    char *date;
} metadata_t;

// Function to extract metadata from a file
metadata_t *extract_metadata(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    metadata_t *metadata = malloc(sizeof(metadata_t));
    if (metadata == NULL) {
        printf("Error: Could not allocate memory for metadata\n");
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
        if (strstr(buffer, "title:")!= NULL) {
            char *title = strtok(buffer, ": ");
            metadata->title = strdup(title);
        } else if (strstr(buffer, "author:")!= NULL) {
            char *author = strtok(buffer, ": ");
            metadata->author = strdup(author);
        } else if (strstr(buffer, "date:")!= NULL) {
            char *date = strtok(buffer, ": ");
            metadata->date = strdup(date);
        }
    }

    fclose(fp);
    return metadata;
}

// Function to print metadata
void print_metadata(metadata_t *metadata) {
    if (metadata == NULL) {
        printf("No metadata found\n");
        return;
    }

    printf("Title: %s\n", metadata->title);
    printf("Author: %s\n", metadata->author);
    printf("Date: %s\n", metadata->date);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    metadata_t *metadata = extract_metadata(argv[1]);
    if (metadata!= NULL) {
        print_metadata(metadata);
        free(metadata->title);
        free(metadata->author);
        free(metadata->date);
        free(metadata);
    }

    return 0;
}