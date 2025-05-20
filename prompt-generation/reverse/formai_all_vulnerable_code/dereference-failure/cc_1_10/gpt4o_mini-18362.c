//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_METADATA_LENGTH 1024

typedef struct {
    char file_name[MAX_FILENAME_LENGTH];
    char title[MAX_METADATA_LENGTH];
    char author[MAX_METADATA_LENGTH];
    char genre[MAX_METADATA_LENGTH];
    char year[MAX_METADATA_LENGTH];
} Metadata;

void extract_metadata(const char *filename, Metadata *metadata) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    // Initialize metadata fields
    strcpy(metadata->file_name, filename);
    memset(metadata->title, 0, MAX_METADATA_LENGTH);
    memset(metadata->author, 0, MAX_METADATA_LENGTH);
    memset(metadata->genre, 0, MAX_METADATA_LENGTH);
    memset(metadata->year, 0, MAX_METADATA_LENGTH);

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Title:", 6) == 0) {
            sscanf(line + 6, "%[^\n]", metadata->title);
        } else if (strncmp(line, "Author:", 7) == 0) {
            sscanf(line + 7, "%[^\n]", metadata->author);
        } else if (strncmp(line, "Genre:", 6) == 0) {
            sscanf(line + 6, "%[^\n]", metadata->genre);
        } else if (strncmp(line, "Year:", 5) == 0) {
            sscanf(line + 5, "%[^\n]", metadata->year);
        }
    }

    fclose(file);
}

void print_metadata(const Metadata *metadata) {
    printf("File Name: %s\n", metadata->file_name);
    printf("Title: %s\n", metadata->title[0] ? metadata->title : "N/A");
    printf("Author: %s\n", metadata->author[0] ? metadata->author : "N/A");
    printf("Genre: %s\n", metadata->genre[0] ? metadata->genre : "N/A");
    printf("Year: %s\n", metadata->year[0] ? metadata->year : "N/A");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> [<file2> ... <fileN>]\n", argv[0]);
        return EXIT_FAILURE;
    }

    Metadata metadata;
    for (int i = 1; i < argc; i++) {
        extract_metadata(argv[i], &metadata);
        print_metadata(&metadata);
        printf("\n");
    }

    return EXIT_SUCCESS;
}