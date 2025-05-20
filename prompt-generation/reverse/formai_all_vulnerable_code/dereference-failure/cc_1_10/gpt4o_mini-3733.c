//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_FILE_NAME 256
#define MAX_FILES 1024
#define METADATA_DIFF 5

typedef struct {
    char fileName[MAX_FILE_NAME];
    off_t size;
    time_t lastModified;
} FileMetadata;

void extractMetadata(const char *directoryPath, FileMetadata *fileList, int *fileCount);
void displayMetadata(const FileMetadata *fileList, int count);
void writeMetadataToFile(const FileMetadata *fileList, int count, const char *outputFile);
void analyzeMetadata(const FileMetadata *fileList, int count);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <directory-path> <output-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directoryPath = argv[1];
    const char *outputFile = argv[2];

    FileMetadata fileList[MAX_FILES];
    int fileCount = 0;

    extractMetadata(directoryPath, fileList, &fileCount);
    displayMetadata(fileList, fileCount);
    writeMetadataToFile(fileList, fileCount, outputFile);
    analyzeMetadata(fileList, fileCount);

    return EXIT_SUCCESS;
}

void extractMetadata(const char *directoryPath, FileMetadata *fileList, int *fileCount) {
    struct dirent *entry;
    struct stat fileStat;
    DIR *dp = opendir(directoryPath);

    if (dp == NULL) {
        fprintf(stderr, "Error opening directory: %s\n", strerror(errno));
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) {
            char filePath[MAX_FILE_NAME];
            snprintf(filePath, sizeof(filePath), "%s/%s", directoryPath, entry->d_name);

            if (stat(filePath, &fileStat) == 0) {
                if (*fileCount < MAX_FILES) {
                    strncpy(fileList[*fileCount].fileName, entry->d_name, MAX_FILE_NAME);
                    fileList[*fileCount].size = fileStat.st_size;
                    fileList[*fileCount].lastModified = fileStat.st_mtime;
                    (*fileCount)++;
                }
            }
        }
    }

    closedir(dp);
}

void displayMetadata(const FileMetadata *fileList, int count) {
    printf("File Metadata:\n");
    printf("%-30s %-10s %-25s\n", "File Name", "Size (bytes)", "Last Modified");
    for (int i = 0; i < count; i++) {
        char timeString[25];
        struct tm *tm_info = localtime(&fileList[i].lastModified);
        strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("%-30s %-10lld %-25s\n", fileList[i].fileName, (long long)fileList[i].size, timeString);
    }
}

void writeMetadataToFile(const FileMetadata *fileList, int count, const char *outputFile) {
    FILE *file = fopen(outputFile, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%lld,%ld\n", fileList[i].fileName, (long long)fileList[i].size, (long)fileList[i].lastModified);
    }

    fclose(file);
    printf("Metadata written to %s\n", outputFile);
}

void analyzeMetadata(const FileMetadata *fileList, int count) {
    printf("\nSize Analysis:\n");
    for (int i = 0; i < count; i++) {
        if (fileList[i].size > METADATA_DIFF) {
            printf("File %s exceeds threshold with size: %lld bytes\n", fileList[i].fileName, (long long)fileList[i].size);
        }
    }
}