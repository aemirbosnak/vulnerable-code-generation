//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 256
#define MAX_ENTRIES 50

typedef struct {
    char key[50];
    char value[200];
} MetadataEntry;

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    MetadataEntry entries[MAX_ENTRIES];
    int entryCount;
} Metadata;

void loadMetadata(const char *filename, Metadata *metadata) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    strcpy(metadata->filename, filename);
    metadata->entryCount = 0;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (metadata->entryCount >= MAX_ENTRIES) {
            fprintf(stderr, "Warning: maximum metadata entries reached for %s\n", filename);
            break;
        }

        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");
        if (key && value) {
            strncpy(metadata->entries[metadata->entryCount].key, key, sizeof(metadata->entries[metadata->entryCount].key));
            strncpy(metadata->entries[metadata->entryCount].value, value, sizeof(metadata->entries[metadata->entryCount].value));
            metadata->entryCount++;
        }
    }

    fclose(file);
}

void printMetadata(const Metadata *metadata) {
    printf("Metadata for file: %s\n", metadata->filename);
    for (int i = 0; i < metadata->entryCount; i++) {
        printf("  %s: %s\n", metadata->entries[i].key, metadata->entries[i].value);
    }
}

void extractAndDisplayMetadata(const char *filenames[], int fileCount) {
    for (int i = 0; i < fileCount; i++) {
        Metadata metadata;
        loadMetadata(filenames[i], &metadata);
        printMetadata(&metadata);
    }
}

void toUpperCase(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *inputFiles[MAX_FILES];
    int fileCount = 0;

    for (int i = 1; i < argc && fileCount < MAX_FILES; i++) {
        toUpperCase(argv[i]);  // Convert filename to uppercase for a unique effect
        inputFiles[fileCount++] = argv[i];
    }

    extractAndDisplayMetadata(inputFiles, fileCount);

    return EXIT_SUCCESS;
}