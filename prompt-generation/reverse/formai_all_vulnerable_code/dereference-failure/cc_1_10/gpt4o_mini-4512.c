//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH 1024

void calculateDiskUsage(const char *basePath, long long *totalSize);
void printDiskUsage(const char *path, long long size);

int main(int argc, char *argv[]) {
    long long totalSize = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Start calculating the disk usage
    calculateDiskUsage(argv[1], &totalSize);

    // Print the total disk usage
    printDiskUsage(argv[1], totalSize);

    return EXIT_SUCCESS;
}

void calculateDiskUsage(const char *basePath, long long *totalSize) {
    struct stat stats;
    struct dirent *entry;
    DIR *dp;
    char path[MAX_PATH];

    dp = opendir(basePath);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the path
        snprintf(path, sizeof(path), "%s/%s", basePath, entry->d_name);
        
        // Get the stats for the current entry
        if (stat(path, &stats) == -1) {
            perror("stat");
            continue;
        }

        // For directories, recursively calculate disk usage
        if (S_ISDIR(stats.st_mode)) {
            calculateDiskUsage(path, totalSize);
        }

        // Add the size of the current file or directory to total size
        *totalSize += stats.st_size;
    }

    closedir(dp);
}

void printDiskUsage(const char *path, long long size) {
    printf("Total disk usage for directory '%s': %lld bytes\n", path, size);
    printf("Equivalent to: %.2f Megabytes\n", size / (1024.0 * 1024.0));
    printf("Equivalent to: %.2f Gigabytes\n", size / (1024.0 * 1024.0 * 1024.0));
}