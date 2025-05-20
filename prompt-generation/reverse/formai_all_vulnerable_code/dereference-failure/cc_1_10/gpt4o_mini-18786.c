//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 256
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    uint64_t size;
    char date_modified[30];
} FileMetadata;

void getFileSizeAndModifiedDate(const char *filename, FileMetadata *metadata) {
    struct stat fileStat;
    if (stat(filename, &fileStat) == -1) {
        perror("Could not get file status");
        return;
    }
    
    metadata->size = fileStat.st_size;
    strftime(metadata->date_modified, sizeof(metadata->date_modified), "%Y-%m-%d %H:%M:%S", localtime(&fileStat.st_mtime));
}

void extractMetadataFromDirectory(const char *dirPath) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(dirPath)) == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Only regular files
            FileMetadata metadata;
            snprintf(metadata.name, sizeof(metadata.name), "%s/%s", dirPath, entry->d_name);
            getFileSizeAndModifiedDate(metadata.name, &metadata);
            printf("File: %s\n", metadata.name);
            printf("Size: %llu bytes\n", metadata.size);
            printf("Date Modified: %s\n\n", metadata.date_modified);
        }
    }
    
    closedir(dir);
}

void printUsage(char *progName) {
    printf("Usage: %s <directory_path>\n", progName);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    char *directoryPath = argv[1];
    extractMetadataFromDirectory(directoryPath);

    return EXIT_SUCCESS;
}