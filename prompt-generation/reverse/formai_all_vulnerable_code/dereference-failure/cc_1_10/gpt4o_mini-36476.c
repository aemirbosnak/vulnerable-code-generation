//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

#define MAX_PATH 4096

// Function prototypes
void analyzeDirectory(const char *dirPath, long long *totalSize);
void printResults(long long totalSize, const char *dirPath);

// Awesome Main Function!
int main(int argc, char *argv[]) {
    // Welcome Message
    printf("===================================\n");
    printf("  Welcome to Disk Space Analyzer!  \n");
    printf("===================================\n");
    
    // Check for directory argument, if not use current directory
    const char *path = (argc > 1) ? argv[1] : ".";
    long long totalSize = 0;

    printf("Analyzing Directory: %s\n", path);
    analyzeDirectory(path, &totalSize);
    printResults(totalSize, path);

    return 0;
}

// Analyze directory and its contents
void analyzeDirectory(const char *dirPath, long long *totalSize) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;

    // Open the directory
    dir = opendir(dirPath);
    if (!dir) {
        fprintf(stderr, "Failed to open directory: %s\n", strerror(errno));
        return;
    }
    
    // Reading entries
    while ((entry = readdir(dir)) != NULL) {
        char fullPath[MAX_PATH];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);

        // Ignore "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get file statistics
        if (stat(fullPath, &fileStat) < 0) {
            fprintf(stderr, "Could not get stats for %s: %s\n", fullPath, strerror(errno));
            continue;
        }

        // Check if it's a directory or a file
        if (S_ISDIR(fileStat.st_mode)) {
            // Recursively analyze if it’s a directory
            analyzeDirectory(fullPath, totalSize);
        } else if (S_ISREG(fileStat.st_mode)) {
            // Accumulate size of regular files
            *totalSize += fileStat.st_size;
        }
    }

    // Close the directory stream
    closedir(dir);
}

// Print the results
void printResults(long long totalSize, const char *dirPath) {
    printf("===================================\n");
    printf("Total size of files in: %s\n", dirPath);
    printf("Total Size (in bytes): %lld\n", totalSize);
    printf("Total Size (in MB): %.2f MB\n", totalSize / (1024.0 * 1024.0));
    printf("===================================\n");
}