//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

// Global variables to store the total size and number of files
long long total_size = 0;
int num_files = 0;

// Recursive function to traverse the directory and calculate the total size
void analyze_directory(const char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    // Iterate over the directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the full path to the entry
        char full_path[256];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        // Get the file stats
        struct stat stats;
        if (stat(full_path, &stats) != 0) {
            perror("Error getting file stats");
            continue;
        }

        // If the entry is a directory, recurse into it
        if (S_ISDIR(stats.st_mode)) {
            analyze_directory(full_path);
        } else {
            // Increment the number of files and add the file size to the total
            num_files++;
            total_size += stats.st_size;
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    // Check if a path was provided
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    // Analyze the specified directory
    analyze_directory(argv[1]);

    // Print the results
    printf("Total size: %lld bytes\n", total_size);
    printf("Number of files: %d\n", num_files);

    return 0;
}