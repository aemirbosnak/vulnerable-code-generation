//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    long size;
    char type[10];
} Metadata;

void extractMetadata(const char *filename, Metadata *meta) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    fseek(file, 0, SEEK_END);
    meta->size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // For simplicity, determining the type based on extension
    const char *dot = strrchr(filename, '.');
    if (dot) {
        strcpy(meta->type, dot + 1);
    } else {
        strcpy(meta->type, "unknown");
    }

    strncpy(meta->name, filename, MAX_NAME_LENGTH);
    fclose(file);
}

void displayMetadata(const Metadata *meta) {
    printf("File Name: %s\n", meta->name);
    printf("File Size: %ld bytes\n", meta->size);
    printf("File Type: %s\n\n", meta->type);
}

void processFiles(char files[MAX_FILES][MAX_NAME_LENGTH], int count) {
    Metadata metadata[MAX_FILES];
    for (int i = 0; i < count; i++) {
        extractMetadata(files[i], &metadata[i]);
        displayMetadata(&metadata[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> [<file2> ... <fileN>]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char files[MAX_FILES][MAX_NAME_LENGTH];
    int fileCount = 0;

    for (int i = 1; i < argc && fileCount < MAX_FILES; i++) {
        strncpy(files[fileCount++], argv[i], MAX_NAME_LENGTH);
    }

    processFiles(files, fileCount);

    return EXIT_SUCCESS;
}