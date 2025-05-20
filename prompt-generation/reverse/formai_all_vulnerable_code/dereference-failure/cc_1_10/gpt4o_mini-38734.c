//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void displayHelp() {
    printf("Welcome to the 'File Synchronizer 3000'!\n");
    printf("Usage: ./syncinator <source_directory> <destination_directory>\n");
    printf("This program will copy new and modified files from the source to the destination.\n");
}

void checkError(int condition, const char* message) {
    if (condition) {
        perror(message);
        exit(EXIT_FAILURE);
    }
}

void syncFile(const char* sourcePath, const char* destinationPath) {
    FILE *sourceFile = fopen(sourcePath, "rb");
    checkError(sourceFile == NULL, "Failed to open source file");

    FILE *destFile = fopen(destinationPath, "wb");
    checkError(destFile == NULL, "Failed to open destination file");

    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);
    printf("Synced: %s to %s\n", sourcePath, destinationPath);
}

void syncDirectory(const char* sourceDir, const char* destDir) {
    DIR *dir = opendir(sourceDir);
    checkError(dir == NULL, "Could not open source directory");

    struct dirent *entry;
    struct stat sourceStat, destStat;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip special entries
        }

        char sourcePath[MAX_PATH];
        char destPath[MAX_PATH];

        snprintf(sourcePath, sizeof(sourcePath), "%s/%s", sourceDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

        if (stat(sourcePath, &sourceStat) == -1) {
            perror("Can't get source file stats");
            continue;
        }

        // Check if it's a directory
        if (S_ISDIR(sourceStat.st_mode)) {
            // Create destination directory if it doesn't exist
            mkdir(destPath, 0755);
            syncDirectory(sourcePath, destPath); // Recursively sync directories
        } else {
            // It's a file, check if it needs syncing
            if (stat(destPath, &destStat) == -1) {
                // If destination file doesn't exist, sync it
                syncFile(sourcePath, destPath);
            } else if (sourceStat.st_mtime > destStat.st_mtime) {
                // If source file is newer, sync it
                syncFile(sourcePath, destPath);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        displayHelp();
        return EXIT_FAILURE;
    }

    const char* sourceDir = argv[1];
    const char* destDir = argv[2];

    struct stat sourceStat;
    if (stat(sourceDir, &sourceStat) == -1 || !S_ISDIR(sourceStat.st_mode)) {
        fprintf(stderr, "Error: %s is not a valid directory.\n", sourceDir);
        return EXIT_FAILURE;
    }

    struct stat destStat;
    if (stat(destDir, &destStat) == -1) {
        // If destination doesn't exist, create it
        mkdir(destDir, 0755);
    } else if (!S_ISDIR(destStat.st_mode)) {
        fprintf(stderr, "Error: %s is not a valid directory.\n", destDir);
        return EXIT_FAILURE;
    }

    syncDirectory(sourceDir, destDir);
    printf("Synchronization completed successfully!\n");
    return EXIT_SUCCESS;
}