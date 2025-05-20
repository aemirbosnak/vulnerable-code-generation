//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

void syncFiles(const char *sourceDir, const char *destDir);
void copyFile(const char *srcFile, const char *destFile);
int isModified(const char *srcFile, const char *destFile);
void createDirIfNotExists(const char *path);
void printUsage();

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printUsage();
        return EXIT_FAILURE;
    }

    const char *sourceDir = argv[1];
    const char *destDir = argv[2];

    syncFiles(sourceDir, destDir);

    printf("File synchronization complete!\n");
    return EXIT_SUCCESS;
}

void syncFiles(const char *sourceDir, const char *destDir) {
    DIR *dir = opendir(sourceDir);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Failed to open source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        // Ignore current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;

        char srcPath[MAX_PATH_LENGTH];
        char destPath[MAX_PATH_LENGTH];
        snprintf(srcPath, sizeof(srcPath), "%s/%s", sourceDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

        struct stat fileInfo;
        if (stat(srcPath, &fileInfo) == -1) {
            perror("Failed to get file info");
            continue;
        }

        if (S_ISDIR(fileInfo.st_mode)) {
            createDirIfNotExists(destPath);
            syncFiles(srcPath, destPath); // Recurse into subdirectory
        } else if (S_ISREG(fileInfo.st_mode)) {
            if (!isModified(srcPath, destPath)) {
                printf("Copying new or modified file: %s\n", srcPath);
                copyFile(srcPath, destPath);
            }
        }
    }

    closedir(dir);
}

void copyFile(const char *srcFile, const char *destFile) {
    FILE *src = fopen(srcFile, "rb");
    FILE *dest = fopen(destFile, "wb");

    if (!src || !dest) {
        perror("Failed to open files for copying");
        if (src) fclose(src);
        return;
    }

    char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(src);
    fclose(dest);
}

int isModified(const char *srcFile, const char *destFile) {
    struct stat srcStat, destStat;

    if (stat(srcFile, &srcStat) == -1) {
        perror("Failed to get source file info");
        return 1; // Assume modified if we can't read
    }

    if (stat(destFile, &destStat) == -1) {
        return 1; // Destination does not exist, so it's considered modified
    }

    return srcStat.st_mtime > destStat.st_mtime; // Return true if source is newer
}

void createDirIfNotExists(const char *path) {
    struct stat st;
    if (stat(path, &st) == -1) {
        if (mkdir(path, 0755) == -1) {
            perror("Failed to create destination directory");
        }
    }
}

void printUsage() {
    fprintf(stderr, "Usage: ./sync <source_directory> <destination_directory>\n");
}