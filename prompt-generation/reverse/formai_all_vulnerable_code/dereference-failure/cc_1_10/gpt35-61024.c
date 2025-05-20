//FormAI DATASET v1.0 Category: File Synchronizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PATH_LENGTH 256

/**
 * Synchronize two directories by copying new and modified files from one to the other.
 * @param srcDir The source directory.
 * @param destDir The destination directory.
 */
void synchronizeDirs(const char* srcDir, const char* destDir);

/**
 * Copy a file from the source directory to the destination directory.
 * @param srcPath The path of the source file.
 * @param destPath The path of the destination file.
 */
void copyFile(const char* srcPath, const char* destPath);

/**
 * Check if a file should be copied from the source to the destination.
 * @param srcPath The path of the source file.
 * @param destPath The path of the destination file.
 * @return True if the file needs to be copied, false otherwise.
 */
bool shouldCopy(const char* srcPath, const char* destPath);

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: file_synchronizer <src_dir> <dest_dir>\n");
        exit(EXIT_FAILURE);
    }

    const char* srcDir = argv[1];
    const char* destDir = argv[2];

    synchronizeDirs(srcDir, destDir);

    printf("Synchronization complete.\n");

    return EXIT_SUCCESS;
}

void synchronizeDirs(const char* srcDir, const char* destDir) {
    DIR* src = opendir(srcDir);
    DIR* dest = opendir(destDir);

    if (!src || !dest) {
        fprintf(stderr, "Failed to open directories!\n");
        exit(EXIT_FAILURE);
    }

    struct dirent* entry;
    struct stat srcStat, destStat;

    char srcPath[MAX_PATH_LENGTH], destPath[MAX_PATH_LENGTH];

    while ((entry = readdir(src))) {
        // ignore . and .. directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(srcPath, MAX_PATH_LENGTH, "%s/%s", srcDir, entry->d_name);
        snprintf(destPath, MAX_PATH_LENGTH, "%s/%s", destDir, entry->d_name);

        if (stat(srcPath, &srcStat) < 0) {
            perror("stat");
            continue;
        }

        // if file does not exist in destination or has been modified since last sync
        if (stat(destPath, &destStat) < 0 || srcStat.st_mtime > destStat.st_mtime) {
            if (shouldCopy(srcPath, destPath)) {
                copyFile(srcPath, destPath);
                printf("Copied file %s to %s\n", srcPath, destPath);
            }
        }
    }

    closedir(src);
    closedir(dest);
}

void copyFile(const char* srcPath, const char* destPath) {
    FILE* srcFile = fopen(srcPath, "rb");
    FILE* destFile = fopen(destPath, "wb");

    if (!srcFile || !destFile) {
        fprintf(stderr, "Failed to open files for copying!\n");
        exit(EXIT_FAILURE);
    }

    char buffer[4096];
    size_t bytes;

    while ((bytes = fread(buffer, sizeof(char), sizeof(buffer), srcFile))) {
        fwrite(buffer, sizeof(char), bytes, destFile);
    }

    fclose(srcFile);
    fclose(destFile);
}

bool shouldCopy(const char* srcPath, const char* destPath) {
    struct stat srcStat, destStat;

    if (stat(srcPath, &srcStat) < 0 || stat(destPath, &destStat) < 0) {
        return true;
    }

    if (srcStat.st_size != destStat.st_size) {
        return true;
    }

    FILE* srcFile = fopen(srcPath, "rb");
    FILE* destFile = fopen(destPath, "rb");

    if (!srcFile || !destFile) {
        fprintf(stderr, "Failed to open files for comparison!\n");
        exit(EXIT_FAILURE);
    }

    char srcBuffer[4096], destBuffer[4096];
    size_t srcBytes, destBytes;

    while ((srcBytes = fread(srcBuffer, sizeof(char), sizeof(srcBuffer), srcFile))) {
        destBytes = fread(destBuffer, sizeof(char), sizeof(destBuffer), destFile);

        if (destBytes != srcBytes || memcmp(srcBuffer, destBuffer, srcBytes) != 0) {
            fclose(srcFile);
            fclose(destFile);
            return true;
        }
    }

    fclose(srcFile);
    fclose(destFile);
    return false;
}