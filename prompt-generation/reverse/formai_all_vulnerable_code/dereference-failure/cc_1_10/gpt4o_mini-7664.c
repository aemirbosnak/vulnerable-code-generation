//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024

void analyze_directory(const char *path, int *total_files, long long *total_size) {
    DIR *directory;
    struct dirent *entry;
    struct stat file_stat;
    char full_path[MAX_PATH];

    directory = opendir(path);
    if (!directory) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        // Ignoring '.' and '..' entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        if (stat(full_path, &file_stat) == 0) {
            if (S_ISREG(file_stat.st_mode)) { // Regular file
                (*total_files)++;
                *total_size += file_stat.st_size;
            } else if (S_ISDIR(file_stat.st_mode)) { // Directory
                analyze_directory(full_path, total_files, total_size); // Recursive call
            }
        } else {
            perror("Could not get file statistics");
        }
    }
    closedir(directory);
}

int main(int argc, char *argv[]) {
    // Start of our introspection journey
    char *path;
    if (argc > 1) {
        path = argv[1];
    } else {
        path = "."; // Default to current directory
    }

    printf("Analyzing disk space for directory: %s\n", path);
    
    int total_files = 0;
    long long total_size = 0;
    
    analyze_directory(path, &total_files, &total_size);

    // Summary of our exploration
    printf("Total files: %d\n", total_files);
    printf("Total size: %lld bytes\n", total_size);

    // Additional informational display
    if (total_files > 0) {
        printf("Average file size: %.2f bytes\n", (double)total_size / total_files);
    } else {
        printf("No files found in the specified directory.\n");
    }

    return 0;
}