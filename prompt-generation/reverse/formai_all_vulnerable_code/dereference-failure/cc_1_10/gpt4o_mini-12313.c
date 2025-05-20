//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define PATH_MAX 1024

// Function to get the total size of files in a specific directory
long get_directory_size(const char *dir_path) {
    long total_size = 0;
    struct stat file_stat;
    DIR *dir;
    struct dirent *entry;

    // Open the directory
    dir = opendir(dir_path);
    if (!dir) {
        perror("Unable to open directory");
        return -1;
    }

    // Iterate through directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current (.) and parent (..) directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char file_path[PATH_MAX];
        snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);

        // Get the file status
        if (stat(file_path, &file_stat) == -1) {
            perror("Unable to get file statistics");
            continue;
        }

        // If the entry is a directory, recursively get its size
        if (S_ISDIR(file_stat.st_mode)) {
            long sub_dir_size = get_directory_size(file_path);
            if (sub_dir_size != -1) {
                total_size += sub_dir_size;
            }
        } else {
            // If it's a file, add its size to the total
            total_size += file_stat.st_size;
        }
    }

    closedir(dir);
    return total_size;
}

// Function to print out sizes of each subdirectory
void analyze_disk_space(const char *path) {
    struct stat file_stat;

    if (stat(path, &file_stat) == -1) {
        perror("Unable to get path statistics");
        return;
    }

    printf("Analyzing directory: %s\n", path);
    long total_size = get_directory_size(path);

    if (total_size >= 0) {
        printf("Total size of files in '%s': %ld bytes\n", path, total_size);
    } else {
        printf("Error calculating size for directory '%s'\n", path);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if a path is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Analyze disk space for the provided directory
    analyze_disk_space(argv[1]);

    return EXIT_SUCCESS;
}