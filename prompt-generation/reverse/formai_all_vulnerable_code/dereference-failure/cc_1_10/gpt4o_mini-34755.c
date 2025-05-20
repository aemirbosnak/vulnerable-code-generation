//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void printUsage(const char *progName) {
    printf("Usage: %s <source_directory> <target_directory>\n", progName);
}

int isRegularFile(const char *path) {
    struct stat pathStat;
    stat(path, &pathStat);
    return S_ISREG(pathStat.st_mode);
}

void synchronizeFile(const char *sourceFile, const char *targetFile) {
    FILE *src = fopen(sourceFile, "rb");
    FILE *dst = fopen(targetFile, "wb");
    if (!src || !dst) {
        perror("Error opening file during synchronization");
        if (src) fclose(src);
        if (dst) fclose(dst);
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dst);
    }

    fclose(src);
    fclose(dst);
}

void syncDirectory(const char *sourceDir, const char *targetDir) {
    DIR *dir = opendir(sourceDir);
    if (!dir) {
        perror("Failed to open source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // skip . and ..
        }

        char sourcePath[MAX_PATH];
        char targetPath[MAX_PATH];

        snprintf(sourcePath, sizeof(sourcePath), "%s/%s", sourceDir, entry->d_name);
        snprintf(targetPath, sizeof(targetPath), "%s/%s", targetDir, entry->d_name);
        
        if (isRegularFile(sourcePath)) {
            synchronizeFile(sourcePath, targetPath);
            printf("Synchronized: %s to %s\n", sourcePath, targetPath);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *sourceDir = argv[1];
    const char *targetDir = argv[2];
    
    struct stat st = {0};
    if (stat(targetDir, &st) == -1) {
        if (mkdir(targetDir, 0700) == -1) {
            perror("Failed to create target directory");
            return EXIT_FAILURE;
        }
    }

    printf("Starting synchronization from '%s' to '%s'\n", sourceDir, targetDir);
    syncDirectory(sourceDir, targetDir);
    printf("Synchronization completed.\n");

    return EXIT_SUCCESS;
}