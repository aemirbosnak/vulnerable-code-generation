//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

// Function to get the size of a file
long getFileSize(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return path_stat.st_size;
}

// Function to recursively analyze the disk space of the directory
void analyzeDiskSpace(const char *dirPath, long *totalSize, long *totalFiles) {
    DIR *dir;
    struct dirent *entry;

    // Open the directory
    if (!(dir = opendir(dirPath))) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the '.' and '..' entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char fullPath[MAX_PATH];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);

            // Check if the entry is a directory
            if (entry->d_type == DT_DIR) {
                long nestedSize = 0;
                long nestedFiles = 0;

                // Recursively analyze nested directories
                analyzeDiskSpace(fullPath, &nestedSize, &nestedFiles);
                *totalSize += nestedSize;
                *totalFiles += nestedFiles;

                printf("Entering directory: %s\n", fullPath);
            } else {
                // It's a file, get its size and count it
                long fileSize = getFileSize(fullPath);
                *totalSize += fileSize;
                (*totalFiles)++;

                printf("Found file: %s (Size: %ld bytes)\n", fullPath, fileSize);
            }
        }
    }

    closedir(dir);
}

// Function to convert bytes to a human-readable format
void humanReadable(long size, char *buffer) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int unitIndex = 0;
    
    while (size >= 1024 && unitIndex < 4) {
        size /= 1024;
        unitIndex++;
    }
    
    snprintf(buffer, 20, "%ld %s", size, units[unitIndex]);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long totalSize = 0;
    long totalFiles = 0;

    // Start analyzing the disk space
    printf("Analyzing disk space for directory: %s\n", argv[1]);
    analyzeDiskSpace(argv[1], &totalSize, &totalFiles);

    // Print out the results
    char sizeStr[20];
    humanReadable(totalSize, sizeStr);

    printf("\nTotal number of files: %ld\n", totalFiles);
    printf("Total disk space used: %s\n", sizeStr);
    
    return EXIT_SUCCESS;
}