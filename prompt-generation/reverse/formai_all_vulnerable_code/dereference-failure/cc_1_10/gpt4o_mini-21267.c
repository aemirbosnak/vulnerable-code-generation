//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void printUsage(long totalSize, long usedSize) {
    long availableSize = totalSize - usedSize;
    printf("\nDisk space usage summary:\n");
    printf("Total size: %ld bytes\n", totalSize);
    printf("Used size: %ld bytes\n", usedSize);
    printf("Available size: %ld bytes\n", availableSize);
}

long getDirectorySize(const char *dirPath) {
    long totalSize = 0;
    struct dirent *entry;
    struct stat fileStats;
    DIR *directory = opendir(dirPath);
    
    if (!directory) {
        perror("Unable to open directory");
        return -1;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char fullPath[1024];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
            if (stat(fullPath, &fileStats) == 0) {
                if (S_ISDIR(fileStats.st_mode)) {
                    long dirSize = getDirectorySize(fullPath);
                    if (dirSize != -1) {
                        totalSize += dirSize;
                    }
                } else {
                    totalSize += fileStats.st_size;
                }
            } else {
                perror("Failed to get file stats");
            }
        }
    }

    closedir(directory);
    return totalSize;
}

void analyzeDiskSpace(const char *startPath) {
    struct stat rootStats;
    long totalSpace = 0;
    
    if (stat(startPath, &rootStats) != 0) {
        perror("Unable to get stats of the root directory");
        return;
    }

    totalSpace = rootStats.st_blocks * 512;

    long usedSpace = getDirectorySize(startPath);
    if (usedSpace != -1) {
        printUsage(totalSpace, usedSpace);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory-path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directoryPath = argv[1];
    printf("Analyzing disk space for directory: %s\n", directoryPath);
    analyzeDiskSpace(directoryPath);

    return EXIT_SUCCESS;
}