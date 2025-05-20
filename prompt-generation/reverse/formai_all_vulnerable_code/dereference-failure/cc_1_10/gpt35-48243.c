//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MB (1048576) // 1 MB = 1048576 bytes

long long getDirSize(char *dirPath);
long long getFileSize(char *filePath);
long long calculateSize(char *path);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    char *path = argv[1];

    long long size = calculateSize(path);
    printf("Total size of '%s' is %.2f MB\n", path, (double)size / MB);

    return 0;
}

/**
 * Calculates the total size of a file or directory recursively.
 */
long long calculateSize(char *path) {
    struct stat statBuf;

    if (lstat(path, &statBuf) == -1) {
        printf("Error: '%s' does not exist or cannot be accessed\n", path);
        exit(1);
    }

    if (S_ISREG(statBuf.st_mode)) { // regular file
        return getFileSize(path);
    } else if (S_ISDIR(statBuf.st_mode)) { // directory
        return getDirSize(path);
    } else { // symbolic link, socket, device file, etc
        return 0;
    }
}

/**
 * Calculates the total size of a directory recursively.
 */
long long getDirSize(char *dirPath) {
    long long size = 0;

    DIR *dir = opendir(dirPath);
    if (!dir) {
        printf("Error: '%s' cannot be opened as a directory\n", dirPath);
        exit(1);
    }

    struct dirent *entry;
    while ((entry = readdir(dir))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            // ignore '.' and '..' entries
            continue;
        }

        char path[strlen(dirPath) + strlen(entry->d_name) + 2];
        sprintf(path, "%s/%s", dirPath, entry->d_name);
        size += calculateSize(path);
    }

    closedir(dir);
    return size;
}

/**
 * Calculates the size of a file.
 */
long long getFileSize(char *filePath) {
    struct stat statBuf;

    if (lstat(filePath, &statBuf) == -1) {
        printf("Warning: '%s' cannot be accessed\n", filePath);
        return 0;
    }

    return statBuf.st_size;
}