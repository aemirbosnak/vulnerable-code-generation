//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// Defining the maximum path length
#define MAX_PATH 1024

// Function to calculate total size of a directory
long long int get_dir_size(const char *path) {
    DIR *dir = opendir(path);
    long long int size = 0;

    if (dir == NULL) {
        perror("Unable to read directory");
        return -1;
    }

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        char file_path[MAX_PATH];

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            // Recursive call to get_dir_size function
            sprintf(file_path, "%s/%s", path, entry->d_name);
            long long int subdir_size = get_dir_size(file_path);

            if (subdir_size == -1) {
                return -1;
            }

            size += subdir_size;
        } else {
            sprintf(file_path, "%s/%s", path, entry->d_name);
            struct stat file_stats;

            if (stat(file_path, &file_stats) == -1) {
                perror("Unable to get file stats");
                return -1;
            }

            size += file_stats.st_size;
        }
    }

    closedir(dir);
    return size;
}

// Drive space analyzer function
void analyze_drive_space(const char *drive) {
    long long int total_size = get_dir_size(drive);

    if (total_size == -1) {
        return;
    }

    printf("Drive %s:\n\n", drive);
    printf("%-20s%-20s%-20s\n", "Folder / File", "Size (Bytes)", "Size (KB)");

    struct dirent *entry;
    DIR *dir = opendir(drive);

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR || entry->d_type == DT_REG) {
            char file_path[MAX_PATH];
            sprintf(file_path, "%s/%s", drive, entry->d_name);
            struct stat file_stats;

            if (stat(file_path, &file_stats) == -1) {
                perror("Unable to get file stats");
                continue;
            }

            long long int size = file_stats.st_size;

            if (entry->d_type == DT_DIR) {
                size = get_dir_size(file_path);
            }

            printf("%-20s%-20lld%-20lld\n", entry->d_name, size, size / 1024);
        }
    }

    closedir(dir);
    printf("\n%-20s%-20lld%-20lld\n", "Total", total_size, total_size / 1024);
}

int main() {
    analyze_drive_space("C:/");
    return 0;
}