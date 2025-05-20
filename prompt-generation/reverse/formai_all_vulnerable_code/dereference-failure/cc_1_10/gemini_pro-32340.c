//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LEN 256

// Recursive function to calculate the size of a directory and all its subdirectories
long long calculate_directory_size(const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    long long total_size = 0;

    // Open the directory
    dir = opendir(path);
    if (dir == NULL) {
        perror(path);
        return -1;
    }

    // Iterate over the entries in the directory
    while ((entry = readdir(dir)) != NULL) {
        char full_path[MAX_PATH_LEN];

        // Skip current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the full path of the entry
        snprintf(full_path, MAX_PATH_LEN, "%s/%s", path, entry->d_name);

        // Get the file statistics
        if (stat(full_path, &statbuf) == -1) {
            perror(full_path);
            continue;
        }

        // If the entry is a directory, recursively calculate its size
        if (S_ISDIR(statbuf.st_mode)) {
            total_size += calculate_directory_size(full_path);
        } else {
            total_size += statbuf.st_size;
        }
    }

    // Close the directory
    closedir(dir);

    return total_size;
}

// Main function
int main(int argc, char **argv) {
    // Check if a path was specified
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Calculate the size of the specified path
    long long size = calculate_directory_size(argv[1]);

    // Print the size of the path
    printf("Size of '%s': %lld bytes\n", argv[1], size);

    return EXIT_SUCCESS;
}