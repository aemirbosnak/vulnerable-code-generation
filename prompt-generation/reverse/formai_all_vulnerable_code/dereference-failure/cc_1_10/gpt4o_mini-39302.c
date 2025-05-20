//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Recursive function to calculate total file size
long getTotalFileSize(const char *dirPath) {
    struct dirent *entry;
    struct stat fileStat;
    DIR *dir = opendir(dirPath);
    long totalSize = 0;

    if (dir == NULL) {
        perror("Unable to open directory");
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char fullPath[512];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);

        // Get file stats
        if (stat(fullPath, &fileStat) == -1) {
            perror("Unable to get file stats");
            continue;
        }

        // If it's a directory, recurse into it
        if (S_ISDIR(fileStat.st_mode)) {
            totalSize += getTotalFileSize(fullPath);
        } else {
            // If it's a file, add its size
            totalSize += fileStat.st_size;
        }
    }

    closedir(dir);
    return totalSize;
}

// Main function to prompt user for directory and calculate size
int main(int argc, char *argv[]) {
    const char *directoryPath;

    // Check if a directory path was provided
    if (argc == 2) {
        directoryPath = argv[1];
    } else {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Calculate total file size
    long totalSize = getTotalFileSize(directoryPath);
    printf("Total size of files in '%s': %ld bytes\n", directoryPath, totalSize);

    return EXIT_SUCCESS;
}