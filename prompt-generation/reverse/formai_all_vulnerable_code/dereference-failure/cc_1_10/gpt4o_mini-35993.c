//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_METADATA_LENGTH 256

typedef struct {
    char fileName[MAX_METADATA_LENGTH];
    char author[MAX_METADATA_LENGTH];
    char description[MAX_METADATA_LENGTH];
    char date[MAX_METADATA_LENGTH];
    long size; // in bytes
} MetaData;

void extractMetadata(const char *filePath, MetaData *meta) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    // Simulating metadata extraction for the example
    strncpy(meta->fileName, filePath, MAX_METADATA_LENGTH);
    strncpy(meta->author, "John Doe", MAX_METADATA_LENGTH);
    strncpy(meta->description, "An example file for metadata extraction.", MAX_METADATA_LENGTH);
    strncpy(meta->date, "2023-10-23", MAX_METADATA_LENGTH);

    // Get file size
    fseek(file, 0, SEEK_END);
    meta->size = ftell(file);
    fclose(file);
}

void printMetadata(const MetaData *meta) {
    printf("File Name: %s\n", meta->fileName);
    printf("Author: %s\n", meta->author);
    printf("Description: %s\n", meta->description);
    printf("Date: %s\n", meta->date);
    printf("Size: %ld bytes\n\n", meta->size);
}

void extractFromMultipleFiles(const char *filePaths[], int numFiles) {
    MetaData meta[MAX_FILES];

    for (int i = 0; i < numFiles; i++) {
        extractMetadata(filePaths[i], &meta[i]);
    }

    printf("Extracted Metadata:\n");
    for (int i = 0; i < numFiles; i++) {
        printMetadata(&meta[i]);
    }
}

void writeMetadataToFile(const char *outputPath, const MetaData *meta, int numFiles) {
    FILE *outputFile = fopen(outputPath, "w");
    if (outputFile == NULL) {
        perror("Unable to open output file");
        return;
    }

    for (int i = 0; i < numFiles; i++) {
        fprintf(outputFile, "File Name: %s\n", meta[i].fileName);
        fprintf(outputFile, "Author: %s\n", meta[i].author);
        fprintf(outputFile, "Description: %s\n", meta[i].description);
        fprintf(outputFile, "Date: %s\n", meta[i].date);
        fprintf(outputFile, "Size: %ld bytes\n\n", meta[i].size);
    }

    fclose(outputFile);
    printf("Metadata written to %s\n", outputPath);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int numFiles = argc - 1;
    const char **filePaths = (const char **)malloc(numFiles * sizeof(char *));
    if (filePaths == NULL) {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < numFiles; i++) {
        filePaths[i] = argv[i + 1];
    }

    extractFromMultipleFiles(filePaths, numFiles);

    // Save metadata to a specific output file
    char outputPath[MAX_METADATA_LENGTH] = "metadata_output.txt";
    writeMetadataToFile(outputPath, filePaths, numFiles);

    free((void *)filePaths);
    return EXIT_SUCCESS;
}