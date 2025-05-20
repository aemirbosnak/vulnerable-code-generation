//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 255
#define MAX_METADATA_LENGTH 512

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char metadata[MAX_METADATA_LENGTH];
} FileMetadata;

void print_usage(const char *progname) {
    printf("Usage: %s <file1> <file2> ... <fileN>\n", progname);
}

void extract_metadata(const char *filename, FileMetadata *fileMetadata) {
    // Simulate metadata extraction
    snprintf(fileMetadata->metadata, MAX_METADATA_LENGTH, 
             "Metadata for file %s: Size=%ld bytes, Created=2023-10-01, Author=John Doe", 
             filename, (long)(strlen(filename) + rand() % 100));
    strcpy(fileMetadata->filename, filename);
}

void display_metadata(FileMetadata *fileMetadata, int count) {
    printf("\n--- File Metadata Extractor ---\n");
    for (int i = 0; i < count; i++) {
        printf("File: %s\n", fileMetadata[i].filename);
        printf("Metadata: %s\n\n", fileMetadata[i].metadata);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    FileMetadata fileMetadata[MAX_FILES];
    int fileCount = 0;

    for (int i = 1; i < argc && fileCount < MAX_FILES; i++) {
        extract_metadata(argv[i], &fileMetadata[fileCount]);
        fileCount++;
    }

    display_metadata(fileMetadata, fileCount);

    return EXIT_SUCCESS;
}