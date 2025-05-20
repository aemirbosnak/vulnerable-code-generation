//FormAI DATASET v1.0 Category: File Synchronizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

// Function declarations
void syncDirectories(const char *src, const char *dest);
void syncFiles(const char *src, const char *dest);
int copyFile(const char *src, const char *dest);
void deleteFile(const char *path);

int main(int argc, char *argv[]) {
    // Check if program was called with two arguments
    if (argc != 3) {
        printf("Usage: %s [source directory] [destination directory]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *srcDir = argv[1];
    char *destDir = argv[2];

    syncDirectories(srcDir, destDir);

    return 0;
}

// Synchronize two directories
void syncDirectories(const char *src, const char *dest) {
    DIR *srcDir = opendir(src);
    if (srcDir == NULL) {
        printf("Error: Could not open source directory %s - %s\n", src, strerror(errno));
        exit(EXIT_FAILURE);
    }

    DIR *destDir = opendir(dest);
    if (destDir == NULL) {
        printf("Error: Could not open destination directory %s - %s\n", dest, strerror(errno));
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(srcDir))) {
        // Skip current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char srcPath[PATH_MAX];
        snprintf(srcPath, PATH_MAX, "%s/%s", src, entry->d_name);

        char destPath[PATH_MAX];
        snprintf(destPath, PATH_MAX, "%s/%s", dest, entry->d_name);

        // Check if file/directory exists in destination directory
        struct stat srcStat;
        stat(srcPath, &srcStat);

        struct stat destStat;
        if (stat(destPath, &destStat) == -1) {
            // File/directory does not exist in destination directory
            if (S_ISDIR(srcStat.st_mode)) {
                // Directory - create directory in destination and synchronize contents
                if (mkdir(destPath, srcStat.st_mode) != 0) {
                    printf("Error: Could not create directory %s - %s\n", destPath, strerror(errno));
                } else {
                    syncDirectories(srcPath, destPath);
                }
            } else {
                // File - copy file to destination
                if (copyFile(srcPath, destPath) == -1) {
                    printf("Error: Could not copy file %s to %s - %s\n", srcPath, destPath, strerror(errno));
                }
            }
        } else {
            // File/directory exists in destination directory
            if (S_ISDIR(srcStat.st_mode)) {
                // Directory - synchronize contents with destination directory
                syncDirectories(srcPath, destPath);
            } else {
                // File - check if file needs to be updated
                if (srcStat.st_mtime > destStat.st_mtime) {
                    if (copyFile(srcPath, destPath) == -1) {
                        printf("Error: Could not copy file %s to %s - %s\n", srcPath, destPath, strerror(errno));
                    }
                }
            }
        }
    }

    closedir(srcDir);
    closedir(destDir);
}

// Synchronize one file
void syncFiles(const char *src, const char *dest) {
    struct stat srcStat;
    stat(src, &srcStat);

    struct stat destStat;
    if (stat(dest, &destStat) == -1) {
        // File does not exist in destination directory - copy file
        copyFile(src, dest);
    } else {
        if (srcStat.st_mtime > destStat.st_mtime) {
            // Source file has been modified after destination file - copy file
            copyFile(src, dest);
        }
    }
}

// Copy one file
int copyFile(const char *src, const char *dest) {
    FILE *srcFile = fopen(src, "r");
    if (srcFile == NULL) {
        printf("Error: Could not open file %s - %s\n", src, strerror(errno));
        return -1;
    }

    FILE *destFile = fopen(dest, "w");
    if (destFile == NULL) {
        printf("Error: Could not create file %s - %s", dest, strerror(errno));
        return -1;
    }

    char buffer[4096];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
        fwrite(buffer, 1, bytes, destFile);
    }

    fclose(srcFile);
    fclose(destFile);

    // Copy source file permissions to destination file
    struct stat srcStat;
    stat(src, &srcStat);

    if (chmod(dest, srcStat.st_mode) == -1) {
        printf("Error: Could not set permissions for file %s - %s\n", dest, strerror(errno));
    }

    return 0;
}

// Delete one file
void deleteFile(const char *path) {
    if (remove(path) == -1) {
        printf("Error: Could not delete file %s - %s", path, strerror(errno));
    }
}