//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_FILES 100
#define FILENAME_LENGTH 256

typedef struct {
    char name[FILENAME_LENGTH];
    off_t size;
    char type[20];
    time_t last_modified;
} FileInfo;

void getFileType(char *fileName, char *fileType) {
    const char *extension = strrchr(fileName, '.');
    if (extension) {
        if (strcmp(extension, ".jpg") == 0 || strcmp(extension, ".png") == 0) {
            strcpy(fileType, "Image");
        } else if (strcmp(extension, ".mp3") == 0 || strcmp(extension, ".wav") == 0) {
            strcpy(fileType, "Audio");
        } else if (strcmp(extension, ".txt") == 0) {
            strcpy(fileType, "Text");
        } else {
            strcpy(fileType, "Unknown");
        }
    } else {
        strcpy(fileType, "Unknown");
    }
}

void extractMetadata(FileInfo *fileInfo) {
    struct stat fileStat;
    if (stat(fileInfo->name, &fileStat) == 0) {
        fileInfo->size = fileStat.st_size;
        fileInfo->last_modified = fileStat.st_mtime;
    } else {
        perror("Error retrieving file stats");
        fileInfo->size = -1;
        fileInfo->last_modified = -1;
    }
}

void printMetadata(FileInfo *fileInfo) {
    char timeString[26];
    ctime_r(&fileInfo->last_modified, timeString);
    timeString[strlen(timeString) - 1] = '\0'; // Remove the newline

    printf("File: %s\n", fileInfo->name);
    printf("Size: %ld bytes\n", fileInfo->size);
    printf("Type: %s\n", fileInfo->type);
    printf("Last Modified: %s\n\n", timeString);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FileInfo fileInfo[MAX_FILES];
    int fileCount = 0;

    for (int i = 1; i < argc && fileCount < MAX_FILES; i++) {
        strncpy(fileInfo[fileCount].name, argv[i], FILENAME_LENGTH);
        getFileType(fileInfo[fileCount].name, fileInfo[fileCount].type);
        extractMetadata(&fileInfo[fileCount]);
        fileCount++;
    }

    for (int i = 0; i < fileCount; i++) {
        printMetadata(&fileInfo[i]);
    }

    return EXIT_SUCCESS;
}