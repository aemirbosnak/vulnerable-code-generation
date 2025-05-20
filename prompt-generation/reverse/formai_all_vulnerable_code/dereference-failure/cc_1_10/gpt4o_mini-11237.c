//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Structure to hold metadata for a file
typedef struct {
    char *fileName;
    char *filePath;
    size_t fileSize;
    time_t creationTime;
    time_t modificationTime;
} FileMetadata;

// Function prototypes
void extractFileMetadata(const char *filePath, FileMetadata *metadata);
void printMetadata(const FileMetadata *metadata);
void freeMetadata(FileMetadata *metadata);
void listFilesInDirectory(const char *directoryPath);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory-path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    listFilesInDirectory(argv[1]);
    return EXIT_SUCCESS;
}

void listFilesInDirectory(const char *directoryPath) {
    struct dirent *entry;
    DIR *dp = opendir(directoryPath);

    if (dp == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) {  // Only process regular files
            char *fullPath = malloc(strlen(directoryPath) + strlen(entry->d_name) + 2);
            sprintf(fullPath, "%s/%s", directoryPath, entry->d_name);
            FileMetadata metadata;
            extractFileMetadata(fullPath, &metadata);
            printMetadata(&metadata);
            freeMetadata(&metadata);
            free(fullPath);
        }
    }

    closedir(dp);
}

void extractFileMetadata(const char *filePath, FileMetadata *metadata) {
    struct stat fileStat;
    if (stat(filePath, &fileStat) < 0) {
        perror("stat");
        return;
    }

    metadata->fileName = strdup(filePath + strlen(filePath) - strlen(strrchr(filePath, '/')));
    metadata->filePath = strdup(filePath);
    metadata->fileSize = fileStat.st_size;
    metadata->creationTime = fileStat.st_ctime;  // Creation time
    metadata->modificationTime = fileStat.st_mtime;  // Last modification time
}

void printMetadata(const FileMetadata *metadata) {
    printf("File Name: %s\n", metadata->fileName);
    printf("File Path: %s\n", metadata->filePath);
    printf("File Size: %lu bytes\n", metadata->fileSize);
    printf("Creation Time: %s", ctime(&metadata->creationTime));
    printf("Modification Time: %s", ctime(&metadata->modificationTime));
    printf("--------------------------------------\n");
}

void freeMetadata(FileMetadata *metadata) {
    free(metadata->fileName);
    free(metadata->filePath);
}