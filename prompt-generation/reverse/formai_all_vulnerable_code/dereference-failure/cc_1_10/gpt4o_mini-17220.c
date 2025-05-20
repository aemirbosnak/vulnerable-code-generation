//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024

void analyze_directory(const char *path, long long int *total_size, int *file_count, int *dir_count) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat file_stat;
    char full_path[MAX_PATH];

    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Generate the full path
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        // Get file stats
        if (stat(full_path, &file_stat) == -1) {
            perror("Failed to get file stats");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            // If it's a directory, increment the directory count and analyze it recursively
            (*dir_count)++;
            analyze_directory(full_path, total_size, file_count, dir_count);
        } else {
            // If it's a file, increment the file count and add to total size
            (*file_count)++;
            *total_size += file_stat.st_size;
        }
    }

    closedir(dir);
}

void print_summary(const char *path) {
    long long int total_size = 0;
    int file_count = 0;
    int dir_count = 0;

    analyze_directory(path, &total_size, &file_count, &dir_count);

    printf("Disk Space Analysis for '%s':\n", path);
    printf("Total Files: %d\n", file_count);
    printf("Total Directories: %d\n", dir_count);
    printf("Total Size: %.2f MB\n", total_size / (1024.0 * 1024.0));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    print_summary(argv[1]);

    return EXIT_SUCCESS;
}