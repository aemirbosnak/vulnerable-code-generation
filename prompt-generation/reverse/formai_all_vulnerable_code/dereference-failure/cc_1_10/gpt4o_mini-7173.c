//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 256
#define BUFFER_SIZE 1024

void printHeader() {
    printf("=================================\n");
    printf("      Retro File Synchronizer\n");
    printf("=================================\n");
}

void copyFile(const char *srcPath, const char *destPath) {
    FILE *srcFile = fopen(srcPath, "rb");
    FILE *destFile = fopen(destPath, "wb");
    
    if (srcFile == NULL || destFile == NULL) {
        perror("File operation failed");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(srcFile);
    fclose(destFile);
}

int fileExists(const char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

int filesAreDifferent(const char *file1, const char *file2) {
    struct stat stat1, stat2;
    stat(file1, &stat1);
    stat(file2, &stat2);
    return stat1.st_mtime != stat2.st_mtime || stat1.st_size != stat2.st_size;
}

void synchronizeFiles(const char *srcDir, const char *destDir) {
    DIR *srcDirPtr = opendir(srcDir);
    struct dirent *entry;

    if (srcDirPtr == NULL) {
        perror("Failed to open source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(srcDirPtr)) != NULL) {
        if (entry->d_name[0] == '.') // Skip hidden files
            continue;

        char srcPath[MAX_PATH];
        char destPath[MAX_PATH];

        snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

        if (!fileExists(destPath) || filesAreDifferent(srcPath, destPath)) {
            printf("Copying %s to %s...\n", srcPath, destPath);
            copyFile(srcPath, destPath);
        }
    }
    
    closedir(srcDirPtr);
}

int main(int argc, char *argv[]) {
    printHeader();

    if (argc != 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    synchronizeFiles(argv[1], argv[2]);

    printf("Synchronization complete!\n");
    return EXIT_SUCCESS;
}