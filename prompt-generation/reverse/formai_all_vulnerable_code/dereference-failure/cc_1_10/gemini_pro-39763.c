//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// Custom data structure to store directory and file information
typedef struct {
    char *path;
    long size;
} FileInfo;

// Comparator function for sorting files by size
int compare_files(const void *a, const void *b) {
    const FileInfo *fa = a;
    const FileInfo *fb = b;
    return fb->size - fa->size;
}

// Recursive function to traverse a directory and calculate disk space usage
long calculate_disk_usage(const char *path) {
    long total_size = 0;

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Error opening directory");
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 1);
        sprintf(full_path, "%s/%s", path, entry->d_name);

        struct stat file_info;
        if (lstat(full_path, &file_info) == 0) {
            if (S_ISREG(file_info.st_mode)) {
                // Add the size of regular files to the total size
                total_size += file_info.st_size;
            } else if (S_ISDIR(file_info.st_mode)) {
                // Recursively calculate the disk usage for subdirectories
                total_size += calculate_disk_usage(full_path);
            }
        }
        free(full_path);
    }

    closedir(dir);
    return total_size;
}

// Main function
int main(void) {
    // Get the root directory path from the user
    char *root_path = getenv("HOME");
    if (root_path == NULL) {
        perror("Error getting root directory path");
        return -1;
    }

    // Initialize an array of FileInfo structures
    FileInfo files[1000];
    int num_files = 0;

    // Recursively traverse the root directory and calculate the disk usage for each file and directory
    long total_size = calculate_disk_usage(root_path);

    // Populate the FileInfo array with the collected data
    DIR *dir = opendir(root_path);
    if (dir == NULL) {
        perror("Error opening root directory");
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *full_path = malloc(strlen(root_path) + strlen(entry->d_name) + 1);
        sprintf(full_path, "%s/%s", root_path, entry->d_name);

        struct stat file_info;
        if (lstat(full_path, &file_info) == 0) {
            if (S_ISREG(file_info.st_mode)) {
                files[num_files].path = full_path;
                files[num_files].size = file_info.st_size;
                num_files++;
            }
        }
        free(full_path);
    }

    closedir(dir);

    // Sort the files by size in descending order
    qsort(files, num_files, sizeof(FileInfo), compare_files);

    // Print the disk usage information for the top 10 files
    printf("Top 10 disk usage:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s (%ld bytes)\n", i + 1, files[i].path, files[i].size);
    }

    // Calculate the percentage of disk space used
    double disk_usage_percent = (double)total_size / (1024 * 1024 * 1024) * 100;

    // Print the total disk usage and percentage
    printf("\nTotal disk usage: %.2f GB (%.2f%%)\n", (double)total_size / (1024 * 1024 * 1024), disk_usage_percent);

    return 0;
}