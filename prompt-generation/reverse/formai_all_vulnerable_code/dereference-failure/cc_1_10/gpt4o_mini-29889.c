//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_METADATA_LENGTH 256

typedef struct {
    char name[MAX_METADATA_LENGTH];
    char value[MAX_METADATA_LENGTH];
} MetadataEntry;

typedef struct {
    char filename[MAX_METADATA_LENGTH];
    MetadataEntry* entries;
    int entryCount;
} FileMetadata;

FileMetadata fileMetadata[MAX_FILES];
int fileCount = 0;

void initializeFileMetadata(FileMetadata* fileMeta, const char* filename) {
    strncpy(fileMeta->filename, filename, MAX_METADATA_LENGTH);
    fileMeta->entries = (MetadataEntry*)malloc(sizeof(MetadataEntry) * 10); // allocate space for 10 entries
    fileMeta->entryCount = 0;
}

void addMetadataEntry(FileMetadata* fileMeta, const char* name, const char* value) {
    if (fileMeta->entryCount >= 10) {
        printf("Max metadata entries for %s reached.\n", fileMeta->filename);
        return;
    }
    strncpy(fileMeta->entries[fileMeta->entryCount].name, name, MAX_METADATA_LENGTH);
    strncpy(fileMeta->entries[fileMeta->entryCount].value, value, MAX_METADATA_LENGTH);
    fileMeta->entryCount++;
}

void printFileMetadata(const FileMetadata* fileMeta) {
    printf("Metadata for file: %s\n", fileMeta->filename);
    for (int i = 0; i < fileMeta->entryCount; i++) {
        printf("  %s: %s\n", fileMeta->entries[i].name, fileMeta->entries[i].value);
    }
}

void freeFileMetadata(FileMetadata* fileMeta) {
    free(fileMeta->entries);
}

void extractMetadataFromFile(const char* filename) {
    FileMetadata fileMeta;
    initializeFileMetadata(&fileMeta, filename);
    
    // Simulating metadata extraction
    addMetadataEntry(&fileMeta, "Author", "John Doe");
    addMetadataEntry(&fileMeta, "Date Created", "2023-10-01");
    addMetadataEntry(&fileMeta, "File Type", "Text");
    addMetadataEntry(&fileMeta, "Version", "1.0");
    
    printFileMetadata(&fileMeta);
    freeFileMetadata(&fileMeta);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        strcat(fileMetadata[fileCount].filename, argv[i]);
        extractMetadataFromFile(argv[i]);
        fileCount++;
    }
    
    return EXIT_SUCCESS;
}