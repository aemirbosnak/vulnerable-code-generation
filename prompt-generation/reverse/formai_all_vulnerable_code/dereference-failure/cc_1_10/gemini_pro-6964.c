//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

// Data structure to store the disk usage information
typedef struct {
    char *path;
    long long size;
} DiskUsage;

// Function to compare two DiskUsage structures by size
int compareDiskUsage(const void *a, const void *b) {
    const DiskUsage *da = (const DiskUsage *)a;
    const DiskUsage *db = (const DiskUsage *)b;
    return db->size - da->size;
}

// Function to analyze the disk space usage of a directory
long long analyzeDiskUsage(char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    long long size = 0;

    // Open the directory
    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    // Iterate over the directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the full path of the entry
        char *fullPath = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(fullPath, "%s/%s", path, entry->d_name);

        // Get the stat of the entry
        if (lstat(fullPath, &statbuf) == -1) {
            perror("lstat");
            free(fullPath);
            closedir(dir);
            return -1;
        }

        // Add the size of the entry to the total size
        if (S_ISDIR(statbuf.st_mode)) {
            // Recursively analyze the subdirectory
            size += analyzeDiskUsage(fullPath);
        } else {
            size += statbuf.st_size;
        }

        // Free the allocated memory
        free(fullPath);
    }

    // Close the directory
    closedir(dir);

    return size;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has specified a directory
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Analyze the disk space usage of the directory
    long long size = analyzeDiskUsage(argv[1]);
    if (size == -1) {
        return EXIT_FAILURE;
    }

    // Convert the size to human-readable format
    char *sizeStr = malloc(64);
    if (size < 1024) {
        sprintf(sizeStr, "%lld bytes", size);
    } else if (size < 1024 * 1024) {
        sprintf(sizeStr, "%.2f KB", (double)size / 1024);
    } else if (size < 1024 * 1024 * 1024) {
        sprintf(sizeStr, "%.2f MB", (double)size / (1024 * 1024));
    } else {
        sprintf(sizeStr, "%.2f GB", (double)size / (1024 * 1024 * 1024));
    }

    // Print the disk space usage
    printf("Disk space usage of %s: %s\n", argv[1], sizeStr);

    // Free the allocated memory
    free(sizeStr);

    return EXIT_SUCCESS;
}