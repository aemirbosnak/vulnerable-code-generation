//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_METADATA 256
#define MAX_FILES 100

typedef struct {
    char filePath[MAX_METADATA];
    char mimeType[MAX_METADATA];
    long fileSize;
    struct stat fileStat;
} FileMeta;

void extractMetadata(const char *filePath, FileMeta *fileMeta) {
    strncpy(fileMeta->filePath, filePath, MAX_METADATA);
    
    // Simulated MIME type extraction based on file extension
    const char *ext = strrchr(filePath, '.');
    if (ext) {
        if (strcmp(ext, ".jpg") == 0 || strcmp(ext, ".jpeg") == 0)
            strcpy(fileMeta->mimeType, "image/jpeg");
        else if (strcmp(ext, ".png") == 0)
            strcpy(fileMeta->mimeType, "image/png");
        else if (strcmp(ext, ".txt") == 0)
            strcpy(fileMeta->mimeType, "text/plain");
        else if (strcmp(ext, ".pdf") == 0)
            strcpy(fileMeta->mimeType, "application/pdf");
        else 
            strcpy(fileMeta->mimeType, "application/octet-stream");
    } else {
        strcpy(fileMeta->mimeType, "application/octet-stream");
    }
    
    // Get file stats
    if (stat(filePath, &fileMeta->fileStat) == 0) {
        fileMeta->fileSize = fileMeta->fileStat.st_size;
    } else {
        perror("Unable to get file stats");
        fileMeta->fileSize = -1; // Indicate an error
    }
}

void printMetadata(const FileMeta *fileMeta) {
    printf("File Path: %s\n", fileMeta->filePath);
    printf("MIME Type: %s\n", fileMeta->mimeType);
    printf("File Size: %ld bytes\n", fileMeta->fileSize);
    printf("------------------------------\n");
}

int listFiles(const char *directory, FileMeta *files, int *fileCount) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    if (dp == NULL) {
        perror("opendir");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char path[MAX_METADATA];
            snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);
            extractMetadata(path, &files[*fileCount]);
            (*fileCount)++;
        }
    }
    closedir(dp);
    return 0;
}

void shiftShape(FileMeta *files, int fileCount) {
    for (int i = 0; i < fileCount; i++) {
        if (files[i].fileSize < 1024) {
            printf("This file is a pebble: ");
        } else if (files[i].fileSize < 1048576) {
            printf("This file is a rock: ");
        } else {
            printf("This file is a mountain: ");
        }
        printMetadata(&files[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FileMeta files[MAX_FILES];
    int fileCount = 0;

    if (listFiles(argv[1], files, &fileCount) == -1) {
        return EXIT_FAILURE;
    }

    printf("Extracting metadata for files in directory: %s\n", argv[1]);
    shiftShape(files, fileCount);

    return EXIT_SUCCESS;
}