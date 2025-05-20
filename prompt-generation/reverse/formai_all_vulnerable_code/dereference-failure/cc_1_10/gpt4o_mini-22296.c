//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>

#define MAX_PATH_LEN 4096
#define CMD_SIZE 512

void analyzeDiskSpace(const char *path);
void displayDiskUsage(const struct statvfs *stat);
void getDirectoryUsage(const char *path, size_t *totalFiles, size_t *totalSize);
void printUsage(size_t totalFiles, size_t totalSize, const char *path);

int main(int argc, char *argv[]) {
    char path[MAX_PATH_LEN];
    
    // Use default path if no arguments are provided
    if (argc < 2) {
        printf("No directory specified. Analyzing current directory.\n");
        strcpy(path, ".");
    } else {
        strncpy(path, argv[1], MAX_PATH_LEN - 1);
        path[MAX_PATH_LEN - 1] = '\0'; // Ensure null termination
    }
    
    // Disk space analysis
    analyzeDiskSpace(path);
    
    return 0;
}

void analyzeDiskSpace(const char *path) {
    struct statvfs stat;
    
    // Fetch filesystem statistics for the given path
    if (statvfs(path, &stat) != 0) {
        perror("Failed to get disk space information");
        exit(EXIT_FAILURE);
    }

    // Display disk usage information
    displayDiskUsage(&stat);

    // Analyze directory content
    size_t totalFiles = 0;
    size_t totalSize = 0;
    getDirectoryUsage(path, &totalFiles, &totalSize);
    
    // Print total files and size
    printUsage(totalFiles, totalSize, path);
}

void displayDiskUsage(const struct statvfs *stat) {
    unsigned long totalDiskSpace = stat->f_blocks * stat->f_frsize;
    unsigned long freeDiskSpace = stat->f_bfree * stat->f_frsize;
    unsigned long usedDiskSpace = totalDiskSpace - freeDiskSpace;

    printf("\n=== Disk Usage for Filesystem ===\n");
    printf("Total Disk Space: %lu bytes\n", totalDiskSpace);
    printf("Used Disk Space: %lu bytes\n", usedDiskSpace);
    printf("Free Disk Space: %lu bytes\n", freeDiskSpace);
    printf("Used Percentage: %.2f%%\n", (double)usedDiskSpace / totalDiskSpace * 100);
    printf("===================================\n");
}

void getDirectoryUsage(const char *path, size_t *totalFiles, size_t *totalSize) {
    FILE *fp;
    char command[CMD_SIZE];

    // Constructing a command to find total files and size in the directory
    snprintf(command, CMD_SIZE, "find \"%s\" -type f -printf '%%s\\n' | awk '{sum += $1} END {print sum}' > total_size.txt && find \"%s\" -type f | wc -l > total_files.txt", path, path);
    
    // Execute command to get total file size and count
    system(command);

    // Read total size
    fp = fopen("total_size.txt", "r");
    if (fp == NULL) {
        perror("Failed to read total size");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%zu", totalSize);
    fclose(fp);
    
    // Read total files
    fp = fopen("total_files.txt", "r");
    if (fp == NULL) {
        perror("Failed to read total files");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%zu", totalFiles);
    fclose(fp);
    
    // Clean up: Remove temporary files
    remove("total_size.txt");
    remove("total_files.txt");
}

void printUsage(size_t totalFiles, size_t totalSize, const char *path) {
    printf("\n=== Directory Usage in %s ===\n", path);
    printf("Total Files: %zu\n", totalFiles);
    printf("Total Size: %zu bytes\n", totalSize);
    printf("===================================\n");
}