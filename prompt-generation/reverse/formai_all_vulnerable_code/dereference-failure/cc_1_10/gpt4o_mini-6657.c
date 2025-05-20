//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function prototype declarations
void analyze_directory(const char *dir_path, long long *total_size, long long *file_count);
void print_human_readable_size(long long size);
void print_analysis(const char *dir_path, long long total_size, long long file_count);

int main(int argc, char *argv[]) {
    // Check if directory path is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long long total_size = 0;
    long long file_count = 0;

    // Start analyzing the given directory
    analyze_directory(argv[1], &total_size, &file_count);

    // Print the result of analysis
    print_analysis(argv[1], total_size, file_count);

    return EXIT_SUCCESS;
}

void analyze_directory(const char *dir_path, long long *total_size, long long *file_count) {
    struct dirent *entry;
    struct stat statbuf;
    DIR *dir = opendir(dir_path);

    // Check if the directory can be opened
    if (dir == NULL) {
        perror("Failed to open directory");
        return;
    }

    // Read the directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path of the file/directory
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        // Get information about the file/directory
        if (stat(full_path, &statbuf) == -1) {
            perror("Failed to get file status");
            continue;
        }

        // If it's a regular file, update total size and file count
        if (S_ISREG(statbuf.st_mode)) {
            *total_size += statbuf.st_size;
            (*file_count)++;
        }
        // If it's a directory, recursively analyze it
        else if (S_ISDIR(statbuf.st_mode)) {
            analyze_directory(full_path, total_size, file_count);
        }
    }

    // Close the directory
    closedir(dir);
}

void print_human_readable_size(long long size) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int unit_index = 0;
    double human_size = size;

    while (human_size >= 1024 && unit_index < (sizeof(units) / sizeof(units[0])) - 1) {
        human_size /= 1024;
        unit_index++;
    }

    printf("%.2f %s\n", human_size, units[unit_index]);
}

void print_analysis(const char *dir_path, long long total_size, long long file_count) {
    printf("Directory: %s\n", dir_path);
    printf("Total files: %lld\n", file_count);
    printf("Total size: ");
    print_human_readable_size(total_size);
}