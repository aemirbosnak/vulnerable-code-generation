//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH_LENGTH 1024

// Function to get the total size of files in a directory
long get_directory_size(const char *path) {
    struct dirent *entry;
    struct stat file_stats;
    DIR *dp;
    long total_size = 0;

    // Open the directory
    dp = opendir(path);
    if (dp == NULL) {
        perror("opendir failed");
        return -1;
    }

    // Read entries in the directory
    while ((entry = readdir(dp)) != NULL) {
        // Ignore the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Create the full path for the file
        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        // Get file status
        if (stat(full_path, &file_stats) == -1) {
            perror("stat failed");
            continue;
        }

        // Check if it is a regular file and add to total size
        if (S_ISREG(file_stats.st_mode)) {
            total_size += file_stats.st_size;
        }
    }

    closedir(dp);
    return total_size;
}

// Function to count files in a directory
int count_files(const char *path) {
    struct dirent *entry;
    DIR *dp;
    int count = 0;

    // Open the directory
    dp = opendir(path);
    if (dp == NULL) {
        perror("opendir failed");
        return -1;
    }

    // Read entries in the directory
    while ((entry = readdir(dp)) != NULL) {
        // Ignore the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        count++;
    }

    closedir(dp);
    return count;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_path = argv[1];
    
    printf("Analyzing directory: %s\n", directory_path);

    // Get the total size of files in the directory
    long total_size = get_directory_size(directory_path);
    if (total_size == -1) {
        return EXIT_FAILURE;
    }

    // Count the number of files in the directory
    int file_count = count_files(directory_path);
    if (file_count == -1) {
        return EXIT_FAILURE;
    }

    // Print the results
    printf("Total number of files: %d\n", file_count);
    printf("Total size of files: %ld bytes\n", total_size);

    return EXIT_SUCCESS;
}