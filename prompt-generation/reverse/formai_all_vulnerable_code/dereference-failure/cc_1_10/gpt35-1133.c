//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

// Define constants for different file sizes
#define SIZE_KB 1024
#define SIZE_MB 1048576
#define SIZE_GB 1073741824

// Function to get file size and format it
const char *formatSize(off_t size) {
    char *formatted = (char *)malloc(32 * sizeof(char));
    if (size < SIZE_KB) {
        sprintf(formatted, "%lu B", size);
    } else if (size >= SIZE_KB && size < SIZE_MB) {
        sprintf(formatted, "%.2f KB", (float)size / SIZE_KB);
    } else if (size >= SIZE_MB && size < SIZE_GB) {
        sprintf(formatted, "%.2f MB", (float)size / SIZE_MB);
    } else {
        sprintf(formatted, "%.2f GB", (float)size / SIZE_GB);
    }
    return formatted;
}

// Function to analyze a directory
void analyzeDirectory(const char *path, off_t *totalSize, int *fileCount, int *dirCount) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory: %s\n", path);
        return;
    }

    struct dirent *currentDir;
    while ((currentDir = readdir(dir)) != NULL) {
        char *currentPath = (char *)malloc(strlen(path) + strlen(currentDir->d_name) + 2);
        sprintf(currentPath, "%s/%s", path, currentDir->d_name);

        struct stat info;
        if (stat(currentPath, &info) == -1) {
            printf("Error getting file info: %s\n", currentDir->d_name);
            continue;
        }

        if (S_ISDIR(info.st_mode)) {
            // Current item is a directory
            if (strcmp(currentDir->d_name, ".") == 0 || strcmp(currentDir->d_name, "..") == 0) {
                continue;
            }
            // Analyze subdirectory
            (*dirCount)++;
            analyzeDirectory(currentPath, totalSize, fileCount, dirCount);
        } else {
            // Current item is a file
            (*fileCount)++;
            *totalSize += info.st_size;
        }
        free(currentPath);
    }
    closedir(dir);
}

int main() {
    // Initialize important variables
    off_t totalSize = 0;
    int fileCount = 0;
    int dirCount = 0;

    // Analyze current directory
    analyzeDirectory(".", &totalSize, &fileCount, &dirCount);

    // Print results
    printf("Total size of all files in directory: %s\n", formatSize(totalSize));
    printf("Number of files in directory: %d\n", fileCount);
    printf("Number of directories in directory: %d\n", dirCount);

    return 0;
}