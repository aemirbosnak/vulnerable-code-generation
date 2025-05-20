//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Let's define some helpful constants
#define FILENAME_MAX_LENGTH 256
#define MAX_METADATA_LENGTH 1024

// We'll use this metadata extractor to pull information from audio files
#define METADATA_EXTRACTOR_MAX_FILES 10

// This is our metadata extractor function. It will happily return metadata for you!
char *extractMetadata(const char *filename) {
    // Let's check if the file exists
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return NULL;
    }

    // We'll use this buffer to store the metadata
    char metadata[MAX_METADATA_LENGTH] = {0};

    // Now, let's grab the metadata!
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, fileSize - MAX_METADATA_LENGTH, SEEK_SET);
    fread(metadata, 1, MAX_METADATA_LENGTH, file);
    fclose(file);

    // And here's your metadata, ready to be used!
    return strdup(metadata);
}

int main(int argc, char *argv[]) {
    // Let's set up our variables
    char filenames[METADATA_EXTRACTOR_MAX_FILES][FILENAME_MAX_LENGTH];
    char *metadata[METADATA_EXTRACTOR_MAX_FILES];
    int numFiles = 0;

    // Let's check if we were given some files to process
    if (argc < 2) {
        printf("Usage: %s <filename1> <filename2> ...\n", argv[0]);
        return 1;
    }

    // We'll process the files one by one
    for (int i = 1; i < argc; i++) {
        // Let's grab the filename
        strncpy(filenames[numFiles], argv[i], FILENAME_MAX_LENGTH);

        // And extract the metadata
        metadata[numFiles] = extractMetadata(filenames[numFiles]);

        // Increment the number of files processed
        numFiles++;
    }

    // Time to display the extracted metadata!
    for (int i = 0; i < numFiles; i++) {
        printf("Metadata for file %s:\n", filenames[i]);
        printf("----------------------\n");
        printf("%s\n\n", metadata[i]);
    }

    // Let's clean up
    for (int i = 0; i < numFiles; i++) {
        free(metadata[i]);
    }

    return 0;
}