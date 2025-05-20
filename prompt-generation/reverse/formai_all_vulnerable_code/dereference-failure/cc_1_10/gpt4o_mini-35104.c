//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

void analyze_directory(const char *dir_path, long *total_size, int *file_count, int *dir_count) {
    DIR *directory;
    struct dirent *entry;
    struct stat file_info;
    
    // Try opening the directory
    if ((directory = opendir(dir_path)) == NULL) {
        perror("Failed to open directory");
        return;
    }

    // Loop through all entries in the directory
    while ((entry = readdir(directory)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path for the entry
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        
        // Get file statistics
        if (stat(full_path, &file_info) != 0) {
            perror("Failed to get file stats");
            continue;
        }

        // Check if entry is a file or directory
        if (S_ISDIR(file_info.st_mode)) {
            // It is a directory, recurse into it
            (*dir_count)++;
            analyze_directory(full_path, total_size, file_count, dir_count);
        } else {
            // It is a file, count it and add its size
            (*file_count)++;
            *total_size += file_info.st_size;
        }
    }

    // Close the directory
    closedir(directory);
}

void print_usage(const char *prog_name) {
    printf("Usage: %s <directory>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    long total_size = 0;
    int file_count = 0;
    int dir_count = 0;

    // Start analyzing the given directory
    analyze_directory(argv[1], &total_size, &file_count, &dir_count);

    // Display the summary of the analysis
    printf("Directory: %s\n", argv[1]);
    printf("Total files: %d\n", file_count);
    printf("Total directories: %d\n", dir_count);
    printf("Total size: %ld bytes\n", total_size);

    return EXIT_SUCCESS;
}