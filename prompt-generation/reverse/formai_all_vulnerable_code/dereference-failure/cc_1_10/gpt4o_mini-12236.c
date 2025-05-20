//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024

// Function to calculate the total size of a directory
long long calculate_directory_size(const char *path) {
    long long total_size = 0;
    struct dirent *entry;
    struct stat file_stat;
    char full_path[MAX_PATH];

    DIR *dp = opendir(path);
    if (dp == NULL) {
        perror("opendir");
        return -1; // return an error if can't open directory
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        if (stat(full_path, &file_stat) == 0) {
            if (S_ISDIR(file_stat.st_mode)) {
                // If it's a directory, recurse into it and add its size
                long long dir_size = calculate_directory_size(full_path);
                if (dir_size >= 0) {
                    total_size += dir_size;
                }
            } else {
                // If it's a file, add its size
                total_size += file_stat.st_size;
            }
        }
    }
    closedir(dp);
    return total_size;
}

// Function to display the size in a readable format
void display_size(long long size) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    double size_in_units = (double)size;
    int unit_index = 0;

    while (size_in_units >= 1024 && unit_index < 4) {
        size_in_units /= 1024;
        unit_index++;
    }
    
    printf("Total Size: %.2f %s\n", size_in_units, units[unit_index]);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1; // Exit if no directory path is provided
    }

    const char *directory_path = argv[1];
    long long total_size = calculate_directory_size(directory_path);

    if (total_size >= 0) {
        display_size(total_size);
    } else {
        printf("Could not calculate size for the directory: %s\n", directory_path);
    }

    return 0; // successfully done
}