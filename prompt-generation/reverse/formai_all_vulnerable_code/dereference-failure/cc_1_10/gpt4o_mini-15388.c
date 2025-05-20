//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void copyFile(const char *src, const char *dest) {
    FILE *srcFile = fopen(src, "rb");
    if (srcFile == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE *destFile = fopen(dest, "wb");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(srcFile);
        return;
    }

    char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(srcFile);
    fclose(destFile);
}

int isFileModified(const char *src, const char *dest) {
    struct stat srcStat, destStat;

    if (stat(src, &srcStat) != 0 || stat(dest, &destStat) != 0) {
        return 1;  // Consider it modified if destination doesn't exist
    }

    return srcStat.st_mtime > destStat.st_mtime; // Compare modification times
}

void syncFiles(const char *srcDir, const char *destDir) {
    DIR *dir = opendir(srcDir);
    if (dir == NULL) {
        perror("Error opening source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files and directories

        char srcPath[MAX_PATH];
        char destPath[MAX_PATH];

        snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

        struct stat entryStat;
        if (stat(srcPath, &entryStat) != 0) {
            perror("Error getting file stats");
            continue;
        }

        if (S_ISDIR(entryStat.st_mode)) {
            // Create destination directory if it doesn't exist
            mkdir(destPath, 0755);
            // Recursive call to sync subdirectory
            syncFiles(srcPath, destPath);
        } else if (S_ISREG(entryStat.st_mode)) {
            // Check if file has been modified
            if (isFileModified(srcPath, destPath)) {
                printf("Copying %s to %s\n", srcPath, destPath);
                copyFile(srcPath, destPath);
            }
        }
    }

    closedir(dir);
}

void showUsage() {
    printf("File Synchronizer Utility\n");
    printf("Usage: ./sync <source_directory> <destination_directory>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        showUsage();
        return EXIT_FAILURE;
    }

    const char *srcDir = argv[1];
    const char *destDir = argv[2];

    struct stat srcStat;
    if (stat(srcDir, &srcStat) != 0 || !S_ISDIR(srcStat.st_mode)) {
        fprintf(stderr, "Source path is not a valid directory: %s\n", srcDir);
        return EXIT_FAILURE;
    }

    struct stat destStat;
    if (stat(destDir, &destStat) != 0 || !S_ISDIR(destStat.st_mode)) {
        fprintf(stderr, "Destination path is not a valid directory: %s\n", destDir);
        return EXIT_FAILURE;
    }

    syncFiles(srcDir, destDir);
    printf("Synchronization completed from %s to %s\n", srcDir, destDir);
    return EXIT_SUCCESS;
}