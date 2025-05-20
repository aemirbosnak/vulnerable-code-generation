//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function declarations
long long get_directory_size(char *);
void print_bytes(long long);

int main(int argc, char *argv[]) {
    // If no directory specified, use current directory
    char *directory = ".";
    if (argc == 2) {
        directory = argv[1];
    }

    // Get directory size
    long long size = get_directory_size(directory);

    // Print directory size
    printf("Size of directory \"%s\": ", directory);
    print_bytes(size);

    return 0;
}

// Function to get size of directory
long long get_directory_size(char *directory) {
    long long total_size = 0;

    // Open directory
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        // Error opening directory
        printf("Error opening directory \"%s\".\n", directory);
        exit(1);
    }

    // Loop through directory contents
    struct dirent *entry;
    char path[PATH_MAX];
    while ((entry = readdir(dir)) != NULL) {
        sprintf(path, "%s/%s", directory, entry->d_name);

        // Get information about file/directory
        struct stat info;
        int stat_result = stat(path, &info);
        if (stat_result != 0) {
            // Error getting file/directory information
            printf("Error getting information about \"%s\".\n", path);
            exit(1);
        }

        // Check if it's a directory
        if (S_ISDIR(info.st_mode)) {
            // Check if it's the current or parent directory
            if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0) {
                continue;
            }
            // Recursively get size of subdirectory
            total_size += get_directory_size(path);
        }
        // Otherwise, add file size to total
        else {
            total_size += info.st_size;
        }
    }

    // Close directory
    closedir(dir);

    return total_size;
}

// Function to print bytes in human-readable format
void print_bytes(long long bytes) {
    if (bytes < 1024) {
        // Less than 1 KB
        printf("%lld bytes\n", bytes);
    } else if (bytes < 1024 * 1024) {
        // Less than 1 MB
        printf("%.2f KB\n", bytes / 1024.0);
    } else if (bytes < 1024 * 1024 * 1024) {
        // Less than 1 GB
        printf("%.2f MB\n", bytes / (1024.0 * 1024));
    } else {
        // Greater than or equal to 1 GB
        printf("%.2f GB\n", bytes / (1024.0 * 1024 * 1024));
    }
}