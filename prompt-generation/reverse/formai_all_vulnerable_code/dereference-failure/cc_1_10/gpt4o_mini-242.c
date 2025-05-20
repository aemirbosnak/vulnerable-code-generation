//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Function prototypes
void syncFiles(const char *srcDir, const char *destDir);
void copyFile(const char *srcFile, const char *destFile);
int isFileUpdated(const char *srcFile, const char *destFile);
void createDirIfNotExists(const char *dirName);
void printUsage(const char *programName);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *srcDir = argv[1];
    const char *destDir = argv[2];

    syncFiles(srcDir, destDir);
    printf("Synchronization complete from %s to %s\n", srcDir, destDir);
    return EXIT_SUCCESS;
}

void printUsage(const char *programName) {
    printf("Usage: %s <source_directory> <destination_directory>\n", programName);
}

void syncFiles(const char *srcDir, const char *destDir) {
    DIR *dir = opendir(srcDir);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Failed to open source directory");
        exit(EXIT_FAILURE);
    }

    createDirIfNotExists(destDir);

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Skip hidden files and directories
        }

        char srcFilePath[1024];
        char destFilePath[1024];
        snprintf(srcFilePath, sizeof(srcFilePath), "%s/%s", srcDir, entry->d_name);
        snprintf(destFilePath, sizeof(destFilePath), "%s/%s", destDir, entry->d_name);

        struct stat fileInfo;
        if (stat(srcFilePath, &fileInfo) == -1) {
            perror("Failed to get file status");
            continue;
        }

        if (S_ISDIR(fileInfo.st_mode)) {
            // If it's a directory, call syncFiles recursively
            syncFiles(srcFilePath, destFilePath);
        } else {
            // If it's a file, check if it needs to be updated
            if (isFileUpdated(srcFilePath, destFilePath)) {
                copyFile(srcFilePath, destFilePath);
            }
        }
    }

    closedir(dir);
}

void copyFile(const char *srcFile, const char *destFile) {
    FILE *src = fopen(srcFile, "rb");
    FILE *dest = fopen(destFile, "wb");

    if (src == NULL || dest == NULL) {
        perror("Failed to open file");
        if (src) fclose(src);
        if (dest) fclose(dest);
        return;
    }

    char buffer[8192];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(src);
    fclose(dest);
    printf("Copied: %s to %s\n", srcFile, destFile);
}

int isFileUpdated(const char *srcFile, const char *destFile) {
    struct stat srcStat, destStat;

    if (stat(srcFile, &srcStat) == -1) {
        perror("Failed to get source file status");
        return 0;
    }

    if (stat(destFile, &destStat) == -1) {
        // If the destination file doesn't exist, consider it updated
        return 1;
    }

    // Compare modification times
    return srcStat.st_mtime > destStat.st_mtime;
}

void createDirIfNotExists(const char *dirName) {
    struct stat st;
    if (stat(dirName, &st) == -1) {
        if (mkdir(dirName, 0755) == -1) {
            perror("Failed to create directory");
            exit(EXIT_FAILURE);
        }
    }
}