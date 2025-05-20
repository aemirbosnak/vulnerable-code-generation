//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void displayUsage() {
    printf("Usage: ./disk_analyzer <directory>\n");
    printf("This program analyzes disk space in the specified directory.\n");
}

long long calculateDirectorySize(const char *dirPath, int *fileCount) {
    struct dirent *entry;
    struct stat fileStat;
    long long totalSize = 0;
    
    DIR *directory = opendir(dirPath);
    if (!directory) {
        perror("Could not open directory");
        return -1;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_name[0] == '.') {
            // Skip hidden files and directories
            continue;
        }

        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
        
        if (stat(fullPath, &fileStat) == -1) {
            perror("Could not get file stats");
            continue;
        }
        
        if (S_ISDIR(fileStat.st_mode)) {
            // For directories, recurse into the directory and add its size
            int count = 0;
            long long dirSize = calculateDirectorySize(fullPath, &count);
            if (dirSize != -1) {
                totalSize += dirSize;
                *fileCount += count;
            }
        } else {
            // It's a file; add its size
            totalSize += fileStat.st_size;
            (*fileCount)++;
        }
    }

    closedir(directory);
    return totalSize;
}

void displayAnalysis(const char *dirPath) {
    int fileCount = 0;
    long long totalSize = calculateDirectorySize(dirPath, &fileCount);
    
    if (totalSize == -1) {
        printf("Failed to analyze the directory.\n");
        return;
    }

    printf("\nDisk Space Analysis for: %s\n", dirPath);
    printf("======================================\n");
    printf("Total Number of Files: %d\n", fileCount);
    printf("Total Space Used: %lld bytes\n", totalSize);
    
    // Additional statistics could be calculated here, like average file size.
    if (fileCount > 0) {
        printf("Average File Size: %.2f bytes\n", (double)totalSize / fileCount);
    }
    printf("======================================\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        displayUsage();
        return EXIT_FAILURE;
    }

    char *targetDir = argv[1];
    
    // Check if the specified path is valid
    if (access(targetDir, F_OK) == -1) {
        fprintf(stderr, "Error: Directory '%s' does not exist!\n", targetDir);
        return EXIT_FAILURE;
    }

    printf("Analyzing directory: '%s'...\n", targetDir);
    displayAnalysis(targetDir);
    
    return EXIT_SUCCESS;
}