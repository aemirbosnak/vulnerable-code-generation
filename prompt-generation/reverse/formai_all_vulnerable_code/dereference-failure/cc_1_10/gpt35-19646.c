//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>

// Function prototypes
void analyzeDirectory(char* path);
void printUsage();

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printUsage();
        exit(EXIT_FAILURE);
    }

    char* path = argv[1];
    analyzeDirectory(path);

    return 0;
}

// Recursively analyzes a directory and its subdirectories for file size information
void analyzeDirectory(char* path) {
    DIR* directory = opendir(path);
    if (directory == NULL) {
        fprintf(stderr, "Error opening directory %s\n", path);
        return;
    }

    struct dirent* dirEntry;
    struct stat st;

    long long totalSize = 0; // Total size of files in directory and subdirectories
    bool hasSubdirs = false; // Boolean indicating if directory has subdirectories

    while ((dirEntry = readdir(directory)) != NULL) {
        // Ignore current and parent directory entries
        if (strcmp(dirEntry->d_name, ".") == 0 || strcmp(dirEntry->d_name, "..") == 0) {
            continue;
        }

        char filePath[256];
        sprintf(filePath, "%s/%s", path, dirEntry->d_name);

        if (lstat(filePath, &st) == -1) {
            fprintf(stderr, "Error getting file stats for %s\n", filePath);
            continue;
        }

        // If directory, recursively call function on it
        if (S_ISDIR(st.st_mode)) {
            analyzeDirectory(filePath);
            hasSubdirs = true;
        }
        // If file, add its size to totalSize
        else if (S_ISREG(st.st_mode)) {
            totalSize += st.st_size;
        }
    }

    closedir(directory);

    if (hasSubdirs) {
        printf("\nDirectory %s:\n", path);
    }

    // Print directory size information
    printf("Total size: %lld bytes\n", totalSize);
    printf("-----------------\n");
}

// Prints usage information if invalid command line input is given
void printUsage() {
    printf("Usage: diskanalyzer <directory path>\n");
}