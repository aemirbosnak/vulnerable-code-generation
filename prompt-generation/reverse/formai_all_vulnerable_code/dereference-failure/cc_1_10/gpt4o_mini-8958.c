//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LEN 512

// Function prototypes
void syncDirectories(const char *sourceDir, const char *destDir);
int isFileModified(const char *sourceFilePath, const char *destFilePath);
void copyFile(const char *sourceFilePath, const char *destFilePath);
void handleError(const char *message);

// Function to synchronize files between two directories
void syncDirectories(const char *sourceDir, const char *destDir) {
    struct dirent *entry;
    DIR *dir = opendir(sourceDir);
    if (dir == NULL) {
        handleError("Error opening source directory");
    }
    
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char sourceFilePath[MAX_PATH_LEN];
        char destFilePath[MAX_PATH_LEN];

        snprintf(sourceFilePath, sizeof(sourceFilePath), "%s/%s", sourceDir, entry->d_name);
        snprintf(destFilePath, sizeof(destFilePath), "%s/%s", destDir, entry->d_name);

        struct stat sourceStat;
        if (stat(sourceFilePath, &sourceStat) == -1) {
            handleError("Error getting file stats");
        }

        // Check if the entry is a file or a directory
        if (S_ISDIR(sourceStat.st_mode)) {
            // Create the corresponding directory in the destination
            mkdir(destFilePath, 0755);
            // Recursively synchronize directories
            syncDirectories(sourceFilePath, destFilePath);
        } else {
            // If it is a file, check if it needs to be copied
            if (!isFileModified(sourceFilePath, destFilePath)) {
                copyFile(sourceFilePath, destFilePath);
            }
        }
    }
    closedir(dir);
}

// Function to check if a file is modified
int isFileModified(const char *sourceFilePath, const char *destFilePath) {
    struct stat sourceStat, destStat;

    // Stat both source and destination files
    if (stat(sourceFilePath, &sourceStat) == -1) {
        handleError("Error getting source file stats");
        return 1; // Treat as modified if source stats cannot be obtained
    }

    // Check if destination file exists
    if (stat(destFilePath, &destStat) == -1) {
        // Destination file does not exist, it must be copied
        return 1;
    }

    // Compare modification times
    return sourceStat.st_mtime > destStat.st_mtime;
}

// Function to copy a file from source to destination
void copyFile(const char *sourceFilePath, const char *destFilePath) {
    FILE *sourceFile = fopen(sourceFilePath, "rb");
    if (sourceFile == NULL) {
        handleError("Error opening source file for copying");
    }

    FILE *destFile = fopen(destFilePath, "wb");
    if (destFile == NULL) {
        fclose(sourceFile);
        handleError("Error opening destination file for copying");
    }

    char buffer[4096];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);
    printf("Copied: %s to %s\n", sourceFilePath, destFilePath);
}

// Function to handle errors
void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source directory> <destination directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    syncDirectories(argv[1], argv[2]);
    printf("Synchronization complete!\n");
    return EXIT_SUCCESS;
}