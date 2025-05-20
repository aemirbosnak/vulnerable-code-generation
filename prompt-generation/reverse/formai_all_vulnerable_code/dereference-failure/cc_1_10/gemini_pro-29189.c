//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <limits.h>

// Function to get the size of a file or directory
unsigned long long get_file_size(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        perror("stat");
        return 0;
    }
    return statbuf.st_size;
}

// Function to recursively traverse a directory and calculate its size
unsigned long long get_dir_size(const char *path) {
    unsigned long long size = 0;
    DIR *dir;
    struct dirent *entry;

    // Open the directory
    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return 0;
    }

    // Iterate over the directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the full path to the entry
        char fullpath[PATH_MAX];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        // Get the size of the entry
        unsigned long long entry_size = get_file_size(fullpath);
        if (entry_size == 0) {
            continue;
        }

        // Add the size of the entry to the total size
        size += entry_size;
    }

    // Close the directory
    closedir(dir);

    return size;
}

// Main function
int main(int argc, char **argv) {
    // Check if a path was provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the size of the path
    unsigned long long size = get_dir_size(argv[1]);
    if (size == 0) {
        fprintf(stderr, "Error getting the size of %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Print the size of the path
    printf("The size of %s is %llu bytes\n", argv[1], size);

    return EXIT_SUCCESS;
}