//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH 1024

// Function prototypes
void analyze_space(const char *path, long long *total_size, long long *file_count, long long *dir_count);
void print_human_readable_size(long long size);
void display_summary(const char *path, long long total_size, long long file_count, long long dir_count);

int main(int argc, char *argv[]) {
    // Check if a directory path is specified
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    long long total_size = 0;
    long long file_count = 0;
    long long dir_count = 0;

    // Analyze the specified directory
    analyze_space(argv[1], &total_size, &file_count, &dir_count);
    
    // Display the summary of disk usage
    display_summary(argv[1], total_size, file_count, dir_count);
    
    return 0;
}

void analyze_space(const char *path, long long *total_size, long long *file_count, long long *dir_count) {
    struct dirent *entry;
    struct stat file_info;
    DIR *dp;

    // Open the directory
    if ((dp = opendir(path)) == NULL) {
        perror("opendir");
        return;
    }

    // Traverse through the directory entries
    while ((entry = readdir(dp)) != NULL) {
        // Ignore the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        // Get file status
        if (stat(full_path, &file_info) == -1) {
            perror("stat");
            continue;
        }

        // Check if it is a directory or a file
        if (S_ISDIR(file_info.st_mode)) {
            (*dir_count)++;
            // Recursively analyze the subdirectory
            analyze_space(full_path, total_size, file_count, dir_count);
        } else if (S_ISREG(file_info.st_mode)) {
            (*file_count)++;
            // Add file size to total size
            *total_size += file_info.st_size;
        }
    }

    // Close the directory stream
    closedir(dp);
}

void print_human_readable_size(long long size) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int unit_index = 0;

    double display_size = size;

    while (display_size >= 1024 && unit_index < 4) {
        display_size /= 1024;
        unit_index++;
    }

    printf("%.2f %s\n", display_size, units[unit_index]);
}

void display_summary(const char *path, long long total_size, long long file_count, long long dir_count) {
    printf("Summary for directory: %s\n", path);
    printf("Number of files: %lld\n", file_count);
    printf("Number of directories: %lld\n", dir_count);
    printf("Total disk usage: ");
    print_human_readable_size(total_size);
}