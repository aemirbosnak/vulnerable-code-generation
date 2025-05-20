//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_FILES 100
#define MAX_PATH_LENGTH 256
#define MAX_METADATA_LENGTH 512

typedef struct {
    char fileName[MAX_PATH_LENGTH];
    char fileType[MAX_PATH_LENGTH];
    long fileSize;
    char lastModified[MAX_METADATA_LENGTH];
} FileMetadata;

void getFileMetadata(const char *filePath, FileMetadata *metadata) {
    FILE *file = fopen(filePath, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    
    fseek(file, 0, SEEK_END);
    metadata->fileSize = ftell(file);
    fclose(file);
    
    // Attempt to extract file type based on extension
    const char *dot = strrchr(filePath, '.');
    if (dot && strcmp(dot, ".txt") == 0) {
        strcpy(metadata->fileType, "Text File");
    } else if (dot && strcmp(dot, ".jpg") == 0) {
        strcpy(metadata->fileType, "JPEG Image");
    } else if (dot && strcmp(dot, ".png") == 0) {
        strcpy(metadata->fileType, "PNG Image");
    } else {
        strcpy(metadata->fileType, "Unknown Type");
    }

    // Simulate getting last modified date
    snprintf(metadata->lastModified, MAX_METADATA_LENGTH, "2023-10-01 12:00:00");
    strcpy(metadata->fileName, filePath);
}

void listFilesInDirectory(const char *directoryPath) {
    DIR *directory = opendir(directoryPath);
    struct dirent *entry;
    FileMetadata fileMetadata[MAX_FILES];
    int fileCount = 0;

    if (!directory) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(directory)) && fileCount < MAX_FILES) {
        if (entry->d_type == DT_REG) { // Check if it's a regular file
            char filePath[MAX_PATH_LENGTH];
            snprintf(filePath, MAX_PATH_LENGTH, "%s/%s", directoryPath, entry->d_name);
            getFileMetadata(filePath, &fileMetadata[fileCount]);
            fileCount++;
        }
    }
    closedir(directory);

    // Output the collected metadata
    printf("Collected Metadata:\n");
    printf("%-30s %-15s %-10s %-20s\n", "File Name", "File Type", "File Size", "Last Modified");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < fileCount; i++) {
        printf("%-30s %-15s %-10ld %-20s\n", 
               fileMetadata[i].fileName, 
               fileMetadata[i].fileType, 
               fileMetadata[i].fileSize, 
               fileMetadata[i].lastModified);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directoryPath = argv[1];
    listFilesInDirectory(directoryPath);

    return EXIT_SUCCESS;
}